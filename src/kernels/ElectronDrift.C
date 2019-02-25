

#include "ElectronDrift.h"

registerMooseObject("MooseApp", ElectronDrift);

template<>
InputParameters validParams<ElectronDrift>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("Calculates a residual contribution due to nabla squared Phi = 0");
  params.addParam<Real>("len_scale", 1.0, "the length scale of the unit");
  return params;
}

ElectronDrift::ElectronDrift(const InputParameters & parameters)
  :Kernel(parameters),
   _len_scale(getParam<Real>("len_scale"))
{
}

Real
ElectronDrift::computeQpResidual()
{
  Real Relec = 0.0;
  Relec +=  _grad_u[_qp] * _grad_test[_i][_qp] * _len_scale;
  ///  Moose::out << "\n R_elec-"; std::cout << " = " << Relec;
  return Relec;
}

Real
ElectronDrift::computeQpJacobian()
{
   return _grad_phi[_j][_qp] * _grad_test[_i][_qp] * _len_scale;
}
