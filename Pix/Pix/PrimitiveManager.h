#pragma once

#include "Vertex.h"

enum class Topology
{
    Point,
    Line,
    Trianlge
};

enum class CullMode
{
    None,   //Don't cull anything
    Back,   //Cull back facing
    Front   //Cull front facing
};

class PrimitiveManager
{
public:
    static PrimitiveManager* Get();

    ~PrimitiveManager();

    void OnNewFrame();
    void SetCullMode(CullMode mode);

    bool BeginDraw(Topology topology, bool applyTransform = false);
    void AddVertex(const Vertex& vertex);
    bool EndDraw();

private:
    PrimitiveManager();

    std::vector<Vertex> mVertexBuffer;
    Topology mTopology = Topology::Trianlge;
    CullMode mCullMode = CullMode::None;
    bool mDrawBegin = false;
    bool mApplyTransform = false;
};