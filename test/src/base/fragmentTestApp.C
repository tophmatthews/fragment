//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "fragmentTestApp.h"
#include "fragmentApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
fragmentTestApp::validParams()
{
  InputParameters params = fragmentApp::validParams();
  return params;
}

fragmentTestApp::fragmentTestApp(InputParameters parameters) : MooseApp(parameters)
{
  fragmentTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

fragmentTestApp::~fragmentTestApp() {}

void
fragmentTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  fragmentApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"fragmentTestApp"});
    Registry::registerActionsTo(af, {"fragmentTestApp"});
  }
}

void
fragmentTestApp::registerApps()
{
  registerApp(fragmentApp);
  registerApp(fragmentTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
fragmentTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  fragmentTestApp::registerAll(f, af, s);
}
extern "C" void
fragmentTestApp__registerApps()
{
  fragmentTestApp::registerApps();
}
