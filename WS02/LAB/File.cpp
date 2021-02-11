//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop2_LAB
//==============================================
// File.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include "File.h"

namespace sdds
{
  // global variable:
  FILE *fptr;

  // Prototype:
  // openFile: Opens the data file for reading
  bool openFile(const char filename[])
  {
    fptr = fopen(filename, "r");
    return fptr != NULL;
  }

  // noOfRecords: Returns an integer that is the number of recoreds in the file
  int noOfRecords()
  {
    int noOfRecs = 0;
    char ch;
    while (fscanf(fptr, "%c", &ch) == 1)
    {
      noOfRecs += (ch == '\n');
    }
    rewind(fptr);
    return noOfRecs;
  }

  // closeFile: Closes the data file
  void closeFile()
  {
    if (fptr)
      fclose(fptr);
  }

  // TODO: read functions go here
  // Reads the name of the employee | Accepts as a parameter the address of an array of characters
  bool read(char *empName)
  {
    return fscanf(fptr, "%[^\n]\n", empName) == 1;
  }

  // Reads employee number | Accepts as a parameter a reference to an integer
  bool read(int &empNumber)
  {
    return fscanf(fptr, "%d,", &empNumber) == 1;
  }

  // Reads the employee salary | Acceptes as a parameter a reference to an floating point number
  // in double precision
  bool read(double &empSalary)
  {
    return fscanf(fptr, "%lf,", &empSalary) == 1;
  }
} // namespace sdds