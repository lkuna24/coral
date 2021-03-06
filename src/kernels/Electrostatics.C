

#include "Electrostatics.h"

registerMooseObject("MooseApp", Electrostatics);

template<>
InputParameters validParams<Electrostatics>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("Calculates a residual contribution due to nabla squared Phi = 0");
  params.addRequiredParam<Real>("permittivity", "permittivity");
  params.addParam<Real>("len_scale", 1.0, "the length scale of the unit");
  return params;
}

Electrostatics::Electrostatics(const InputParameters & parameters)
  :Kernel(parameters),
   _permittivity(getParam<Real>("permittivity")),
   _len_scale(getParam<Real>("len_scale"))
{
}

Real
Electrostatics::computeQpResidual()
{
  Real Relec = 0.0;
  Relec += _permittivity * _grad_u[_qp] * _grad_test[_i][_qp] * _len_scale;
  ///  Moose::out << "\n R_elec-"; std::cout << " = " << Relec;
  return Relec;
}

Real
Electrostatics::computeQpJacobian()
{
   return _permittivity * _grad_phi[_j][_qp] * _grad_test[_i][_qp] * _len_scale;
}
