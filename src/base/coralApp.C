#include "coralApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"



template <>
InputParameters
validParams<coralApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

coralApp::coralApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  coralApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  coralApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  coralApp::registerExecFlags(_factory);
}

coralApp::~coralApp() {}

void
coralApp::registerApps()
{
  registerApp(coralApp);
}

void
coralApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"coralApp"});
}

void
coralApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"coralApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
coralApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
coralApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
coralApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
coralApp__registerApps()
{
  coralApp::registerApps();
}

extern "C" void
coralApp__registerObjects(Factory & factory)
{
  coralApp::registerObjects(factory);
}

extern "C" void
coralApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  coralApp::associateSyntax(syntax, action_factory);
}

extern "C" void
coralApp__registerExecFlags(Factory & factory)
{
  coralApp::registerExecFlags(factory);
}
