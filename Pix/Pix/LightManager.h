#pragma once

#include <XEngine.h>
#include "Light.h"

class LightManager
{
public:
    static LightManager* Get();

    void OnNewFrame();

    void SetLigthingAmbient(const X::Color& color);
    void SetLigthingDiffuse(const X::Color& color);
    void SetLigthingSpecular(const X::Color& color);

    X::Color ComputeLightColor(const Vector3& position, const Vector3& normal) const;

private:
    std::vector<std::unique_ptr<Light>> mLight;
    X::Color mAmbient = X::Colors::White;
    X::Color mDiffuse = X::Colors::White;
    X::Color mSpecular = X::Colors::White;
};