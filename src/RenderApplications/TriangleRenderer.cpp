#include "RenderApplications/TriangleRenderer.h"
#include "Shader/Shader.h"

#include <string>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// TODO find a better solution here
#define SHADER_DIR "/home/bender/Projekte/Programming/C++/OpenGlRenderingProjects/src/Shader/"


using namespace OpenGlApplication;

TriangleRenderer::TriangleRenderer() :
		m_shader(nullptr) {
}

TriangleRenderer::~TriangleRenderer() {
	if (m_shader != nullptr) {
		delete m_shader;
	}

	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
}


void TriangleRenderer::SetKey(int key)
{

}

void TriangleRenderer::Init() {
    std::string vertexShader = SHADER_DIR"VertexShaders/DefaultVertexShader.vert";
    std::string fragmentShader = SHADER_DIR"FragmentShaders/DefaultFragmentShader.frag";

	m_shader = new Shader();
	m_shader->LoadShaderProgram(vertexShader, ShaderType::VERTEX_SHADER);
	m_shader->LoadShaderProgram(fragmentShader, ShaderType::FRAGMENT_SHADER);
	m_shader->CreateProgram();

	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = { -0.5f, -0.5f, 0.0f, // Left
			0.5f, -0.5f, 0.0f, // Right
			0.0f, 0.5f, 0.0f  // Top
			};

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(m_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
			(GLvoid*) 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
}


void TriangleRenderer::DoRender() {
	// Render
	// Clear the colorbuffer
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw our first triangle
	m_shader->Use();

	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}
