#ifndef ELECTROSTATICSCOMBO_H
#define ELECTROSTATICSCOMBO_H

#include "Kernel.h"

class ElectrostaticsCombo;

template<>
InputParameters validParams<ElectrostaticsCombo>();

class ElectrostaticsCombo: public Kernel
{
public:

  ElectrostaticsCombo(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

private:
  const Real _permittivity;
  const Real _len_scale;
  const unsigned int _n_var;
  const unsigned int _p_var;
  const VariableValue & _n;
  const VariableValue & _p;

};
#endif
