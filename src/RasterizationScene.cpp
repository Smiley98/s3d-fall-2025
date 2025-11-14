#include "RasterizationScene.h"
#include "Rasterization.h"
#include "ImageUtils.h"
#include "Window.h"
#include "Camera.h"
#include "Time.h"

void Homework4();
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
	//Homework4();
	Example1();
}

void Homework4()
{
	Image* img = &gImageCPU;

	// Draw 2 horizontal lines
	DrawLineX(img, 100, 100, 200, RED);
	DrawLineX(img, 200, 200, 300, RED);

	// Draw 2 vertical lines
	DrawLineY(img, 100, 100, 200, GREEN);
	DrawLineY(img, 200, 200, 300, GREEN);

	// Draw a rectangle in the centre of your screen and outline it
	DrawRect(img, 252, 252, 8, 8, BLUE);
	DrawRectLines(img, 251, 251, 9, 9, MAGENTA);

	// Draw a border around your screen using DrawRectLines
	DrawRectLines(img, 0, 0, CPU_IMAGE_SIZE - 1, CPU_IMAGE_SIZE - 1, CYAN);

	// Draw a circle at your mouse cursor and outline it
	Vector2 mouse = GetMousePosition();
	mouse.x = Remap(mouse.x, 0.0f, SCREEN_WIDTH, 0.0f, CPU_IMAGE_SIZE);
	mouse.y = Remap(mouse.y, SCREEN_HEIGHT, 0.0f, 0.0f, CPU_IMAGE_SIZE);

	int r = 5;
	Vector2 min{ (float)r, (float)r };
	Vector2 max{ CPU_IMAGE_SIZE - (r + 1), CPU_IMAGE_SIZE - (r + 1) };
	mouse = Clamp(mouse, min, max);
	DrawCircle(img, mouse.x, mouse.y, r, GRAY);

	// Draw a line connecting the centre rectangle to the cursor circle
	DrawLine(img, 255, 255, mouse.x, mouse.y, YELLOW);
}

void Example1()
{
	Vector3 triangle[]
	{
		{ 0.5f, -0.5f, 0.0f },
		{ 0.0f, 0.5f, 0.0f },
		{ -0.5f, -0.5f, 0.0f }
	};

	DrawFaceWireframes(&gImageCPU, triangle, 0, RED);
}

void Example2()
{

}
