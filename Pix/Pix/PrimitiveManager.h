#pragma once

#include "Vertex.h"

enum class Topology
{
    Point,
    Line,
    Trianlge
};

class PrimitiveManager
{
public:
    static PrimitiveManager* Get();

    ~PrimitiveManager();

    bool BeginDraw(Topology topology, bool applyTransform = false);
    void AddVertex(const Vertex& vertex);
    bool EndDraw();

private:
    PrimitiveManager();

    std::vector<Vertex> mVertexBuffer;
    Topology mTopology = Topology::Trianlge;
    bool mDrawBegin = false;
    bool mApplyTransform = false;
};