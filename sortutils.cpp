// Implementation file for assignment 4 :D
#include "sortutils.hpp"
#include <algorithm>
#include <iostream>
#include <random>
void initializeRawArrayFromStdArray(const SourceArray &source, int dest[]) {
  std::cout << "initalizing raw array from std array..." << std::endl;
  for (long unsigned int i = 0; i < source.size(); i++) {
    dest[i] = source[i];
  }
}
void orgainPipeStdArray(SourceArray &data) {
  std::cout << "doing organ pipe..." << std::endl;
}
void evaluateRawArray(const SourceArray &random, const SourceArray &sorted,
                      const SourceArray &reversed, const SourceArray &organPipe,
                      const SourceArray &rotated) {
  std::cout << "doing evaluating raw array.." << std::endl;
}
void evaluateStdArray(const SourceArray &random, const SourceArray &sorted,
                      const SourceArray &reversed, const SourceArray &organPipe,
                      const SourceArray &rotated) {
  std::cout << "doing evaluating std array.." << std::endl;
}
void evaluateStdVector(const SourceArray &random, const SourceArray &sorted,
                       const SourceArray &reversed,
                       const SourceArray &organPipe,
                       const SourceArray &rotated) {
  std::cout << "doing evaluating raw vector.." << std::endl;
}
