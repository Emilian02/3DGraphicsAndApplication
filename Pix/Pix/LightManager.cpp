#include "LightManager.h"

LightManager* LightManager::Get()
{
	static LightManager sInstance;
	return &sInstance;
}

void LightManager::OnNewFrame()
{
	mLight.clear();
	mAmbient = X::Colors::White;
	mDiffuse = X::Colors::White;
	mSpecular = X::Colors::White;
}

void LightManager::SetLigthingAmbient(const X::Color& color)
{
	mAmbient = color;
}

void LightManager::SetLigthingDiffuse(const X::Color& color)
{
	mDiffuse = color;
}

void LightManager::SetLigthingSpecular(const X::Color& color)
{
	mSpecular = color;
}

X::Color LightManager::ComputeLightColor(const Vector3& position, const Vector3& normal) const
{
	if (mLight.empty())
	{
		return X::Colors::White;
	}
	X::Color color;
	
	for (const auto& light : mLight)
	{
		color += light->ComputeLightColor(position, normal);
	}

	return color;
}
