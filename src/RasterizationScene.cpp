#include "RasterizationScene.h"
#include "Rasterization.h"
#include "ImageUtils.h"
#include "Window.h"
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
	Image* img = &gImageCPU;
	ClearColor(img, BLACK);

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
	mouse.x = Remap(mouse.x, 0.0f, SCREEN_WIDTH,  0.0f, CPU_IMAGE_SIZE);
	mouse.y = Remap(mouse.y, SCREEN_HEIGHT, 0.0f, 0.0f, CPU_IMAGE_SIZE);

	int r = 5;
	Vector2 min{ (float)r, (float)r };
	Vector2 max{ CPU_IMAGE_SIZE - (r + 1), CPU_IMAGE_SIZE - (r + 1) };
	mouse = Clamp(mouse, min, max);
	DrawCircle(img, mouse.x, mouse.y, r, GRAY);
	
	// Draw a line connecting the centre rectangle to the cursor circle
	DrawLine(img, 255, 255, mouse.x, mouse.y, YELLOW);
}
