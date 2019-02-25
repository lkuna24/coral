

#include "ElectronDiff.h"

registerMooseObject("MooseApp", ElectronDiff);

template<>
InputParameters validParams<ElectronDiff>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("Calculates a residual contribution due to nabla squared Phi = 0");
  params.addRequiredCoupledVar("n", "The variable n or p");
  params.addParam<Real>("len_scale", 1.0, "the length scale of the unit");
  return params;
}

ElectronDiff::ElectronDiff(const InputParameters & parameters)
  :Kernel(parameters),
    _n_var(coupled("n")),
    _n(coupledValue("n")),
   _len_scale(getParam<Real>("len_scale"))
{
}

Real
ElectronDiff::computeQpResidual()
{
  Real Relec = 0.0;
  Relec += _n[_qp] * _grad_u[_qp] * _grad_test[_i][_qp] * _len_scale;
  ///  Moose::out << "\n R_elec-"; std::cout << " = " << Relec;
  return Relec;
}

Real
ElectronDiff::computeQpJacobian()
{
  // return _grad_phi[_j][_qp] * _grad_test[_i][_qp] * _len_scale;
   return 0.0;
}
