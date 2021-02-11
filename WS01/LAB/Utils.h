//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop1_LAB
//==============================================
// Utils.h

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {

  // Function Prototypes:
  void flushkeys();
  bool ValidYesResponse(char ch);
  bool yes();
  void readCstr(char cstr[], int len);
  int readInt(int min, int max);
}

#endif // !SDDS_UTILS_H
