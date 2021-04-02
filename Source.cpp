
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
#include <cstdlib>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
void drawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLenght);

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;
int main() {

	glfwInit();


	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Learn OpenGL", nullptr, nullptr);
	
	glfwSetKeyCallback(window, keyCallBack);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
	if(nullptr==window)
	{
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	/*glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit()) {
		std::cout << "Failæed to initialize GLEW\n";
		return EXIT_FAILURE;

	}*/


	glViewport(0.0f, 0.0f, screenWidth, screenHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
	GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;



	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);

		glPushMatrix();
		glTranslatef(halfScreenWidth, halfScreenHeight, -500);

		glRotatef(rotationX, 1, 0, 0);

		glRotatef(rotationY, 0, 1, 0);

		glTranslatef(-halfScreenWidth, -halfScreenHeight, 500);

		drawCube(halfScreenWidth, halfScreenHeight, -500, 50);

		drawCube(halfScreenWidth, halfScreenHeight-100, -500,50);
		glPopMatrix();


		
		glfwSwapBuffers(window);
	

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;



}



void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {

	const GLfloat rotationSpeed = 10;
	if (action == GLFW_PRESS || action == GLFW_REPEAT) {

		switch (key) {
		case GLFW_KEY_UP:
			rotationX -= rotationSpeed;
			break;
		case GLFW_KEY_DOWN:
			rotationX += rotationSpeed;
			break;
		case GLFW_KEY_RIGHT:
			rotationY += rotationSpeed;
			break;
		case GLFW_KEY_LEFT:
			rotationY -= rotationSpeed;
			break;
		}

	}
}

void drawCube(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLenght) {
	
	GLfloat halfSideLenght = edgeLenght * 0.5f;
	GLfloat vertices[] = {
		//Front Face
		centerPosX - halfSideLenght, centerPosY + halfSideLenght, centerPosZ + halfSideLenght,//top left
		centerPosX + halfSideLenght, centerPosY + halfSideLenght, centerPosZ + halfSideLenght, // top right
		centerPosX + halfSideLenght, centerPosY - halfSideLenght, centerPosZ + halfSideLenght,//bottom right
		centerPosX - halfSideLenght, centerPosY - halfSideLenght, centerPosZ + halfSideLenght, //bottom left

		//Back Face
		centerPosX - halfSideLenght, centerPosY + halfSideLenght, centerPosZ - halfSideLenght,//top left
		centerPosX + halfSideLenght, centerPosY + halfSideLenght, centerPosZ - halfSideLenght, // top right
		centerPosX + halfSideLenght, centerPosY - halfSideLenght, centerPosZ - halfSideLenght,//bottom right
		centerPosX - halfSideLenght, centerPosY - halfSideLenght, centerPosZ - halfSideLenght, //bottom left

		//Left Face
		centerPosX - halfSideLenght, centerPosY + halfSideLenght, centerPosZ + halfSideLenght,//top left
		centerPosX - halfSideLenght, centerPosY + halfSideLenght, centerPosZ - halfSideLenght, // top right
		centerPosX - halfSideLenght, centerPosY - halfSideLenght, centerPosZ - halfSideLenght,//bottom right
		centerPosX - halfSideLenght, centerPosY - halfSideLenght, centerPosZ + halfSideLenght, //bottom left

		//Right Face
		centerPosX + halfSideLenght, centerPosY + halfSideLenght, centerPosZ + halfSideLenght,//top left
		centerPosX + halfSideLenght, centerPosY + halfSideLenght, centerPosZ - halfSideLenght, // top right
		centerPosX + halfSideLenght, centerPosY - halfSideLenght, centerPosZ - halfSideLenght,//bottom right
		centerPosX + halfSideLenght, centerPosY - halfSideLenght, centerPosZ + halfSideLenght, //bottom left


		//Top Face
		centerPosX - halfSideLenght, centerPosY + halfSideLenght, centerPosZ + halfSideLenght,//top left
		centerPosX - halfSideLenght, centerPosY + halfSideLenght, centerPosZ - halfSideLenght, // top right
		centerPosX + halfSideLenght, centerPosY + halfSideLenght, centerPosZ - halfSideLenght,//bottom right
		centerPosX + halfSideLenght, centerPosY + halfSideLenght, centerPosZ + halfSideLenght, //bottom left

		//Bottom Face
		centerPosX - halfSideLenght, centerPosY - halfSideLenght, centerPosZ + halfSideLenght,//top left
		centerPosX - halfSideLenght, centerPosY - halfSideLenght, centerPosZ - halfSideLenght, // top right
		centerPosX + halfSideLenght, centerPosY - halfSideLenght, centerPosZ - halfSideLenght,//bottom right
		centerPosX + halfSideLenght, centerPosY - halfSideLenght, centerPosZ + halfSideLenght //bottom left
	};
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_QUADS, 0, 24);
	glDisableClientState(GL_VERTEX_ARRAY);
}