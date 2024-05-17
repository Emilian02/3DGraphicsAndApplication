#include "CmdSetCullMode.h"
#include "PrimitiveManager.h"

bool CmdSetCullMode::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	return true;
}