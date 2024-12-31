#ifndef STRUCT_HPP
#define STRUCT_HPP


struct coordinate {
  int x;
  int y;
};

struct RGB {
  uint8_t r;
  uint8_t g;
  uint8_t b;

  RGB(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0)
    : r(red), g(green), b(blue) {
  }
};


#endif // STRUCT_HPP
