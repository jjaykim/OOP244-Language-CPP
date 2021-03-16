//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop2_DIY
//==============================================
// File.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
  FILE *fptr;

  bool openFile(const char filename[])
  {
    fptr = fopen(filename, "r");
    return fptr != NULL;
  }

  int noOfRecords()
  {
    int noOfRecs = 0;
    char ch;
    while (fscanf(fptr, "%c", &ch) == 1) {
      noOfRecs += (ch == '\n');
    }
    rewind(fptr);
    return noOfRecs;
  }

  void closeFile()
  {
    if (fptr)
      fclose(fptr);
  }

  // Create Functions:
  // Reads the postalcode
  bool read(char *code)
  {
    return fscanf(fptr, "%[^,],", code) == 1;
  }

  // Reads the population
  bool read(int &population)
  {
    return fscanf(fptr, "%d\n", &population) == 1;
  }

} // namespace sdds