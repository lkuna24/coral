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

private:
  const Real _len_scale;

};
#endif
