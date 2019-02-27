

#include "ElectronDiffusion.h"

registerMooseObject("MooseApp", ElectronDiffusion);

template<>
InputParameters validParams<ElectronDiffusion>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("Calculates a residual contribution due to nabla squared Phi = 0");
  params.addParam<Real>("len_scale", 1.0, "the length scale of the unit");
  return params;
}

ElectronDiffusion::ElectronDiffusion(const InputParameters & parameters)
  :Kernel(parameters),
   _len_scale(getParam<Real>("len_scale"))
{
}

Real
ElectronDiffusion::computeQpResidual()
{
  // u here is n  ## Not sure how implement as n, so will leave as u ##
  // Also this is supposed to be n/N where N is the concentration relevant to the problem
  Real Relec = 0.0;
  Relec +=  _grad_u[_qp] * _grad_test[_i][_qp] * _len_scale;
  ///  Moose::out << "\n R_elec-"; std::cout << " = " << Relec;
  return Relec;
}

Real
ElectronDiffusion::computeQpJacobian()
{
   return _grad_phi[_j][_qp] * _grad_test[_i][_qp] * _len_scale;
}
