// #include "sortutils.cpp"
#include "sortutils.hpp"
#include <algorithm>
#include <iostream>
#include <random>
constexpr auto MIN_VALUE = -10'000'000;
constexpr auto MAX_VALUE = 10'000'000;
SourceArray generateMyRandomArray() {
  std::default_random_engine engine{};
  std::uniform_int_distribution<> dist{MIN_VALUE, MAX_VALUE};

  SourceArray array;
  std::generate(array.begin(), array.end(), [&] { return dist(engine); });
  return array;
}
int main() {
  std::cout << "Hello World" << std::endl;
  const auto array = generateMyRandomArray();
  std::cout << "generated array: " << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << array[i] << std::endl;
  }
  int intArray[HOW_MANY_ELEMENTS];
  initializeRawArrayFromStdArray(array, intArray);
  std::cout << "int array after initialization: " << std::endl;

  for (int i = 0; i < 10; i++) {
    std::cout << intArray[i] << std::endl;
  }
  return 0;
}
