#include "findRplSym.hpp"

char* taskaev::countDifLetters(char* string)
{
  for (size_t i = 0; string[i] != '\0' ; i++)
  {
	if (string[i] == 'c') {
	  string[i] = 'b';
	}
  }
  return string;
}
