#include "RasterizationScene.h"
#include "Rasterization.h"
#include "ImageUtils.h"
#include "Camera.h"
#include "Time.h"

void Example1();
void Example2();
void Example3();
void Example4();
void Example5();

void RasterizationScene::OnLoad()
{
}

void RasterizationScene::OnUnload()
{
}

void RasterizationScene::OnUpdate(float dt)
{
	ClearColor(&gImageCPU, BLACK);
	//Example1();
	//Example2();
	//Example3();
	Example4();
	//Example5();
}

void Example1()
{
	// Solid colour image
	for (int y = 0; y < CPU_IMAGE_SIZE; y++)
	{
		for (int x = 0; x < CPU_IMAGE_SIZE; x++)
		{
			Color color = BLUE;
			SetPixel(&gImageCPU, x, y, color);
		}
	}
}

void Example2()
{
	// 1D gradient -- https://www.shadertoy.com/view/43Kyzc
	for (int y = 0; y < CPU_IMAGE_SIZE; y++)
	{
		for (int x = 0; x < CPU_IMAGE_SIZE; x++)
		{
			// Modify this to be the horizontal position of the pixel (x) divided by the image size (CPU_IMAGE_SIZE)
			float u = x / (float)CPU_IMAGE_SIZE;

			Color color = BLACK;
			color.r = u * 255.0f;

			SetPixel(&gImageCPU, x, y, color);
		}
	}
}

void Example3()
{
	// 2D gradient -- https://www.shadertoy.com/view/43Kyzc
	for (int y = 0; y < CPU_IMAGE_SIZE; y++)
	{
		for (int x = 0; x < CPU_IMAGE_SIZE; x++)
		{
			// Calculate uv by dividing the xy position of the pixel by image size
			Vector2 uv = V2_ZERO;

			Color color = Float2ToColor(&uv.x);
			SetPixel(&gImageCPU, x, y, color);
		}
	}
}

// Challenge 1 - Fading gradient
void Example4()
{
	// Time since s3d start
	float t = TotalTime();

	// Fading 2D gradient -- https://www.shadertoy.com/view/MXKcR3
	for (int y = 0; y < CPU_IMAGE_SIZE; y++)
	{
		for (int x = 0; x < CPU_IMAGE_SIZE; x++)
		{
			// Blend between red-green gradient and blue-purple gradient
			Vector2 uv = { x, y };
			uv /= CPU_IMAGE_SIZE;

			Color color = Float2ToColor(&uv.x);
			SetPixel(&gImageCPU, x, y, color);
		}
	}
}

// Challenge 2 -- Animating ring
void Example5()
{
	// Ultra-difficult task: make the "Ring of PTSD" -- https://www.shadertoy.com/view/X3tBDs
	// You'll need to make glsl functions such as step yourself since they're not part of C++!
}