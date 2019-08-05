#include "GUI/RenderWindow.h"
#include "RenderApplications/IRenderApplication.h"

#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

using namespace OpenGlApplication;

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;


RenderWindow* RenderWindow::m_windowInstance = nullptr;


RenderWindow::RenderWindow() {
}

RenderWindow::~RenderWindow() {
}

RenderWindow* RenderWindow::GetInstance()
{
    if( m_windowInstance == nullptr )
        m_windowInstance = new RenderWindow();
    return  m_windowInstance;
}

int RenderWindow::InitGL() {
    std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
    // Init GLFW
    glfwInit();

    std::cout << " 1 ** " << glGetError() << std::endl;

    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

    std::cout << " 2 ** " << glGetError() << std::endl;


    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    std::cout << " 3 ** " << glGetError() << std::endl;

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    std::cout << " 4 ** " << glGetError() << std::endl;

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    //if (FullScreen() < 0)
    //{
    //	return -1;
    //}

    ScreenResolution();

    std::cout << " 5 ** " << glGetError() << std::endl;

    glfwMakeContextCurrent(m_window);

    std::cout << " 6 ** " << glGetError() << std::endl;

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;

    std::cout << " 7 ** " << glGetError() << std::endl;

    // Initialize GLEW to setup the OpenGL Function pointers
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // Define the viewport dimensions
    int width, height;

    std::cout << " 9 ** " << glGetError() << std::endl;

    glfwGetFramebufferSize(m_window, &width, &height);

    std::cout << " 10 ** " << glGetError() << std::endl;

    glViewport(0, 0, width, height);

    std::cout << " 11 ** " << glGetError() << std::endl;

    //keyCallback = GLFWKeyCallback(this::glfwKeyCallback);

    glfwSetKeyCallback(m_window, RenderWindow::glfwKeyCallback);

    return 0;
}


int RenderWindow::FullScreen()
{
    const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    m_window = glfwCreateWindow(mode->width, mode->height, "LearnOpenGL", glfwGetPrimaryMonitor(), nullptr);
    if (m_window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    return 0;
}

int RenderWindow::ScreenResolution()
{
    // Create a GLFWwindow object that we can use for GLFW's functions
    m_window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    if (m_window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    return 0;
}

void RenderWindow::SetRenderApplication(IRenderApplication* renderApplication) {
    m_renderApplication = renderApplication;
    m_renderApplication->Init();
}

int RenderWindow::DoRender() {
    // Game loop
    while (!glfwWindowShouldClose(m_window)) {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        m_renderApplication->DoRender();

        // Swap the screen buffers
        glfwSwapBuffers(m_window);
    }

    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}

void RenderWindow::SetKey(int key)
{
    m_renderApplication->SetKey(key);
}


void RenderWindow::glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    else
    {
        RenderWindow::GetInstance()->SetKey(key);
    }
}


