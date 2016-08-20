#ifndef INCLUDE_GLVIEW_H_
#define INCLUDE_GLVIEW_H_

#include <vector>

class GLView {
 public:
   GLView(const char* title);

   static void idle_display();

   static void reshape(int width, int height);

 protected:
   virtual void display() = 0;

 private:
   static std::vector<GLView*> glviews;
   int window_id;
};

#endif  // INCLUDE_GLVIEW_H_
