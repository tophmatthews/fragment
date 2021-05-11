#pragma once

#include "DirichletBCBase.h"

class FragmentBCBase;

template <>
InputParameters validParams<FragmentBCBase>();

class FragmentBCBase : public DirichletBCBase
{
public:
  static InputParameters validParams();

  FragmentBCBase(const InputParameters & parameters);

protected:
  virtual Real computeQpValue() override;
  virtual Real bcValue() = 0;
};
