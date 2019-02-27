

#include "ElectrostaticsCombo.h"

registerMooseObject("MooseApp", ElectrostaticsCombo);

template<>
InputParameters validParams<ElectrostaticsCombo>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("Calculates a residual contribution due to nabla squared Phi = 0");
  params.addRequiredParam<Real>("permittivity", "permittivity");
  params.addParam<Real>("len_scale", 1.0, "the length scale of the unit");
  params.addRequiredCoupledVar("n", "The variable n");
  params.addRequiredCoupledVar("p", "The variable p");
  return params;
}

ElectrostaticsCombo::ElectrostaticsCombo(const InputParameters & parameters)
  :Kernel(parameters),
   _permittivity(getParam<Real>("permittivity")),
   _len_scale(getParam<Real>("len_scale")),
   _n(coupledValue("n")),
   _p(coupledValue("p")),
   _n_var(coupled("n")),
   _p_var(coupled("p")),
   q(1.60217662 * 1e-19),
   kb(1.38064852 * 1e-23),
   T(300)
{
}

Real
ElectrostaticsCombo::computeQpResidual()
{
  Real k = q / (kb*T);
  Real Relec = 0.0;
  Relec += _grad_test[_i][_qp] *k* (_permittivity * _grad_u[_qp] *  _len_scale);
  Relec += _test[_i][_qp] * (_p[_qp] - _n[_qp]);
  ///  Moose::out << "\n R_elec-"; std::cout << " = " << Relec;
  return Relec;
}

Real
ElectrostaticsCombo::computeQpJacobian()
{
  Real k = q / (kb*T);
  return _permittivity *k* _grad_phi[_j][_qp] * _grad_test[_i][_qp] * _len_scale;
}

Real
ElectrostaticsCombo::computeQpOffDiagJacobian(unsigned int jvar)
{
  if (jvar == _n_var)
    return -_test[_i][_qp]*_phi[_j][_qp];
  else if (jvar == _p_var)
    return _test[_i][_qp]*_phi[_j][_qp];
  else
    return 0.0;
}
