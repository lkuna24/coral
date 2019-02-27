

#include "HoleDiffusion.h"

registerMooseObject("MooseApp", HoleDiffusion);

template<>
InputParameters validParams<HoleDiffusion>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("Calculates a residual contribution due to nabla squared Phi = 0");
  params.addParam<Real>("len_scale", 1.0, "the length scale of the unit");
  return params;
}

HoleDiffusion::HoleDiffusion(const InputParameters & parameters)
  :Kernel(parameters),
   _len_scale(getParam<Real>("len_scale"))
{
}

Real
HoleDiffusion::computeQpResidual()
{
  Real Relec = 0.0;
  Relec +=  _grad_u[_qp] * _grad_test[_i][_qp] * _len_scale;
  ///  Moose::out << "\n R_elec-"; std::cout << " = " << Relec;
  return Relec;
}

Real
HoleDiffusion::computeQpJacobian()
{
   return _grad_phi[_j][_qp] * _grad_test[_i][_qp] * _len_scale;
}
