//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop1_DIY
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
    {
      length++;
    }

    return length;
  }

  // strCpy: Cpies the srouce character string into the destination
  void strCpy(char *des, const char *src)
  {
    int i = 0;

    // Set the "while" loop to repeat until 'src' has a value the corresponding index
    while (src[i])
    {
      // Copy the String from 'src' to 'des'
      des[i] = src[i];
      i++;
    }

    // Set the last index to be NULL value
    des[i] = '\0';
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

      // Set the last index to be NULL value
    }
    des[i] = '\0';
  }

  // strCmp: Compares two C-strings
  int strCmp(const char *s1, const char *s2)
  {
    int i = 0, result = 0;
    bool flag = false;

    // Set the "while" loop to repeat until the comparison between "s1" and "s2" is complete
    while (!flag)
    {
      if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
      {
        result = s1[i] - s2[i];
        flag = true;
      }

      i++;
    }

    return result;
  }

  // strnCmp: Compares two C-strings upto "len" characters.
  int strnCmp(const char *s1, const char *s2, int len)
  {
    int i = 0, result = 0;
    bool flag = false;

    // Set the "while" loop to repeat until 'src' has a value the corresponding index
    // and the index count is less than "len"
    while (i < len && !flag)
    {
      if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
      {
        result = s1[i] - s2[i];
        flag = true;
      }

      i++;
    }

    // The case below is the same string if all conditions are not met
    return result;
  }

  // strStr: returns the address of first occurance of "str2" in "str1"
  const char *strStr(const char *str1, const char *str2)
  {
    int i = 0;
    const char *result = nullptr;
    bool flag = false;

    // Infinitie "while" loop until 'str1' has value
    // and only if "str1" length is longer than "str2"
    while (str1[i] && strLen(str1) > strLen(str2) && !flag)
    {
      // Check if 'str1' contains 'str2' using 'strnCmp' function
      if (strnCmp(&str1[i], str2, strLen(str2)) == 0)
      {
        result = &str1[i];
        flag = true;
      }
      i++;
    }

    // if no match is found, return nullptr
    return result;
  }

  // strCat: Concantinates "src" C-string to the end of "des"
  void strCat(char *des, const char *src)
  {
    int des_len = strLen(des);
    int counter = 0;

    // Infinitie "while" loop until 'src' has value
    while (src[counter])
    {
      // copy the characters from the last index of 'des'
      des[des_len] = src[counter];
      des_len++;
      counter++;
    }

    // Set the last index to be NULL value
    des[des_len] = '\0';
  }
} // namespace sdds