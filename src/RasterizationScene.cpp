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
std::vector<Vector3> VerticesFromIndices(std::vector<Vector3> positions, std::vector<uint16_t> indices);

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
	//Example2();
	Example3();
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
	std::vector<Vector3> plane_vertices;
	plane_vertices.resize(4);
	plane_vertices[0] = { 0.5f, -0.5f, 0.0f };	// bottom-right;
	plane_vertices[1] = { 0.5f,  0.5f, 0.0f };	// top-right;
	plane_vertices[2] = { -0.5f,  0.5f, 0.0f };	// top-left;
	plane_vertices[3] = { -0.5f, -0.5f, 0.0f };	// bottom-left;

	std::vector<uint16_t> plane_indices;
	plane_indices.resize(6);
	plane_indices[0] = 0;
	plane_indices[1] = 1;
	plane_indices[2] = 3;
	plane_indices[3] = 1;
	plane_indices[4] = 2;
	plane_indices[5] = 3;

	std::vector<Vector3> plane_positions = VerticesFromIndices(plane_vertices, plane_indices);
	
	Image* img = &gImageCPU;
	DrawFaceWireframes(img, plane_positions.data(), 0, GREEN);
	DrawFaceWireframes(img, plane_positions.data(), 1, GREEN);
}

void Example3()
{
	// Challenge: Try applying a transformation matrix to sphere_position in order to rotate the sphere continuously about the y-axis
	// You'll want to use the RotateY() function in conjunction with the TotalTime() function!

	std::vector<Vector3> sphere_position = VerticesFromIndices(gMeshSphere.positions, gMeshSphere.indices);
	for (int i = 0; i < sphere_position.size() / 3; i++)
		DrawFaceWireframes(&gImageCPU, sphere_position.data(), i, GREEN);
}

std::vector<Vector3> VerticesFromIndices(std::vector<Vector3> positions, std::vector<uint16_t> indices)
{
	std::vector<Vector3> vertices;
	vertices.resize(indices.size());

	for (int i = 0; i < indices.size(); i++)
	{
		vertices[i] = positions[indices[i]];
	}

	return vertices;
}
