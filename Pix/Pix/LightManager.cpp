#include "LightManager.h"
#include "LightTypes.h"
#include "MaterialManager.h"

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

void LightManager::AddDirectionLight(const Vector3& direction)
{
	auto light = std::make_unique<DirectionalLight>();
	light->SetAmbient(mAmbient);
	light->SetDiffuse(mDiffuse);
	light->SetSpecular(mSpecular);
	light->SetDirection(direction);
	mLight.emplace_back(std::move(light));
}

void LightManager::AddPointLight(const Vector3& position, float constant, float linear, float qudratic)
{
	auto light = std::make_unique<PointLight>();
	light->SetAmbient(mAmbient);
	light->SetDiffuse(mDiffuse);
	light->SetSpecular(mSpecular);
	light->SetPosition(position);
	light->SetAttenuation(constant, linear, qudratic);
	mLight.emplace_back(std::move(light));
}

X::Color LightManager::ComputeLightColor(const Vector3& position, const Vector3& normal) const
{
	X::Color color = MaterialManager::Get()->GetMaterialEmissive();
	
	for (const auto& light : mLight)
	{
		color += light->ComputeLightColor(position, normal);
	}

	return color;
}
