#ifndef SHADER_H__
#define SHADER_H__

#include <string>
#include <GL/glew.h>

namespace OpenGlApplication {

	enum ShaderType {
		VERTEX_SHADER, FRAGMENT_SHADER
	};

	class Shader {

	public:

		Shader();

		~Shader();

		void LoadShaderProgram(std::string filename, ShaderType shaderType);

		void CreateProgram();

		// Uses the current shader
		void Use();

		GLuint ShaderProgram();

	private:

		GLuint m_shaderProgram;
		GLuint m_vertex, m_fragment;

		void CreateVertexShader(std::string programCode);

		void CreateFragmentShader(std::string programCode);

	};
}

#endif //SHADER_H__

