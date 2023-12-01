#pragma once

#include "RenderEngine.h"
#include "Cube.h"
#include "Shader.h"

class Application :
	public RenderEngine
{
public:
	Application();
	~Application();
private:
	Shader* shader;
	Cube* cube;
	float angle;
	glm::vec3 viewPos;
	double lastFrameTime = glfwGetTime();
	void setupPerspective();
	void setupCamera();
	void setupLighting();
	// Tambahkan fungsi untuk mengupdate orientasi kamera berdasarkan input mouse
	void UpdateCameraDirection(double xpos, double ypos);
	// Tambahkan variabel posisi entitas
	glm::vec3 entityPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	// Tambahkan variabel kecepatan gerak
	float movementSpeed = 5.0f;
	virtual void Init();
	virtual void DeInit();
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void ProcessInput(GLFWwindow* window);
	const int windowWidth = 1280;
	const int windowHeight = 768;
	bool lampOn = true;
	bool skyOn = true;
	double lastLightToggled = 0;
	// Tambahkan variabel anguler untuk mengontrol orientasi kamera
	float yaw = -90.0f;
	float pitch = 0.0f;
	glm::vec3 viewDir = glm::vec3(0.0f, 0.0f, -1.0f); // Vektor arah pandangan kamera

	bool firstMouse = true;
	float lastX = windowWidth / 2.0f;
	float lastY = windowHeight / 2.0f;
};