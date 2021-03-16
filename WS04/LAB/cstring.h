//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop4_LAB
//==============================================
// cstring.h

#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_
namespace sdds {
  // strLen: Calculate the length of the C-String in characters
  int strLen(const char *s);
  // strCpy: Cpies the srouce character string into the destination
  void strCpy(char *des, const char *src);
  // strCmp: Compares two C-strings
  int strCmp(const char *s1, const char *s2);
}
#endif // !SDDS_CSTRING_H_
