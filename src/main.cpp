//
//
//#define STB_IMAGE_IMPLEMENTATION
//#define STB_IMAGE_WRITE_IMPLEMENTATION
//
//
//#include "../include/common/CommonHeader.hpp"
//
//#include "../include/common/stb/stb_image.h"
//#include "../include/common/stb/stb_image_write.h"
//
//#include "../include/common/filter/Filter.cpp"
//
//#include "../include/types/types.hpp"
//
//#include "../include/struct/struct.hpp"
//
//#include <vector>
//#include <unordered_map>
//
//// Pixel representation of digits
//std::unordered_map<char, std::vector<std::vector<int>>> digitPatterns = {
//    {'0', {
//        {1, 1, 1},
//        {1, 0, 1},
//        {1, 0, 1},
//        {1, 0, 1},
//        {1, 1, 1}
//    }},
//    {'1', {
//        {0, 1, 0},
//        {1, 1, 0},
//        {0, 1, 0},
//        {0, 1, 0},
//        {1, 1, 1}
//    }},
//    {'2', {
//        {1, 1, 1},
//        {0, 0, 1},
//        {1, 1, 1},
//        {1, 0, 0},
//        {1, 1, 1}
//    }},
//  // Add patterns for 3-9 similarly
//};
//
//void drawNumber(
//  std::vector<std::vector<RGB>>& canvas,
//  int x, int y, char number,
//  RGB foreground, RGB background
//) {
//  // Validate number
//  if (digitPatterns.find(number) == digitPatterns.end()) {
//    std::cerr << "Error: Unsupported digit '" << number << "'.\n";
//    return;
//  }
//
//  // Get the digit's pattern
//  const auto& pattern = digitPatterns[number];
//
//  // Draw the pattern on the canvas
//  for (int i = 0; i < pattern.size(); ++i) {
//    for (int j = 0; j < pattern[i].size(); ++j) {
//      int newY = y + i;
//      int newX = x + j;
//
//      // Ensure within bounds of canvas
//      if (newY >= 0 && newY < canvas.size() && newX >= 0 && newX < canvas[0].size()) {
//        canvas[newY][newX] = pattern[i][j] ? foreground : background;
//      }
//    }
//  }
//}
//
//
//int main() {
//
//  Filter filter;
//
//  int width = 500;
//  int height = 500;
//  int gridSpacing = 50;
//
//  // Create canvas of 1100 x 1100px
//  auto mycanvas = filter.createCanvas(width, height);
//
//
//  for (int i = 0; i < height;++i) { 
//    for (int j = 0; j < width; j += gridSpacing) {
//      mycanvas[i][j].r = 0;
//      mycanvas[i][j].g = 0;
//      mycanvas[i][j].b = 0;
//
//    }
//  }
//
//  for (int i = 0; i < height;i+= gridSpacing) {
//    for (int j = 0; j < width; ++j) {
//      mycanvas[i][j].r = 0;
//      mycanvas[i][j].g = 0;
//      mycanvas[i][j].b = 0;
//    }
//  }
//
//  // Colors for numbers
//  RGB foreground = { 255, 0, 0 }; // Red
//  RGB background = { 255, 255, 255 }; // White
//
//  // Draw numbers in a loop
//  int startX = 100, startY = 100, spacing = 10;
//  std::string numbersToDraw = "120"; // Example: Draw 1, 2, 0
//  for (size_t i = 0; i < numbersToDraw.size(); ++i) {
//    drawNumber(mycanvas, startX + i * (3 + spacing), startY, numbersToDraw[i], foreground, background);
//  }
//
//
//
//  filter.saveToPNG(mycanvas, width, height, "grid.png");
//
//  cout << "Save success\n";
//
//  return 0;
//}
//

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../include/common/CommonHeader.hpp"
#include "../include/common/stb/stb_image.h"
#include "../include/common/stb/stb_image_write.h"
#include "../include/common/filter/Filter.cpp"
#include "../include/types/types.hpp"
#include "../include/struct/struct.hpp"

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

// Pixel representation of digits
std::unordered_map<char, std::vector<std::vector<int>>> digitPatterns = {
    {'0', {
        {1, 1, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1}
    }},
    {'1', {
        {0, 1, 0},
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 0},
        {1, 1, 1}
    }},
    {'2', {
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1}
    }},
    {'3', {
        {1, 1, 1},
        {0, 0, 1},
        {0, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    }},
    {'4', {
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1}
    }},
    {'5', {
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    }},
    {'6', {
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    }},
    {'7', {
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 1, 0},
        {0, 1, 0}
    }},
    {'8', {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    }},
    {'9', {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    }},
};


void drawNumber(
  std::vector<std::vector<RGB>>& canvas,
  int x, int y, char number,
  RGB foreground, RGB background
) {
  // Validate number
  if (digitPatterns.find(number) == digitPatterns.end()) {
    std::cerr << "Error: Unsupported digit '" << number << "'.\n";
    return;
  }

  // Get the digit's pattern
  const auto& pattern = digitPatterns[number];

  // Draw the pattern on the canvas
  for (int i = 0; i < pattern.size(); ++i) {
    for (int j = 0; j < pattern[i].size(); ++j) {
      int newY = y + i;
      int newX = x + j;

      // Ensure within bounds of canvas
      if (newY >= 0 && newY < canvas.size() && newX >= 0 && newX < canvas[0].size()) {
        canvas[newY][newX] = pattern[i][j] ? foreground : background;
      }
    }
  }
}

int main() {
  Filter filter;

  int width = 1000;
  int height = 1000;
  int gridSpacing = 50;

  // Create canvas
  auto mycanvas = filter.createCanvas(width, height);

  // Draw grid
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; j += gridSpacing) {
      mycanvas[i][j] = { 0, 0, 0 }; // Black
    }
  }
  for (int i = 0; i < height; i += gridSpacing) {
    for (int j = 0; j < width; ++j) {
      mycanvas[i][j] = { 0, 0, 0 }; // Black
    }
  }

  // Colors for numbers
  RGB foreground = { 255, 0, 0 }; // Red
  RGB background = { 255, 255, 255 }; // White

  // Draw numbers at grid intersections
  cout << "hello \n";
  int counter = 0;
  for (int i = height; i > 0; i -= gridSpacing) {
    cout << "hello \n";

    cout << (int)i << '\n';
    //for (int j = 0; j < width; j += gridSpacing) {
      // Convert counter to string and draw each digit
      std::string number = std::to_string(counter++);
      int offsetX = 0;
      for (char digit : number) {
        drawNumber(mycanvas, 10 + offsetX, i-10, digit, foreground, background);
        offsetX += 4; // Adjust spacing between digits
      }
    //}
  }

  int counter1 = 0;
  for (int i = 0; i < width; i += gridSpacing) {
    cout << "hello \n";

    cout << (int)i << '\n';
    //for (int j = 0; j < width; j += gridSpacing) {
      // Convert counter to string and draw each digit
    std::string number = std::to_string(counter1++);
    int offsetX = 0;
    for (char digit : number) {
      drawNumber(mycanvas,  i+10, height + offsetX - 10, digit, foreground, background);
      offsetX += 4; // Adjust spacing between digits
    }
    //}
  }

  // Save canvas to PNG
  filter.saveToPNG(mycanvas, width, height, "grid_with_numbers.png");

  std::cout << "Save success\n";

  return 0;
}
