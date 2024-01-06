#include <iostream>
#include <cstddef>
#include "functions.hpp"

int main()
{
  try
  {
    char *str1 = new char [1000];
    size_t len1 = zheleznyakov::readLine(str1);
    const char *str2 = "abc ef";
    size_t len2 = 6;
    char *dest = new char [1000];
    size_t destSize = zheleznyakov::findNonDuplicateChars(dest, str1, str2, len1, len2);
    for (size_t i = 0; i < destSize; i++)
    {
      std::cout << dest[i];
    }
    std::cout << '\n';
    delete[] str1;
    delete[] dest;
    return 0;
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
