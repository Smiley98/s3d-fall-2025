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
	Image* img = &gImageCPU;
	ClearColor(img, BLACK);

	DrawLineX(img, 100, 100, 200, RED);
	DrawLineX(img, 200, 200, 300, RED);

	DrawLineY(img, 100, 100, 200, GREEN);
	DrawLineY(img, 200, 200, 300, GREEN);

	DrawRect(img, 300, 300, 100, 100, BLUE);
	DrawRectLines(img, 299, 299, 101, 101, MAGENTA);

	// Homework:
	// Draw a border around your screen using DrawRectLines
	// Draw 2 horizontal lines
	// Draw 2 vertical lines
	// Draw a rectangle in the centre of your screen and outline it
	// Draw a circle at your mouse cursor and outline it
	// Draw a line connecting the above two shapes
}