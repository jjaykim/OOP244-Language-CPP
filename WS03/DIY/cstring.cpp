//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop3_DIY
//==============================================

#include "cstring.h"
namespace sdds {
  // strLen: Calculate the length of the C-String in characters
  int strLen(const char *s)
  {
    // Declare Variable to store the length
    int length = 0;

    // Set the "while" loop to repeat until the corresponding index has a value
    while (s[length])
    {
      length++;
    }

    return length;
  }

  // strnCpy: Copies the source character string into the destination upto "len" characters.
  void strnCpy(char *des, const char *src, int len)
  {
    int i = 0;

    if (strLen(src) >= len)
    {
      // Set the "while" loop to copy the 'src' as long as 'len'
      while (i < len)
      {
        des[i] = src[i];
        i++;
      }
    }
    else
    {
      // Set the "while" loop to copy the 'src' as long as the length of 'src'
      while (i < strLen(src))
      {
        des[i] = src[i];
        i++;
      }
    }
    // Set the last index to be NULL value
    des[i] = '\0';
  }
}