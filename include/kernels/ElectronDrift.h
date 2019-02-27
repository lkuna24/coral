#ifndef ELECTRONDRIFT_H
#define ELECTRONDRIFT_H

#include "Kernel.h"

class ElectronDrift;

template<>
InputParameters validParams<ElectronDrift>();

class ElectronDrift: public Kernel
{
public:

  ElectronDrift(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

private:
  const unsigned int _n_var;
  const VariableValue & _n;
  const Real _len_scale;
  Real q;
  Real kb;
  Real T;

};
#endif
