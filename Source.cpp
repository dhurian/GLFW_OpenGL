#include <iostream>
#define GLEW_STATIC


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 640

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
		std::cout << "Failæed to initialize GLEW\n";
		return EXIT_FAILURE;

	}


	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	float array[] = {
		20,100,0,
		100,300,0,
		100,50,0,
		320,10,0,
		40,40,0
	};
	glLineWidth(10);
	glPointSize(10);

	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	while (!glfwWindowShouldClose(window)) {
		glEnable(GL_POINT_SMOOTH);
		glClear(GL_COLOR_BUFFER_BIT);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, array);
		glDrawArrays(GL_POLYGON, 0, 5);

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisable(GL_POINT_SMOOTH);

 
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;



}