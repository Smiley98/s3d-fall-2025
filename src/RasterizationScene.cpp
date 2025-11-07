#include "RasterizationScene.h"
#include "Rasterization.h"
#include "ImageUtils.h"
#include "Camera.h"
#include "Time.h"

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
			SetPixel(&gImageCPU, x, y, BLUE);
		}
	}
}
