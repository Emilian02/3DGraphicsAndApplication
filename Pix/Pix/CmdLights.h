#pragma once
#include "Command.h"

class CmdSetLightAmbient : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightAmbient";
	}

	const char* GetDescription() override
	{
		return
			"Set Ambient(r, g, b)\n"
			"-Set ambient color for light";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetLightDiffuse : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightDiffuse";
	}

	const char* GetDescription() override
	{
		return
			"Set Diffuse(r, g, b)\n"
			"-Set diffuse color for light";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetLightSpecular : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightSpecular";
	}

	const char* GetDescription() override
	{
		return
			"Set Specular(r, g, b)\n"
			"-Set specular color for light";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdAddDirectionalLight: public Command
{
public:
	const char* GetName() override
	{
		return "AddDirectionalLight";
	}

	const char* GetDescription() override
	{
		return
			"AddDirectionalLight(x, y, z)\n"
			"-Set directional for manager";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdAddPointLight: public Command
{
public:
	const char* GetName() override
	{
		return "AddPointLight";
	}

	const char* GetDescription() override
	{
		return
			"AddPointLight(x, y, z, <constant>, <linear>, <quadratic>)\n"
			"-Adds point light to manages";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdAddSpotLight: public Command
{
public:
	const char* GetName() override
	{
		return "AddSpotLight";
	}

	const char* GetDescription() override
	{
		return
			"AddSpotLight(posX, posY, posZ, dirX, dirY, dirZ, <constant>, <linear>, <quadratic>)\n"
			"-Adds spot light to manages";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
