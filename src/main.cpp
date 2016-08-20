#include <GL/freeglut.h>

#include "include/glview.hpp"

class FirstView : public GLView {
 public:
  FirstView() : GLView("First view") {}

 protected:
   virtual void display() {
     glClear(GL_COLOR_BUFFER_BIT);

     glColor3ub(0xCA, 0xFF, 0xEE);
     glBegin(GL_TRIANGLES);
       glVertex2f(0.0f, 0.5f);
       glVertex2f(-0.5f, -0.5f);
       glVertex2f(0.5f, -0.5f);
     glEnd();

     glutSwapBuffers();
   }
};

class SecondView : public GLView {
 public:
  SecondView() : GLView("Second view") {}

 protected:
   virtual void display() {
     glClear(GL_COLOR_BUFFER_BIT);

     glColor3ub(0xCA, 0xFF, 0xEE);
     glBegin(GL_TRIANGLES);
       glVertex2f(0.0f, -0.5f);
       glVertex2f(0.5f, 0.5f);
       glVertex2f(-0.5f, 0.5f);
     glEnd();

     glutSwapBuffers();
   }
};

int main(int argc, char** argv) {
  FirstView first_view;
  SecondView second_view;

  // Start GLUT's internal loop. Exit by one of windows is closing.
  glutMainLoop();
  return 0;
}
