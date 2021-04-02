#include <iostream>
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 640

void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides);




int main() {

	glfwInit();


	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Learn OpenGL", nullptr, nullptr);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
	if(nullptr==window)
	{
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (GLEW_OK != glewInit()) {
		std::cout << "Fail�ed to initialize GLEW\n";
		return EXIT_FAILURE;

	}


	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);

		drawCircle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 0, 200,10);
 
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;



}



void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides) {

	GLint numberOfVertices = numberOfSides+1;

	GLfloat doublePi = 2.0 * 3.1415;
	GLfloat circleVerticesX[100];
	GLfloat circleVerticesY[100];
	GLfloat circleVerticesZ[100];



	for (int i = 0; i < numberOfVertices; i++) {

		circleVerticesX[i] = x + (radius * cos(i * doublePi / numberOfSides));
		circleVerticesY[i] = y + (radius * sin(i * doublePi / numberOfSides));
		circleVerticesZ[i] = z;
	}
		GLfloat allCircleVertices[300];

		for (int i = 0; i < numberOfVertices; i++) {
			allCircleVertices[i * 3] = circleVerticesX[i];
			allCircleVertices[i * 3+1] = circleVerticesY[i];
			allCircleVertices[i * 3+2] = circleVerticesZ[i];

		}

		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, allCircleVertices);
		glDrawArrays(GL_LINE_STRIP, 0, numberOfVertices);
		glDisableClientState(GL_VERTEX_ARRAY);


}
