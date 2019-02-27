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
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

private:
  const unsigned int _p_var;
  const VariableValue & _p;
  const Real _len_scale;
  Real q;
  Real kb;
  Real T;

};
#endif
