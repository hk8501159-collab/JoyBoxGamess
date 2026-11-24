#pragma once

#include "Modules/ModuleManager.h"

class FJoyBoxGamessModule : public FDefaultGameModuleImpl
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
