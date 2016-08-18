#include <GL/freeglut.h>

void init();
void display();
void reshape(int width, int height);

int main(int argc, char** argv) {
  // GLUT initialization.
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

  // Window initialization.
  glutInitWindowSize(324, 324);  // Width, height of window.
  glutInitWindowPosition(0, 0);  // (x, y) position of window from top-left.
  int window_id = glutCreateWindow("Single view");

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

  glColor3ub(0xCA, 0xFF, 0xEE);  // Hex just for fun. Color is (202, 255, 238).
  glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
  glEnd();

  glutSwapBuffers();
}

void reshape(int width, int height) {
  glViewport(0, 0, width, height);
}
