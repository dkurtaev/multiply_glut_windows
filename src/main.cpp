#include <GL/freeglut.h>

void display_first();
void display_second();

int main(int argc, char** argv) {
  glutInit(&argc, argv);  // GLUT initialization.

  // First window initialization.
  glutInitWindowSize(324, 324);  // Width, height of window.
  glutInitWindowPosition(0, 0);  // (x, y) position of window from top-left.
  glutCreateWindow("First view");

  glutDisplayFunc(display_first);

  // Second window initialization.
  glutInitWindowSize(324, 324);
  glutInitWindowPosition(500, 0);
  glutCreateWindow("Second view");

  glutDisplayFunc(display_second);

  // Start GLUT's internal loop. Exit by one of windows is closing.
  glutMainLoop();
  return 0;
}

void display_first() {
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3ub(0xCA, 0xFF, 0xEE);
  glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
  glEnd();

  glutSwapBuffers();
}

void display_second() {
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3ub(0xCA, 0xFF, 0xEE);
  glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
  glEnd();

  glutSwapBuffers();
}
