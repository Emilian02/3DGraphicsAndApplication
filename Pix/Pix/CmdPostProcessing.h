#pragma once
#include "Command.h"

class CmdPostProcessingBeginDraw : public Command
{
public:
	const char* GetName() override
	{
		return "PostProcessingBeginDraw";
	}

	const char* GetDescription() override
	{
		return
			"PostProcessingBeginDraw()\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdPostProcessingEndDraw : public Command
{
public:
	const char* GetName() override
	{
		return "CmdPostProcessingEndDraw";
	}

	const char* GetDescription() override
	{
		return
			"CmdPostProcessingEndDraw()\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};


class CmdPostProcessingSetEffectType: public Command
{
public:
	const char* GetName() override
	{
		return "CmdPostProcessingSetEffectType";
	}

	const char* GetDescription() override
	{
		return
			"CmdPostProcessingSetEffectType(<effectType>)\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
