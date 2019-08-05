#include "GUI/RenderWindow.h"
#include "RenderApplications/TriangleRenderer.h"

using namespace OpenGlApplication;


void StartTriangleRenderer() {
    //TriangleRenderer* renderer = new TriangleRenderer();
    TriangleRenderer* renderer = new TriangleRenderer();

    //RenderWindow window;

    if (RenderWindow::GetInstance()->InitGL() > -1) {

        RenderWindow::GetInstance()->SetRenderApplication(renderer);

        RenderWindow::GetInstance()->DoRender();
    }

    delete renderer;
}


int main() {

    StartTriangleRenderer();

}

