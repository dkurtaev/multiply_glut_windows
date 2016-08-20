#include <GL/freeglut.h>

void display_first();
void display_second();
void reshape(int width, int height);

int first_window_id;
int second_window_id;

int main(int argc, char** argv) {
  glutInit(&argc, argv);  // GLUT initialization.

  // First window initialization.
  glutInitWindowSize(324, 324);  // Width, height of window.
  glutInitWindowPosition(0, 0);  // (x, y) position of window from top-left.
  first_window_id = glutCreateWindow("First view");

  glutDisplayFunc(display_first);
  glutReshapeFunc(reshape);
  glutIdleFunc(display_first);

  // Second window initialization.
  glutInitWindowSize(324, 324);
  glutInitWindowPosition(500, 0);
  second_window_id = glutCreateWindow("Second view");

  glutDisplayFunc(display_second);
  glutReshapeFunc(reshape);
  glutIdleFunc(display_second);

  // Start GLUT's internal loop. Exit by one of windows is closing.
  glutMainLoop();
  return 0;
}

void display_first() {
  glutSetWindow(first_window_id);
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
  glutSetWindow(second_window_id);
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3ub(0xCA, 0xFF, 0xEE);
  glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
  glEnd();

  glutSwapBuffers();
}

void reshape(int width, int height) {
  glViewport(0, 0, width, height);
}
