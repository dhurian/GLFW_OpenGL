#include <iostream>
#define GLEW_STATIC

#include <gl/glew.h>
#include <GLFW/glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;

int main() {

	glfwInit();


	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Learn OpenGL", nullptr, nullptr);

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
	glViewport(0, 0, screenWidth, screenHeight);

	float vertices[] = {
		0.0, 0.5,0.0,
		-0.5,-0.5,0.0,
		0.5,-0.5,0.0
	};
	while (!glfwWindowShouldClose(window)) {

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, vertices);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableClientState(GL_VERTEX_ARRAY);


 
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;



}