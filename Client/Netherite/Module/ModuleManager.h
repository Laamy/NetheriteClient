#pragma once

#include "Netherite/Module/Modules/AntiImmobile.h"
#include "Netherite/Module/Modules/CustomCursor.h"
#include "Netherite/Module/Modules/KillInsults.h"
#include "Netherite/Module/Modules/AutoClicker.h"
#include "Netherite/Module/Modules/TestModule.h"
#include "Netherite/Module/Modules/Animations.h"
#include "Netherite/Module/Modules/NoLagBack.h"
#include "Netherite/Module/Modules/FastPlace.h"
#include "Netherite/Module/Modules/ArrayList.h"
#include "Netherite/Module/Modules/Watermark.h"
#include "Netherite/Module/Modules/TargetHUD.h"
#include "Netherite/Module/Modules/ClickGUI.h"
#include "Netherite/Module/Modules/Velocity.h"
#include "Netherite/Module/Modules/Scaffold.h"
#include "Netherite/Module/Modules/LongJump.h"
#include "Netherite/Module/Modules/Killaura.h"
#include "Netherite/Module/Modules/FastStop.h"
#include "Netherite/Module/Modules/NoSwing.h"
#include "Netherite/Module/Modules/Flight.h"
#include "Netherite/Module/Modules/Sprint.h"
#include "Netherite/Module/Modules/Hitbox.h"
#include "Netherite/Module/Modules/Aimbot.h"
#include "Netherite/Module/Modules/Speed.h"
#include "Netherite/Module/Modules/Reach.h"
#include "Netherite/Module/Modules/Step.h"
#include "Netherite/Module/Modules/Derp.h"

class ModuleManager
{
public:
	std::vector<Module*> modules;
	std::map<std::string, Vector2> categories; // std::string categoryName, Vector2 categoryPosition 

	void Initialize()
	{
		// Combat
		modules.push_back(new Aimbot());
		modules.push_back(new AutoClicker());
		modules.push_back(new Killaura());
		modules.push_back(new Hitbox());
		modules.push_back(new Reach());

		// Visual
		modules.push_back(new CustomCursor());
		modules.push_back(new Animations());
		modules.push_back(new Watermark());
		modules.push_back(new ArrayList());
		modules.push_back(new TargetHUD());
		modules.push_back(new ClickGUI());

		// Movement
		modules.push_back(new Velocity());
		modules.push_back(new LongJump());
		modules.push_back(new FastStop());
		modules.push_back(new Flight());
		modules.push_back(new Sprint());
		modules.push_back(new Speed());
		modules.push_back(new Step());

		// Player
		modules.push_back(new KillInsults());
		modules.push_back(new FastPlace());
		modules.push_back(new Scaffold());
		modules.push_back(new NoSwing());

		// Exploit
		modules.push_back(new AntiImmobile());
		modules.push_back(new NoLagBack());

		// Misc
		modules.push_back(new Module("BlockReach", "Misc", "Lets you place blocks father away retard"));
		modules.push_back(new TestModule());
		modules.push_back(new Derp());

		updateCategoriesArray(); // fix up categories array

		// I'll sort them later
	}

	Module* getModuleByName(const char* str) {
		for (auto mod : modules) {
			if (mod->name.c_str() == str)
				return mod;
		}
	}

	void updateCategoriesArray() {
		for (auto mod : modules) {
			bool addCat = true;
			for (auto cat : categories) {
				auto category = cat.first;

				if (mod->category == category)
					addCat = false;
			}
			
			if (addCat) {
				categories[mod->category] = Vector2(50 + (categories.size() * 72), 50);
			}
		}

		_modules = &modules;
		_categories = &categories;
	}
};