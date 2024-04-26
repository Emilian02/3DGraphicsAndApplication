#pragma once

#include "Vertex.h"

class Clipper
{
public:
    static Clipper* Get();
public:
    void OnNewFrame();

    bool ClipPoint(const Vertex& v);
    bool ClipLine(Vertex& v0, Vertex& v1);
    bool ClipTrianlge(std::vector<Vertex>& vertics);

    bool IsClippin() const { return mClipping; }
    void SetClipping(bool clip) { mClipping = clip; }

private:
    Clipper();

    bool mClipping = false;
};