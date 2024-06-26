#include "CmdBeginDraw.h"
#include "PrimitiveManager.h"

bool CmdBeginDraw::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	Topology topology;
	if (params[0] == "point")
	{
		topology = Topology::Point;
	}
	else if (params[0] == "line")
	{
		topology = Topology::Line;
	}
	else if (params[0] == "triangle")
	{
		topology = Topology::Trianlge;
	}
	else
	{
		return false;
	}

	bool applyTransform = false;
	if (params.size() > 1)
	{
		applyTransform = params[1] == "true";
	}

	return PrimitiveManager::Get()->BeginDraw(topology, applyTransform);
}