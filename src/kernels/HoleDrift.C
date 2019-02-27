

#include "HoleDrift.h"

registerMooseObject("MooseApp", HoleDrift);

template<>
InputParameters validParams<HoleDrift>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("Calculates a residual contribution due to nabla squared Phi = 0");
  params.addRequiredCoupledVar("p", "The variable p");
  params.addParam<Real>("len_scale", 1.0, "the length scale of the unit");
  return params;
}

HoleDrift::HoleDrift(const InputParameters & parameters)
  :Kernel(parameters),
    _p_var(coupled("p")),
    _p(coupledValue("p")),
   _len_scale(getParam<Real>("len_scale")),
   q(1.60217662 * 1e-19),
   kb(1.38064852 * 1e-23),
   T(300)
{
}

Real
HoleDrift::computeQpResidual()
{
  // Here u refers to the potential phi
  //  It is rescaled by q/kbT where
  //  q = 1.60217662 *1e-19
  //  kb = 1.38064852 *1e-23
  //  T = 300
  Real Relec = 0.0;
  Real k = q / (kb*T);
  Relec += -_p[_qp] *k* _grad_u[_qp] * _grad_test[_i][_qp] * _len_scale;
  ///  Moose::out << "\n R_elec-"; std::cout << " = " << Relec;
  return Relec;
}

Real
HoleDrift::computeQpJacobian()
{
  Real k = q / (kb*T);
  return -_grad_phi[_j][_qp] *_p[_qp]* k* _grad_test[_i][_qp] * _len_scale;
  // return 0.0;
}

Real
HoleDrift::computeQpOffDiagJacobian(unsigned int jvar)
{
  Real k = q / (kb*T);
  if (jvar == _p_var)
    return -_grad_test[_i][_qp]* k* _phi[_j][_qp] * _grad_u[_qp] * _len_scale;
  else
    return 0.0;
}
