#pragma once
#include "MathHelper.h"
#include <XEngine.h>

struct Vertex
{
	Vector3 pos;
	X::Color color;
};

inline static Vector3 LerpPosition(const Vector3& a, const Vector3& b, float t)
{
	Vector3 pos;
	pos.x = floorf(MathHelper::Lerp(a.x, b.x, t) + 0.5f);
	pos.y = floorf(MathHelper::Lerp(a.y, b.y, t) + 0.5f);
	pos.z = floorf(MathHelper::Lerp(a.z, b.z, t) + 0.5f);

	return pos;
}

inline static X::Color LerpColor(const X::Color& a, const X::Color& b, float t	)
{
	X::Color color;
	color.r = MathHelper::Lerp(a.x, b.x, t);
	color.g = MathHelper::Lerp(a.y, b.y, t);
	color.b = MathHelper::Lerp(a.z, b.z, t);
	color.a = MathHelper::Lerp(a.a, b.a, t);

	return color;
}

inline static Vertex LerpVertex(const Vertex& a, const Vertex& b, float t)
{
	Vertex vertex;
	vertex.pos = LerpPosition(a.pos, b.pos, t);
	vertex.color = LerpColor(a.color, b.color, t);

	return vertex;
}