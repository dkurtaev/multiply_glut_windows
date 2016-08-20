#ifndef INCLUDE_GLVIEW_H_
#define INCLUDE_GLVIEW_H_

class GLView {
 public:
   GLView(const char* title);

 private:
   static void display();

   static void reshape(int width, int height);
};

#endif  // INCLUDE_GLVIEW_H_
