#include "FragmentBC.h"

registerMooseObject("fragmentApp", FragmentBC);

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
