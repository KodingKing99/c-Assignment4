// Implementation file for assignment 4 :D
#include "sortutils.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
bool isEvan(int num) {
  if (num % 2 == 0) {
    return true;
  } else {
    return false;
  }
}
void initializeRawArrayFromStdArray(const SourceArray &source, int dest[]) {
  std::cout << "initalizing raw array from std array..." << std::endl;
  std::copy(source.begin(), source.end(), dest);
}
// void sortRaw(const SourceArray &raw){
//   std::sort(std::begin(raw), std::end(raw));
// }
void organPipeStdArray(SourceArray &data) {
  std::cout << "doing organ pipe..." << std::endl;
  std::cout << "data size: " << data.size() << std::endl;
  int mid = data.size() / 2;
  std::cout << "mid point: " << mid << " data at mid: " << data[mid]
            << std::endl;
  // auto myIterator = data.begin() + mid;

  if (isEvan(mid)) {

    // std::reverse(data.begin() + mid, data.end());
    std::reverse_copy(data.begin(), data.begin() + mid, data.begin() + mid);
  } else {
    // std::reverse(data.begin() + (mid + 1), data.end());
    std::reverse_copy(data.begin(), data.begin() + mid, data.begin() + mid + 1);
  }
  std::cout << "Organ Pipe: " << std::endl;
  for (int i = mid - 10; i < mid + 10; i++) {
    std::cout << data[i] << std::endl;
  }
}
void evaluateRawArray(const SourceArray &random, const SourceArray &sorted,
                      const SourceArray &reversed, const SourceArray &organPipe,
                      const SourceArray &rotated) {
  std::cout << "doing evaluating raw array.." << std::endl;
  // using namespace std::chrono;
  // auto begin = steady_clock::now();
  // std::cout << "sorting random." << std::endl;
  // sortRaw(random);

  // auto t0 = steady_clock::now();
  // std::cout << "sorting random." << std::endl;
  // sortRaw(sorted);
  // auto t1 = steady_clock::now();
  // std::cout << "sorting reversed" << std::endl;
  // sortRaw(reversed);
  // auto t2 = steady_clock::now();
  // std::cout << "sorting organPipe." << std::endl;
  // sortRaw(organPipe);
  // auto t3 = steady_clock::now();
  // std::cout << "sorting rotated." << std::endl;
  // sortRaw(rotated);
  // auto t4 = steady_clock::now();
  // auto duration0 = nanoseconds(t0 - begin);
  // auto duration1 = nanoseconds(t1 - t0);
  // auto duration2 = nanoseconds(t2 - t1);
  // auto duration3 = nanoseconds(t3 - t2);
  // auto duration4 = nanoseconds(t4 - t3);
  // std::cout << "duration for random: " << duration0.count() <<std::endl;
  // std::cout << "duration for random: " << duration1.count() << std::endl;
  // std::cout << "duration for random: " << duration2.count() <<std::endl;
  // std::cout << "duration for random: " << duration3.count() <<std::endl;
  // std::cout << "duration for random: " << duration4.count() <<std::endl;
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
