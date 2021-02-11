//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop1_LAB
//==============================================
// File.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "File.h"

namespace sdds {

  // Constant Value:
  const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";

  // Global Variable:
  FILE* sfptr = nullptr;

  // Functions:
  bool openFileForRead() {
    sfptr = fopen(SHOPPING_DATA_FILE, "r");
    return sfptr != NULL;
  }

  bool openFileForOverwrite() {
    sfptr = fopen(SHOPPING_DATA_FILE, "w");
    return sfptr != NULL;
  }

  void closeFile() {
    if (sfptr) fclose(sfptr);
  }

  bool freadShoppingRec(ShoppingRec* rec) {
    int flag = 0;
    bool success = fscanf(sfptr, "%[^,],%d,%d\n",
      rec->m_title, &rec->m_quantity, &flag) == 3;
    rec->m_bought = !!flag;
    return success;
  }

  void fwriteShoppintRec(const ShoppingRec* rec) {
    fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
  }

}
