//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "coralTestApp.h"
#include "coralApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<coralTestApp>()
{
  InputParameters params = validParams<coralApp>();
  return params;
}

coralTestApp::coralTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  coralApp::registerObjectDepends(_factory);
  coralApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  coralApp::associateSyntaxDepends(_syntax, _action_factory);
  coralApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  coralApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    coralTestApp::registerObjects(_factory);
    coralTestApp::associateSyntax(_syntax, _action_factory);
    coralTestApp::registerExecFlags(_factory);
  }
}

coralTestApp::~coralTestApp() {}

void
coralTestApp::registerApps()
{
  registerApp(coralApp);
  registerApp(coralTestApp);
}

void
coralTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
coralTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
coralTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
coralTestApp__registerApps()
{
  coralTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
coralTestApp__registerObjects(Factory & factory)
{
  coralTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
coralTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  coralTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
coralTestApp__registerExecFlags(Factory & factory)
{
  coralTestApp::registerExecFlags(factory);
}
