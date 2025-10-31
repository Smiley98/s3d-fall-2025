#include "RasterizationScene.h"
#include "Rasterization.h"
#include "ImageUtils.h"
#include "Camera.h"
#include "Time.h"

static Image fDiffuseMap;

void Example1();
void Example2();
void Example3();
void Example4();
void Example5();

void RasterizationScene::OnLoad()
{
	gCamera = FromView(LookAt({ 0.0f, 0.0f, 5.0f }, V3_ZERO, V3_UP));
	CreateImageFromFile(&fDiffuseMap, "assets/textures/african_head_diffuse.png", true);
}

void RasterizationScene::OnUnload()
{
	DestroyImage(&fDiffuseMap);
}

void RasterizationScene::OnUpdate(float dt)
{
	ClearColor(&gImageCPU, BLACK);
	Example3();
}

// Solid colour
void Example1()
{
	for (int y = 0; y < CPU_IMAGE_SIZE; y++)
	{
		for (int x = 0; x < CPU_IMAGE_SIZE; x++)
		{
			Color color = RED;
			SetPixel(&gImageCPU, x, y, color);
		}
	}
}

// 1D red gradient
void Example2()
{
	for (int y = 0; y < CPU_IMAGE_SIZE; y++)
	{
		for (int x = 0; x < CPU_IMAGE_SIZE; x++)
		{
			// Convert from [0, 512] to [0, 1]
			float u = x / (float)CPU_IMAGE_SIZE;
			
			// s3d expects colors within the range of [0, 255], so convert!
			Color color = BLACK;
			color.r = u * 255.0f;

			SetPixel(&gImageCPU, x, y, color);
		}
	}
}

// 2D red-green-yellow-black gradient
void Example3()
{
	for (int y = 0; y < CPU_IMAGE_SIZE; y++)
	{
		for (int x = 0; x < CPU_IMAGE_SIZE; x++)
		{
			// Best to use vector-math to do component-wise operations!
			Vector2 uv = { x, y };
			uv /= CPU_IMAGE_SIZE;

			// Automatically convert vec2/vec3/vec4 to colour when you're done!
			Color color = Float2ToColor(&uv.x);
			SetPixel(&gImageCPU, x, y, color);
		}
	}
}

// Challenge 1 (medium) -- render the following fading 2d gradient: https://www.shadertoy.com/view/MXKcR3
void Example4()
{

}

// Challenge 2 (impossible) -- render the animating ring: https://www.shadertoy.com/view/X3tBDs
void Example5()
{

}