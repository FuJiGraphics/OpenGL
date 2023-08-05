#include <PCH.h>


int main( void )
{
	glfwInit();

	GLFWwindow* window = glfwCreateWindow( 1280, 720, "OpenGL", nullptr, nullptr );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 2 );

	glfwMakeContextCurrent( window );
	glfwSwapInterval( 1 );

	while ( !glfwWindowShouldClose( window ) )
	{
		glfwPollEvents();

		glfwSwapBuffers( window );
	}

	glfwDestroyWindow( window );
	glfwTerminate();

	return 0;
}