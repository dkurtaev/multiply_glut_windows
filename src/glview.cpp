#include "include/glview.hpp"

#include <GL/freeglut.h>

GLView::GLView(const char* title) {
  // GLUT initialization.
  int argc = 0;
  glutInit(&argc, 0);

  // Window initialization.
  glutInitWindowSize(324, 324);  // Width, height of window.
  glutInitWindowPosition(0, 0);  // (x, y) position of window from top-left.
  int window_id = glutCreateWindow(title);

  // Set callbacks.
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
}

void GLView::display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3ub(0xCA, 0xFF, 0xEE);  // Hex just for fun. Color is (202, 255, 238).
  glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
  glEnd();

  glutSwapBuffers();
}

void GLView::reshape(int width, int height) {
  glViewport(0, 0, width, height);
}
