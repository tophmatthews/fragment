#include "fragmentApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
fragmentApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

fragmentApp::fragmentApp(InputParameters parameters) : MooseApp(parameters)
{
  fragmentApp::registerAll(_factory, _action_factory, _syntax);
}

fragmentApp::~fragmentApp() {}

void
fragmentApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"fragmentApp"});
  Registry::registerActionsTo(af, {"fragmentApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
fragmentApp::registerApps()
{
  registerApp(fragmentApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
fragmentApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  fragmentApp::registerAll(f, af, s);
}
extern "C" void
fragmentApp__registerApps()
{
  fragmentApp::registerApps();
}
