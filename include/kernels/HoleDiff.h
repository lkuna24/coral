#ifndef HOLEDIFF_H
#define HOLEDIFF_H

#include "Kernel.h"

class HoleDiff;

template<>
InputParameters validParams<HoleDiff>();

class HoleDiff: public Kernel
{
public:

  HoleDiff(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

private:
  const unsigned int _p_var;
  const VariableValue & _p;
  const Real _len_scale;

};
#endif
