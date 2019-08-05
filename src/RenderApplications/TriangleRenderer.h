#ifndef TRIANGLERENDERER_H__
#define TRIANGLERENDERER_H__

#include "RenderApplications/IRenderApplication.h"
#include "Shader/Shader.h"

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

namespace OpenGlApplication
{
	class TriangleRenderer : public IRenderApplication
	{
		public:

			TriangleRenderer();

			virtual ~TriangleRenderer();

			virtual void Init();

			virtual void DoRender();

            virtual void SetKey(int key);

		private:
			GLuint m_VAO, m_VBO;

			Shader* m_shader;
	};
}

#endif //TRIANGLERENDERER_H__
