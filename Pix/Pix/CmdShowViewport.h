#pragma once

#include "Command.h"

class CmdShowViewport : public Command
{
public:
	const char* GetName() override
	{
		return "ShowViewport";
	}

	const char* GetDescription() override
	{
		return
			"SetResolution(<bool>)\n"
			"\n"
			"- Shows or hides viewport.\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
#pragma once
