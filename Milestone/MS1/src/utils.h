/*
 < Citation and Sources >

Final Project Milestone 1
Module: Utils
Filename: utils.h
Version 1.0

Author:	        Jungjoo Kim
Student Number: 162 641 195
Email:          jkim594@myseneca.ca
Section:        NCC

Revision History
-----------------------------------------------------------
Date       Reason
2021/3/13  First crating coding
2021/3/14  Completed coding
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

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
