#include "include/glview.hpp"

#include <vector>

#include <GL/freeglut.h>

std::vector<GLView*> GLView::glviews;

GLView::GLView(const char* title) {
  if (glviews.empty()) {
    int argc = 0;
    glutInit(&argc, 0);  // GLUT initialization.
  }

  // Window initialization.
  glutInitWindowSize(324, 324);  // Width, height of window.
  glutInitWindowPosition(0, 0);  // (x, y) position of window from top-left.
  window_id = glutCreateWindow(title);
  glviews.push_back(this);

  // Set callbacks.
  glutDisplayFunc(display_all);
  glutReshapeFunc(reshape);
}

void GLView::display_all() {
  for (int i = 0; i < glviews.size(); ++i) {
    glutSetWindow(glviews[i]->window_id);
    glviews[i]->display();
  }
}

void GLView::reshape(int width, int height) {
  glViewport(0, 0, width, height);
}
