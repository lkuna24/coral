#ifndef ELECTRONDIFFUSION_H
#define ELECTRONDIFFUSION_H

#include "Kernel.h"

class ElectronDiffusion;

template<>
InputParameters validParams<ElectronDiffusion>();

class ElectronDiffusion: public Kernel
{
public:

  ElectronDiffusion(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

private:
  const Real _len_scale;

};
#endif
