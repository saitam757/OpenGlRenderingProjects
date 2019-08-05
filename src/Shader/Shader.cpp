#include "Shader/Shader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

using namespace OpenGlApplication;

Shader::Shader() {
}

Shader::~Shader() {
}

void Shader::LoadShaderProgram(std::string filename, ShaderType shaderType) {
	std::string shaderCode;
	std::ifstream shaderFile;

	// ensures ifstream objects can throw exceptions:
	shaderFile.exceptions(std::ifstream::badbit);

	try {
		// Open files
		shaderFile.open(filename);
		std::stringstream shaderStream;
		// Read file's buffer contents into streams
		shaderStream << shaderFile.rdbuf();

		// close file handlers
		shaderFile.close();

		// Convert stream into string
		shaderCode = shaderStream.str();

		if (shaderType == ShaderType::VERTEX_SHADER) {
			CreateVertexShader(shaderCode);
		} else if (shaderType == ShaderType::FRAGMENT_SHADER) {
			CreateFragmentShader(shaderCode);
		}
	} catch (std::ifstream::failure e) {
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
}

void Shader::CreateVertexShader(std::string programCode) {
	const GLchar* vprogramCode = programCode.c_str();

	GLint success;
	GLchar infoLog[512];
	// Vertex Shader
	m_vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(m_vertex, 1, &vprogramCode, NULL);
	glCompileShader (m_vertex);
	// Print compile errors if any
	glGetShaderiv(m_vertex, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(m_vertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog
				<< std::endl;
	}
}

void Shader::CreateFragmentShader(std::string programCode) {
	const GLchar* vprogramCode = programCode.c_str();

	GLint success;
	GLchar infoLog[512];
	// Vertex Shader
	m_fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(m_fragment, 1, &vprogramCode, NULL);
	glCompileShader (m_fragment);
	// Print compile errors if any
	glGetShaderiv(m_fragment, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(m_fragment, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog
				<< std::endl;
	}
}

void Shader::CreateProgram() {
	GLint success;
	GLchar infoLog[512];
	// Shader Program
	this->m_shaderProgram = glCreateProgram();
	glAttachShader(this->m_shaderProgram, m_vertex);
	glAttachShader(this->m_shaderProgram, m_fragment);
	glLinkProgram(this->m_shaderProgram);
	// Print linking errors if any
	glGetProgramiv(this->m_shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(this->m_shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog
				<< std::endl;
	}
	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader (m_vertex);
	glDeleteShader (m_fragment);
}


// Uses the current shader
void Shader::Use() {
	glUseProgram(this->m_shaderProgram);
}


GLuint Shader::ShaderProgram()
{
	return this->m_shaderProgram;
}



