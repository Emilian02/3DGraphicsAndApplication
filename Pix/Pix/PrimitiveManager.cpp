#include "PrimitiveManager.h"
#include "Rasterizer.h"
#include "Clipper.h"
#include "Camera.h"
#include "MatrixStack.h"

extern float gResolutionX;
extern float gResolutionY;

namespace
{
    Matrix4 GetScreenMatrix()
    {
        float hw = gResolutionX * 0.5f;
        float hh = gResolutionY * 0.5f;

        return Matrix4(
              hw, 0.0f, 0.0f, 0.0f,
            0.0f,  -hh, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
              hw,   hh, 0.0f, 1.0f
        );
    }

    bool CullTriangle(CullMode mode, const std::vector<Vertex>& triangleInNDC)
    {
        if (mode == CullMode::None)
        {
            return false;
        }

        Vector3 abDir = triangleInNDC[1].pos - triangleInNDC[0].pos;
        Vector3 acDir = triangleInNDC[2].pos - triangleInNDC[0].pos;
        Vector3 faceNorm = MathHelper::Normalize(MathHelper::Cross(abDir, acDir));
        if (mode == CullMode::Back)
        {
            return faceNorm.z > 0.0f;
        }
        if (mode == CullMode::Front)
        {
            return faceNorm.z < 0.0f;
        }

        return false;
    }
}

PrimitiveManager::PrimitiveManager()
{
}

PrimitiveManager::~PrimitiveManager()
{
}

PrimitiveManager* PrimitiveManager::Get() 
{
    static PrimitiveManager sInstance;
    return &sInstance;
}

void PrimitiveManager::OnNewFrame()
{
    mCullMode = CullMode::None;
}

void PrimitiveManager::SetCullMode(CullMode mode)
{
    mCullMode = mode;
}

bool PrimitiveManager::BeginDraw(Topology topology, bool applyTransform)
{
    mTopology = topology;
    mApplyTransform = applyTransform;
    mDrawBegin = true;
    mVertexBuffer.clear();
    return true;
}
void PrimitiveManager::AddVertex(const Vertex& vertex)
{
    if (mDrawBegin)
    {
        mVertexBuffer.push_back(vertex);
    }
}
bool PrimitiveManager::EndDraw()
{
    if (!mDrawBegin)
    {
        return false;
    }

    switch (mTopology)
    {
    case Topology::Point:
    {
        for (size_t i = 0; i < mVertexBuffer.size(); ++i)
        {
            if (!Clipper::Get()->ClipPoint(mVertexBuffer[i]))
            {
                Rasterizer::Get()->DrawPoint(mVertexBuffer[i]);
            }
        }
    }
    break;
    case Topology::Line:
    {
        for (size_t i = 1; i < mVertexBuffer.size(); i += 2)
        {
            if (!Clipper::Get()->ClipLine(mVertexBuffer[i - 1], mVertexBuffer[i]))
            {
                Rasterizer::Get()->DrawLine(mVertexBuffer[i - 1], mVertexBuffer[i]);
            }
        }
    }
    break;
    case Topology::Trianlge:
    {
        Matrix4 matWorld = MatrixStack::Get()->GetTransform();
        Matrix4 matView = Camera::Get()->GetViewMatrix();
        Matrix4 matProj = Camera::Get()->GetProjectionMatrix();
        Matrix4 matScreen = GetScreenMatrix();
        Matrix4 matNDC = matWorld * matView * matProj;

        for (size_t i = 2; i < mVertexBuffer.size(); i += 3)
        {
            std::vector<Vertex> triangle = { mVertexBuffer[i - 2], mVertexBuffer[i - 1], mVertexBuffer[i] };

            if (mApplyTransform)
            {
                for (size_t t = 0; t < triangle.size(); ++t)
                {
                    Vector3 ndcPos = MathHelper::TransformCoord(triangle[t].pos, matNDC);
                    triangle[t].pos = ndcPos;
                }

                if (CullTriangle(mCullMode, triangle))
                {
                    continue;
                }

                for (size_t t = 0; t < triangle.size(); ++t)
                {
                    Vector3 screenPos = MathHelper::TransformCoord(triangle[t].pos, matScreen);
                    screenPos.x = floor(screenPos.x + 0.5f);
                    screenPos.y = floor(screenPos.y + 0.5f);
                    triangle[t].pos = screenPos;
                }
            }

            if (!Clipper::Get()->ClipTriangle(triangle))
            {
                for (size_t t = 2; t < triangle.size(); ++t)
                {

                    Rasterizer::Get()->DrawTriangle(triangle[0], triangle[t - 1], triangle[t]);
                }
            }

        }
    }
    break;
    default:
        break;
    }

    mDrawBegin = false;
    return true;
}
