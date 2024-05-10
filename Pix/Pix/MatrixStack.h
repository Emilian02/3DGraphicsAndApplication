#pragma once

#include "MathHelper.h"
#include "vector"

class MatrixStack
{
public:
	static MatrixStack* Get();

	void OnNewFrawm();

	void PushTranslation(const Vector3& d);
	void PushRotationX(float radians);
	void PushRotationY(float radians);
	void PushRotationZ(float radians);
	void PushScaling(const Vector3& s);
	void PopMatrix();

	const Matrix4& GetTransform()const;

};