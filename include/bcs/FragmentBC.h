#pragma once

#include "PrimaryBCBase.h"

class FragmentBC;

template <>
InputParameters validParams<FragmentBC>();

class FragmentBC : public PrimaryBCBase
{
public:
  static InputParameters validParams();

  FragmentBC(const InputParameters & parameters);

protected:
  virtual Real bcValue() override;
};
