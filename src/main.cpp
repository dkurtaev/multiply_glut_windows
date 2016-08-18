#include <GL/freeglut.h>

static const unsigned kInitViewWidth = 324;
static const unsigned kInitViewHeight = 324;
static const unsigned kInitViewPositionX = 0;
static const unsigned kInitViewPositionY = 0;
static const char* kViewTitle = "Single view";

void init();

void display();

void reshape(int width, int height);

int main(int argc, char** argv) {
  // GLUT initialization.
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

  // Window initialization.
  glutInitWindowSize(kInitViewWidth, kInitViewHeight);
  glutInitWindowPosition(kInitViewPositionX, kInitViewPositionY);
  int window_id = glutCreateWindow(kViewTitle);

  // Set callbacks.
  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutReshapeFunc(reshape);

  glutMainLoop();
  return 0;
}

void init() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers();
}

void reshape(int width, int height) {
  glViewport(0, 0, width, height);
}
