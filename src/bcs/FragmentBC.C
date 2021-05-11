#include "FragmentBC.h"

registerMooseObject("PrimaryApp", FragmentBC);

defineLegacyParams(FragmentBC);

InputParameters
FragmentBC::validParams()
{
  return PrimaryBCBase::validParams();
}

FragmentBC::FragmentBC(const InputParameters & parameters) : PrimaryBCBase(parameters) {}

Real
FragmentBC::bcValue()
{
  return 2.0;
}
