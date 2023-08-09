#include <PCH.h>


// TODO : 셰이더 트라이앵글 그리기, 진도 나가기

int main( void )
{
	glfwInit();

	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 2 );
	GLFWwindow* window = glfwCreateWindow( 1280, 720, "OpenGL", nullptr, nullptr );

	glfwMakeContextCurrent( window );
	glfwSwapInterval( 1 );

	NR_INFO( (const char*)glGetString( GL_VERSION ) );

	// GLEW Initialize
	glewInit();

	// Create Vertex Datas
	float vertices[] = {
		-0.5f, -0.5f,
		+0.5f, -0.5f,
		+0.0f, +0.5f,
	};

	// Create Index Datas
	unsigned int indices[] = {
		0, 1, 2
	};

	// Vertex Attribute Object
	GLuint vertexArraysID = 0;
	glGenVertexArrays( 1, &vertexArraysID );
	glBindVertexArray( vertexArraysID );

	// Create Vertex Buffer
	unsigned int vertexBufferID;
	glGenBuffers( 1, &vertexBufferID );
	glBindBuffer( GL_ARRAY_BUFFER, vertexBufferID );
	glBufferData( GL_ARRAY_BUFFER, sizeof( vertices ), vertices, GL_STATIC_DRAW );
	
	//// Create Vertex Array Layout
	glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, sizeof( GL_FLOAT ) * 2, (GLvoid*)0 );
	glEnableVertexAttribArray( 0 );

	//// Create Index Buffer
	unsigned int indexBufferID;
	glGenBuffers( 1, &indexBufferID );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indexBufferID );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_STATIC_DRAW );


	glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
	while ( !glfwWindowShouldClose( window ) )
	{
		glClear( GL_COLOR_BUFFER_BIT );

		glDrawElements( GL_TRIANGLES, 3, GL_UNSIGNED_INT, (GLvoid*)0 );

		glfwSwapBuffers( window );
		glfwPollEvents();
	}

	glfwDestroyWindow( window );
	glfwTerminate();

	return 0;
}