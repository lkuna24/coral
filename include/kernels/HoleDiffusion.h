#ifndef HOLEDIFFUSION_H
#define HOLEDIFFUSION_H

#include "Kernel.h"

class HoleDiffusion;

template<>
InputParameters validParams<HoleDiffusion>();

class HoleDiffusion: public Kernel
{
public:

  HoleDiffusion(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

private:
  const Real _len_scale;

};
#endif
