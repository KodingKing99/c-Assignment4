// #include "sortutils.cpp"
#include "sortutils.hpp"
#include <algorithm>
#include <iostream>
#include <random>
constexpr auto MIN_VALUE = -10'000'000;
constexpr auto MAX_VALUE = 10'000'000;
SourceArray generateMyRandomArray() {
  std::default_random_engine engine{0u};
  std::uniform_int_distribution<> dist{MIN_VALUE, MAX_VALUE};

  SourceArray array;
  std::generate(array.begin(), array.end(), [&] { return dist(engine); });
  return array;
}
void sortMyArray(SourceArray &array) { std::sort(array.begin(), array.end()); }
void reverseMyArray(SourceArray &array) {
  std::reverse(array.begin(), array.end());
}
void rotateMyArray(SourceArray &array) {
  std::rotate(array.begin(), (array.begin() + 1), array.end());
}
// void generateMy
int main() {
  std::cout << "Hello World" << std::endl;
  const auto randomArray = generateMyRandomArray();
  std::cout << "generated array: " << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << randomArray[i] << std::endl;
  }
  int intArray[HOW_MANY_ELEMENTS];
  initializeRawArrayFromStdArray(randomArray, intArray);
  std::cout << "int array after initialization: " << std::endl;

  for (int i = 0; i < 10; i++) {
    std::cout << intArray[i] << std::endl;
  }
  // orgainPipeStdArray(array);
  auto sortedArray = generateMyRandomArray();
  sortMyArray(sortedArray);
  std::cout << "sorted Array: " << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << sortedArray[i] << std::endl;
  }
  auto reversedArray = generateMyRandomArray();
  sortMyArray(reversedArray);
  reverseMyArray(reversedArray);
  std::cout << "reversed Array: " << std::endl;
  for (int i = 0; i < 100; i++) {
    std::cout << reversedArray[i] << std::endl;
  }
  auto rotatedArray = generateMyRandomArray();
  sortMyArray(rotatedArray);
  rotateMyArray(rotatedArray);
  std::cout << "rotated Array: " << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << rotatedArray[i] << std::endl;
  }
  // std::cou
  std::cout << "last element: " << rotatedArray[rotatedArray.size() - 1]
            << std::endl;
  auto organPipe = generateMyRandomArray();
  sortMyArray(organPipe);
  organPipeStdArray(organPipe);
  // auto rawArray = generateMyRandomArray();
  // initializeRawArrayFromStdArray(rawArray, )
  evaluateRawArray(randomArray, sortedArray, reversedArray, organPipe,
                   rotatedArray);

  return 0;
}
