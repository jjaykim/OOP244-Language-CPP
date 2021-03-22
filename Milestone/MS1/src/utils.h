//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Final Project Milestone 1
//==============================================
// utils.h

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_

#include <iostream>

namespace sdds
{
  extern bool debug; // making sdds::debug variable global to all the files
                     // which include: "utils.h"

  const int BUFFER_SIZE = 32767;

  // returns the time of day in minutes
  int getTime();

  // Performs a fool-proof integer entry from the console
  int getInt(const char *prompt = nullptr);

  // Performs a fool-proof integer entry from the console
  int getInt(int min, int max, const char *prompt = nullptr,
             const char *errorMessage = nullptr, bool showRangeAtError = true);

  char *getcstr(const char *prompt = nullptr, std::istream &istr = std::cin,
        char delimiter = '\n');
}
#endif // !SDDS_UTILS_H_
