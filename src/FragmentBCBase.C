#include "FragmentBCBase.h"

defineLegacyParams(FragmentBCBase);

InputParameters
FragmentBCBase::validParams()
{
  return DirichletBCBase::validParams();
}

FragmentBCBase::FragmentBCBase(const InputParameters & parameters) : DirichletBCBase(parameters) {}

Real
FragmentBCBase::computeQpValue()
{
  return bcValue();
}
