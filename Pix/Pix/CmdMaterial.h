#pragma once
#include "Command.h"

class CmdSetMaterialAmbient : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialAmbient";
	}

	const char* GetDescription() override
	{
		return
			"Set Ambient(r, g, b)\n"
			"-Set ambient color for Material";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetMaterialDiffuse : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialDiffuse";
	}

	const char* GetDescription() override
	{
		return
			"Set Diffuse(r, g, b)\n"
			"-Set diffuse color for Material";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetMaterialSpecular : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialSpecular";
	}

	const char* GetDescription() override
	{
		return
			"Set specular(r, g, b)\n"
			"-Set specular color for Material";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetMaterialEmissive : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialEmissive";
	}

	const char* GetDescription() override
	{
		return
			"Set emissive(r, g, b)\n"
			"-Set emissive color for Material";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetMaterialShininess : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialShininess";
	}

	const char* GetDescription() override
	{
		return
			"Set shininess(shininess)\n"
			"-Set shininess color for Material";
	}

	bool Execute(const std::vector<std::string>& params) override;
};