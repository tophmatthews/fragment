#pragma once

#include "FragmentBCBase.h"

class FragmentBC;

template <>
InputParameters validParams<FragmentBC>();

class FragmentBC : public FragmentBCBase
{
public:
  static InputParameters validParams();

  FragmentBC(const InputParameters & parameters);

protected:
  virtual Real bcValue() override;
};
