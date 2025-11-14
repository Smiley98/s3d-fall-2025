#include "RasterizationScene.h"
#include "Rasterization.h"
#include "ImageUtils.h"
#include "Window.h"
#include "Camera.h"
#include "Time.h"
#include "Mesh.h"

void Homework4();
void Example1();
void Example2();
void Example3();

std::vector<Vector3> VerticesFromIndices(std::vector<Vector3> unique_vertices, std::vector<uint16_t> indices);

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
	//Example1();
	Example2();
}

void Homework4()
{
	const int sz = CPU_IMAGE_SIZE;
	Image* img = &gImageCPU;

	DrawLineX(img, 100, 100, 200, RED);
	DrawLineX(img, 200, 200, 300, RED);
	DrawLineY(img, 100, 100, 200, GREEN);
	DrawLineY(img, 200, 200, 300, GREEN);

	DrawRect(img, 252, 252, 8, 8, BLUE);
	DrawRectLines(img, 251, 251, 9, 9, MAGENTA);
	DrawRectLines(img, 0, 0, sz - 1, sz - 1, CYAN);

	int r = 5;
	Vector2 mouse = GetMousePosition();
	mouse.x = Remap(mouse.x, 0.0f, SCREEN_WIDTH, 0.0f, sz);
	mouse.y = Remap(mouse.y, SCREEN_HEIGHT, 0.0f, 0.0f, sz);

	Vector2 min = { r, r };
	Vector2 max = { (sz - 1) - r, (sz - 1) - r };
	mouse = Clamp(mouse, min, max);
	DrawCircle(img, mouse.x, mouse.y, r, GRAY);
	DrawLine(img, 255, 255, mouse.x, mouse.y, YELLOW);

	// Homework:
	// Draw a border around your screen using DrawRectLines
	// Draw 2 horizontal lines
	// Draw 2 vertical lines
	// Draw a rectangle in the centre of your screen and outline it
	// Draw a circle at your mouse cursor and outline it
	// Draw a line connecting the above two shapes
}

void Example1()
{
	Vector3 triangle[]
	{
		{ 0.5f, -0.5f, 0.0f },
		{ 0.0f,  0.5f, 0.0f },
		{-0.5f, -0.5f, 0.0f }
	};

	DrawFaceWireframes(&gImageCPU, triangle, 0);
}

void Example2()
{
	std::vector<Vector3> plane_vertex_positions
	{
		{  0.5f, -0.5f, 0.0f },	// bottom-right
		{  0.5f,  0.5f, 0.0f },	// top-right
		{ -0.5f,  0.5f, 0.0f },	// top-left
		{ -0.5f, -0.5f, 0.0f },	// bottom-left
	};

	std::vector<uint16_t> plane_vertex_indices
	{
		0, 1, 3,
		1, 2, 3
	};

	std::vector<Vector3> positions = VerticesFromIndices(plane_vertex_positions, plane_vertex_indices);
	DrawFaceWireframes(&gImageCPU, positions.data(), 0, MAGENTA);
	DrawFaceWireframes(&gImageCPU, positions.data(), 1, RED);
}

void Example3()
{
}

std::vector<Vector3> VerticesFromIndices(std::vector<Vector3> unique_vertices, std::vector<uint16_t> indices)
{
	std::vector<Vector3> positions;
	positions.resize(indices.size());

	for (int i = 0; i < positions.size(); i++)
		positions[i] = unique_vertices[indices[i]];

	return positions;
}
