#include "RasterizationScene.h"
#include "Rasterization.h"
#include "ImageUtils.h"
#include "Camera.h"
#include "Time.h"

float sdCircle(Vector2 p, float r)
{
	return Length(p) - r;
}

float step(float edge, float x)
{
	return x < edge ? 0.0f : 1.0f;
}

void RasterizationScene::OnLoad()
{
}

void RasterizationScene::OnUnload()
{
}

void RasterizationScene::OnUpdate(float dt)
{
	// Challenge: render a circle using an SDF (https://www.shadertoy.com/view/XXtfDn)
	ClearColor(&gImageCPU, BLACK);
	for (int y = 0; y < CPU_IMAGE_SIZE; y++)
	{
		for (int x = 0; x < CPU_IMAGE_SIZE; x++)
		{
			Vector2 uv = { x, y };
			uv /= CPU_IMAGE_SIZE;
			uv = uv * 2.0f - 1.0f;

			float c = sdCircle(uv, 0.75f);
			Vector3 rgb = V3_ONE * step(0.0f, c);

			Color color = Float3ToColor(&rgb.x);
			SetPixel(&gImageCPU, x, y, color);
		}
	}
}
