#include <PCH.h>

int main( void )
{
	glfwInit();

	GLFWwindow* window = glfwCreateWindow( 1280, 720, "OpenGL", nullptr, nullptr );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 2 );

	glfwMakeContextCurrent( window );
	glfwSwapInterval( 1 );

	NR_INFO( (const char*)glGetString( GL_VERSION ) );

	glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
	while ( !glfwWindowShouldClose( window ) )
	{
		glClear( GL_COLOR_BUFFER_BIT );

		glBegin( GL_LINE_LOOP );
		glVertex2f( -0.5f, -0.5f );
		glVertex2f( +0.5f, -0.5f );
		glVertex2f( +0.0f, +0.5f );
		glEnd();

		glFlush();
		
		glfwSwapBuffers( window );
		glfwPollEvents();
	}

	glfwDestroyWindow( window );
	glfwTerminate();

	return 0;
}