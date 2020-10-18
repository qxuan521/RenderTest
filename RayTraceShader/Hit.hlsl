#include "Common.hlsl"
struct STriVertex
{
    float3 vertex;
    float4 color;
};

StructuredBuffer<STriVertex> BTriVertex : register(t0);
[shader("closesthit")] 

void ClosestHit(inout HitInfo payload, Attributes attrib) 
{
    float3 barycentrics =
    float3(1.f - attrib.bary.x - attrib.bary.y, attrib.bary.x, attrib.bary.y);

    const float3 A = float3(1, 0, 0);
    const float3 B = float3(0, 1, 0);
    const float3 C = float3(0, 0, 1);

    //float3 hitColor = A * barycentrics.x + B * barycentrics.y + C * barycentrics.z;
    uint vertId = 3 * PrimitiveIndex();
    // #DXR Extra: Per-Instance Data
    float3 hitColor = float3(0.7, 0.7, 0.7);
    switch (InstanceID())
    {
    case 0:
        hitColor = A * barycentrics.x + B * barycentrics.y + C * barycentrics.z;
        break;
    case 1:
        hitColor = B * barycentrics.x + B * barycentrics.y + C * barycentrics.z;
        break;
    case 2:
        hitColor = C * barycentrics.x + B * barycentrics.y + C * barycentrics.z;
        break;
    }
  /*  float3 hitColor = BTriVertex[vertId + 0].color * barycentrics.x +
        BTriVertex[vertId + 1].color * barycentrics.y +
        BTriVertex[vertId + 2].color * barycentrics.z;*/
    payload.colorAndDistance = float4(hitColor, RayTCurrent());
}
