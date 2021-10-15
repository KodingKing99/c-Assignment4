// Implementation file for assignment 4 :D
#include "sortutils.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
// #include <execution>
bool isEvan(int num) {
  if (num % 2 == 0) {
    return true;
  } else {
    return false;
  }
}
void initializeRawArrayFromStdArray(const SourceArray &source, int dest[]) {
  std::copy(source.begin(), source.end(), dest);
}
void timeRawArraySeq(SourceArray data) {
  using namespace std::chrono;
  duration<double> totalTime = steady_clock::duration::zero();
  for (int i = 0; i < HOW_MANY_TIMES; i++) {
    int raw[HOW_MANY_ELEMENTS];
    initializeRawArrayFromStdArray(data, raw);
    auto t0 = steady_clock::now();
    // std::sort(std::execution::seq, raw, raw + HOW_MANY_ELEMENTS);
    std::sort(raw, raw + HOW_MANY_ELEMENTS);
    auto t1 = steady_clock::now();
    totalTime += t1 - t0;
  }
  std::cout << "Sort took " << totalTime.count() << " seconds" << std::endl;
}
void timeRawArrayPar(SourceArray data) {
  using namespace std::chrono;
  duration<double> totalTime = steady_clock::duration::zero();
  for (int i = 0; i < HOW_MANY_TIMES; i++) {
    int raw[HOW_MANY_ELEMENTS];
    initializeRawArrayFromStdArray(data, raw);
    auto t0 = steady_clock::now();
    // std::sort(std::execution::par, raw, raw + HOW_MANY_ELEMENTS);
    std::sort(raw, raw + HOW_MANY_ELEMENTS);
    auto t1 = steady_clock::now();
    totalTime += t1 - t0;
  }
  std::cout << "Sort took " << totalTime.count() << " seconds" << std::endl;
}
void timeStdArraySeq(SourceArray data) {
  using namespace std::chrono;
  duration<double> totalTime = steady_clock::duration::zero();
  for (int i = 0; i < HOW_MANY_TIMES; i++) {
    std::array<int, HOW_MANY_ELEMENTS> stdArr;
    std::copy(data.begin(), data.end(), stdArr.begin());
    auto t0 = steady_clock::now();
    // std::sort(std::execution::seq, stdArr.begin(), stdArr.end());
    std::sort(stdArr.begin(), stdArr.end());
    auto t1 = steady_clock::now();
    totalTime += t1 - t0;
  }
  std::cout << "Sort took " << totalTime.count() << " seconds" << std::endl;
}
void timeStdArrayPar(SourceArray data) {
  using namespace std::chrono;
  duration<double> totalTime = steady_clock::duration::zero();
  for (int i = 0; i < HOW_MANY_TIMES; i++) {
    std::array<int, HOW_MANY_ELEMENTS> stdArr;
    std::copy(data.begin(), data.end(), stdArr.begin());
    auto t0 = steady_clock::now();
    // std::sort(std::execution::par, stdArr.begin(), stdArr.end());
    std::sort(stdArr.begin(), stdArr.end());
    auto t1 = steady_clock::now();
    totalTime += t1 - t0;
  }
  std::cout << "Sort took " << totalTime.count() << " seconds" << std::endl;
}
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
  std::cout << "Evaluating Raw Array.." << std::endl;
  std::cout << "Timing Sequentially..." << std::endl;
  timeRawArraySeq(random);
  timeRawArraySeq(sorted);
  timeRawArraySeq(reversed);
  timeRawArraySeq(organPipe);
  timeRawArraySeq(rotated);

  std::cout << "Timing Parallel..." << std::endl;
  timeRawArrayPar(random);
  timeRawArrayPar(sorted);
  timeRawArrayPar(reversed);
  timeRawArrayPar(organPipe);
  timeRawArrayPar(rotated);
}
void evaluateStdArray(const SourceArray &random, const SourceArray &sorted,
                      const SourceArray &reversed, const SourceArray &organPipe,
                      const SourceArray &rotated) {
  std::cout << "Evaluating Std Array.." << std::endl;
  std::cout << "Timing Sequentially..." << std::endl;
  timeStdArraySeq(random);
  timeStdArraySeq(sorted);
  timeStdArraySeq(reversed);
  timeStdArraySeq(organPipe);
  timeStdArraySeq(rotated);

  std::cout << "Timing Parallel..." << std::endl;
  timeStdArrayPar(random);
  timeStdArrayPar(sorted);
  timeStdArrayPar(reversed);
  timeStdArrayPar(organPipe);
  timeStdArrayPar(rotated);
}
void evaluateStdVector(const SourceArray &random, const SourceArray &sorted,
                       const SourceArray &reversed,
                       const SourceArray &organPipe,
                       const SourceArray &rotated) {
  std::cout << "doing evaluating raw vector.." << std::endl;
}
