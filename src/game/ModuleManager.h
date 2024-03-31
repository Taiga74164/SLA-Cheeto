#pragma once
#include "Module.h"
#include <vector>
#include <memory>

#include "Singleton.h"

class ModuleManager : public Singleton<ModuleManager>
{
public:
	void RegisterModule(const std::shared_ptr<Module> module)
	{
		m_Modules.push_back(module);
	}

	void LoadAllModules() const
	{
		for (auto& module : m_Modules)
		{
			module->Load();
		}
	}

	void UpdateAllModules() const
	{
		for (auto& module : m_Modules)
		{
			module->Update();
		}
	}

private:
	friend class Singleton<ModuleManager>;
	std::vector<std::shared_ptr<Module>> m_Modules;

	ModuleManager() = default;
	~ModuleManager() = default;
};
