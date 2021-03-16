//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop1_LAB
//==============================================
// File.h

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "ShoppingRec.h"

namespace sdds {

  // Function Prototypes:
  bool openFileForRead();
  bool openFileForOverwrite();
  void closeFile();
  bool freadShoppingRec(ShoppingRec* rec);
  void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif // !SDDS_FILE_H
