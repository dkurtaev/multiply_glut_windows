#include "include/glview.hpp"

#include <vector>

#include <GL/freeglut.h>

std::vector<GLView*> GLView::glviews;

GLView::GLView(const char* title, GLView* parent) {
  if (glviews.empty()) {
    int argc = 0;
    glutInit(&argc, 0);  // GLUT initialization.
  }

  // Window initialization.
  if (parent != 0) {
    // Receive parent's id, x, y, width and height. Subwindows has not titles.
    window_id = glutCreateSubWindow(parent->window_id, 0, 0, 128, 128);
  } else {
    glutInitWindowSize(324, 324);  // Width, height of window.
    glutInitWindowPosition(0, 0);  // (x, y) position of window from top-left.
    window_id = glutCreateWindow(title);
  }
  glviews.push_back(this);

  glutDisplayFunc(display_all);  // Set callback.
}

void GLView::display_all() {
  for (int i = 0; i < glviews.size(); ++i) {
    glutSetWindow(glviews[i]->window_id);
    glviews[i]->display();
  }
}
