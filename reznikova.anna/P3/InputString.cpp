#include <iostream>
#include "InputString.hpp"

char * reznikova::inputString(std::istream & in, size_t & size, size_t & add_size)
{
  char * string = new char[size]();
  char chr = 0;
  size_t read = 0;
  in >> std::noskipws;

  while (in >> chr)
  {
    if (read == (size-1))
    {
      char * newstring = nullptr;
      try
      {
        newstring = new char[size + add_size]();
      }
      catch (const std::bad_alloc & e)
      {
        delete [] string;
        throw std::runtime_error("bad_alloc error");
      }

      for (size_t i = 0; i < size; i++)
      {
        newstring[i] = string[i];
      }
      delete [] string;
      string = newstring;
      size += add_size;
    }
    if  (chr == '\n')
    {
      size = size - add_size + read;
      break;
    }
    string[read++] = chr;
  }

  string[size == 0 ? size : size - 1] = '\0';
  if (!string[0])
  {
    delete [] string;
    throw std::runtime_error("empty input");
  }

  in >> std::skipws;
  return string;
}
