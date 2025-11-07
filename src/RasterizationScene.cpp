#include "RasterizationScene.h"
#include "Rasterization.h"
#include "ImageUtils.h"
#include "Camera.h"
#include "Time.h"

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
			Vector3 rgb = V3_ONE;

			Color color = Float3ToColor(&rgb.x);
			SetPixel(&gImageCPU, x, y, color);
		}
	}
}

void Example2()
{
}
