//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop1_DIY
//==============================================
// cstring.h

#ifndef SDDS_CSTRING_H
#define SDDS_CSTRING_H

namespace sdds {

  // Function Prototypes:

  // strLen: Calculate the length of the C-String in characters
  int strLen(const char *s);

  // strCpy: Cpies the srouce character string into the destination
  void strCpy(char *des, const char *src);

  // strnCpy: Copies the source character string into the destination upto "len" characters.
  //          The destination will be null terminated only if the number
  //          of the characters copied is less than "len"
  void strnCpy(char *des, const char *src, int len);

  // strCmp: Compares two C-strings
  int strCmp(const char *s1, const char *s2);

  // strnCmp: Compares two C-strings upto "len" characters.
  int strnCmp(const char *s1, const char *s2, int len);

  // strStr: returns the address of first occurance of "str2" in "str1"
  //         returns nullptr if no match is found
  const char *strStr(const char *str1, const char *str2);

  // strCat: Concantinates "src" C-string to the end of "des"
  void strCat(char *des, const char *src);
}
#endif