#include <GL/freeglut.h>

#include "include/glview.hpp"

int main(int argc, char** argv) {
  GLView glview("Single view");

  // Start GLUT's internal loop. Exit by window closing.
  glutMainLoop();
  return 0;
}
