#ifndef ELECTRONDIFF_H
#define ELECTRONDIFF_H

#include "Kernel.h"

class ElectronDiff;

template<>
InputParameters validParams<ElectronDiff>();

class ElectronDiff: public Kernel
{
public:

  ElectronDiff(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

private:
  const unsigned int _n_var;
  const VariableValue & _n;
  const Real _len_scale;

};
#endif
