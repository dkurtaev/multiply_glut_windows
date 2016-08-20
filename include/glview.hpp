#ifndef INCLUDE_GLVIEW_HPP_
#define INCLUDE_GLVIEW_HPP_

#include <vector>

class GLView {
 public:
   GLView(const char* title);

 protected:
   virtual void display() = 0;

 private:
   static void display_all();

   static std::vector<GLView*> glviews;
   int window_id;
};

#endif  // INCLUDE_GLVIEW_HPP_
