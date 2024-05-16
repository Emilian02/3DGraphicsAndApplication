#include "CmdPushRotationZ.h"
#include "VariableCache.h"
#include "MatrixStack.h"

bool CmdPushRotationZ::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	auto vc = VariableCache::Get();
	float rad = vc->GetFloat(params[0]) * 3.14159 / 180.f;

	MatrixStack::Get()->PushRotationZ(rad);
	return true;
}

