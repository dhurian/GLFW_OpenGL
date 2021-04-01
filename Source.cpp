#include <iostream>
#define GLEW_STATIC


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

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
	float vertices[] = {
		10.0,10.0,0.0,
		200.0,200.0,0.0,
		300,400,0,
		400,700,0
	};

	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);
		glLineWidth(10);
		glEnable(GL_LINE_SMOOTH);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, vertices);
		glDrawArrays(GL_LINE_LOOP, 0, 4);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisable(GL_LINE_SMOOTH);
 
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;



}