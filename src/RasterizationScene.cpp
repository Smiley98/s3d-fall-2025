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

void Example1();
void Example2();

void RasterizationScene::OnLoad()
{
}

void RasterizationScene::OnUnload()
{
}

void RasterizationScene::OnUpdate(float dt)
{
	ClearColor(&gImageCPU, BLACK);
	Example1();
	//Example2();
}

// Challenge: Port the following shader to s3d: https://www.shadertoy.com/view/XXtfDn
// If you want to use glsl's step function, you'll also need to port that to s3d:
// https://registry.khronos.org/OpenGL-Refpages/gl4/html/step.xhtml
void Example1()
{
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

void Example2()
{
}
