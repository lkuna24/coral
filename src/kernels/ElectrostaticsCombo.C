

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
   _n_var(coupled("n")),
   _p_var(coupled("p")),
   _n(coupledValue("n")),
   _p(coupledValue("p"))
{
}

Real
ElectrostaticsCombo::computeQpResidual()
{
  Real Relec = 0.0;
  Relec += _grad_test[_i][_qp] * (_permittivity * _grad_u[_qp] *  _len_scale);
  Relec += _test[_i][_qp] * (_p[_qp] - _n[_qp]);
  ///  Moose::out << "\n R_elec-"; std::cout << " = " << Relec;
  return Relec;
}

Real
ElectrostaticsCombo::computeQpJacobian()
{
   // return _permittivity * _grad_phi[_j][_qp] * _grad_test[_i][_qp] * _len_scale;
   return 0.0;
}
