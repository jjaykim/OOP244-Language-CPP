//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop10_LAB
//==============================================
// cstring.cpp

#include "cstring.h"
namespace sdds
{
  // strLen: Calculate the length of the C-String in characters
  int strLen(const char *s)
  {
    // Declare Variable to store the length
    int length = 0;

    // Set the "while" loop to repeat until the corresponding index has a value
    while (s[length])
      length++;

    return length;
  }

  // strCpy: Cpies the srouce character string into the destination
  void strCpy(char *des, const char *src)
  {
    int i = 0;

    // Set the "while" loop to repeat until 'src' has a value the corresponding index
    while (src[i]) {
      // Copy the String from 'src' to 'des'
      des[i] = src[i];
      i++;
    }

    // Set the last index to be NULL value
    des[i] = '\0';
  }
}