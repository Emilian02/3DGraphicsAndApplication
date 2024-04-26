#pragma once
#include "Command.h"

class CmdBeginDraw : public Command
{
public:
	const char* GetName() override
	{
		return "BeginDraw";
	}

	const char* GetDescription() override
	{
		return
			"BeginDraw(Topology)\n"
			"\n"
			"- BeginDraw\n."
			"- Initializes the draw\n.";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
