#include "FragmentBC.h"

registerMooseObject("PrimaryApp", FragmentBC);

defineLegacyParams(FragmentBC);

InputParameters
FragmentBC::validParams()
{
  return FragmentBCBase::validParams();
}

FragmentBC::FragmentBC(const InputParameters & parameters) : FragmentBCBase(parameters) {}

Real
FragmentBC::bcValue()
{
  return 2.0;
}
