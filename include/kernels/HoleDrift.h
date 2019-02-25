#ifndef HOLEDRIFT_H
#define HOLEDRIFT_H

#include "Kernel.h"

class HoleDrift;

template<>
InputParameters validParams<HoleDrift>();

class HoleDrift: public Kernel
{
public:

  HoleDrift(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

private:
  const Real _len_scale;

};
#endif
