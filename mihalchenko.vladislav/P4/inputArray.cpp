#include "inputArray.hpp"
#include <algorithm>
#include <iostream>

size_t readArray::inputArray(std::istream & in, int * matrix, size_t s, size_t toRead)
{
  for (size_t i = 0; i < std::min(toRead, s); ++i)
  {
    if (!(in >> matrix[i]))
    {
      return i;
    }
    //std::cout << matrix[i] << "\t";
  }
  return std::min(toRead, s);
}
