//////////
// Driver Code for assignment 4
// @author Nick Sorenson
// A02287085
/////////
#include "sortutils.hpp"

#include <algorithm>
#include <iostream>
#include <random>
constexpr auto MIN_VALUE = -10'000'000;
constexpr auto MAX_VALUE = 10'000'000;
SourceArray generateMyRandomArray()
{
    std::default_random_engine engine{ 0u };
    std::uniform_int_distribution<> dist{ MIN_VALUE, MAX_VALUE };
    SourceArray array;
    std::generate(array.begin(), array.end(), [&] { return dist(engine); });
    return array;
}
void sortMyArray(SourceArray& array)
{
    std::sort(array.begin(), array.end());
}
void reverseMyArray(SourceArray& array)
{
    std::reverse(array.begin(), array.end());
}
void rotateMyArray(SourceArray& array)
{
    std::rotate(array.begin(), (array.begin() + 1), array.end());
}
SourceArray sorted()
{
    SourceArray array = generateMyRandomArray();
    sortMyArray(array);
    return array;
}
SourceArray rotated()
{
    SourceArray array = generateMyRandomArray();
    sortMyArray(array);
    rotateMyArray(array);
    return array;
}
SourceArray reversed()
{
    SourceArray array = generateMyRandomArray();
    sortMyArray(array);
    reverseMyArray(array);
    return array;
}
SourceArray mkOrganPipe()
{
    auto organPipe = generateMyRandomArray();
    sortMyArray(organPipe);
    organPipeStdArray(organPipe);
    return organPipe;
}
int main()
{
    auto randomArray = generateMyRandomArray();
    auto sortedArray = sorted();
    auto reversedArray = reversed();
    auto rotatedArray = rotated();
    auto organPipe = mkOrganPipe();
    std::cout << "\n--- Raw Array performance ---\n" << std::endl;
    evaluateRawArray(randomArray, sortedArray, reversedArray, organPipe,
                     rotatedArray);
    std::cout << "\n--- std::array performance ---\n" << std::endl;
    evaluateStdArray(randomArray, sortedArray, reversedArray, organPipe,
                     rotatedArray);
    std::cout << "\n--- std::vector performance ---\n" << std::endl;
    evaluateStdVector(randomArray, sortedArray, reversedArray, organPipe,
                      rotatedArray);
    return 0;
}
