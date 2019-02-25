

#include "HoleDiff.h"

registerMooseObject("MooseApp", HoleDiff);

template<>
InputParameters validParams<HoleDiff>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("Calculates a residual contribution due to nabla squared Phi = 0");
  params.addRequiredCoupledVar("p", "The variable p");
  params.addParam<Real>("len_scale", 1.0, "the length scale of the unit");
  return params;
}

HoleDiff::HoleDiff(const InputParameters & parameters)
  :Kernel(parameters),
    _p_var(coupled("p")),
    _p(coupledValue("p")),
   _len_scale(getParam<Real>("len_scale"))
{
}

Real
HoleDiff::computeQpResidual()
{
  Real Relec = 0.0;
  Relec += -_p[_qp] * _grad_u[_qp] * _grad_test[_i][_qp] * _len_scale;
  ///  Moose::out << "\n R_elec-"; std::cout << " = " << Relec;
  return Relec;
}

Real
HoleDiff::computeQpJacobian()
{
  // return _grad_phi[_j][_qp] * _grad_test[_i][_qp] * _len_scale;
   return 0.0;
}
