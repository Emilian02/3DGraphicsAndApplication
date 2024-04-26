#pragma once

#include "Command.h"

class CmdSetClipping : public Command
{
public:
	const char* GetName() override
	{
		return "SetClipping";
	}

	const char* GetDescription() override
	{
		return
			"SetResolution(<clip>)\n"
			"\n"
			"- Sets if clipping is enable or not.\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
