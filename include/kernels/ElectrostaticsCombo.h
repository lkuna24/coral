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
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

private:
  const Real _permittivity;
  const Real _len_scale;
  const VariableValue & _n;
  const VariableValue & _p;
  const unsigned int _n_var;
  const unsigned int _p_var;
  Real q;
  Real kb;
  Real T;

};
#endif
