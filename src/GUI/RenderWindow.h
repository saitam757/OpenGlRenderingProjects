#ifndef RENDERWINDOW_H__
#define RENDERWINDOW_H__

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

#include "RenderApplications/IRenderApplication.h"

namespace OpenGlApplication
{
    class RenderWindow
    {
    public:
        static RenderWindow * GetInstance();

        //Constructor (no error)
        RenderWindow();

        //Destructor
        ~RenderWindow();

        void ProcessKeys(int key, int action);

        int InitGL();

        void SetRenderApplication(IRenderApplication* renderApplication);

        int DoRender();

        void SetKey(int key);

        static void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    private:

        static RenderWindow *m_windowInstance;

        GLFWwindow* m_window;

        //GLFWErrorCallback       errorCallback;
        //GLFWKeyCallback* keyCallback;
        //GLFWCursorPosCallback   cursorPosCallback;
        //GLFWMouseButtonCallback mouseButtonCallback;
        //GLFWScrollCallback      scrollCallback;

        IRenderApplication* m_renderApplication;

		int FullScreen();

		int ScreenResolution();
    };

}
#endif //RENDERWINDOW_H__
