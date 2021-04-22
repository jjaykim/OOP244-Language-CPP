/*
 < Citation and Sources >

Final Project Milestone 5
Module: IOAble
Filename: IOAble.cpp
Version 1.0

Author:	        Jungjoo Kim
Student Number: 162 641 195
Email:          jkim594@myseneca.ca
Section:        NCC

Revision History
-----------------------------------------------------------
Date       Reason
2021/3/19  First creating coding
2021/3/19  Completed coding
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include "IOAble.h"

using namespace std;

namespace sdds
{
  std::ostream &operator<<(std::ostream &ostr, const IOAble &src)
  {
    return src.write(ostr);
  }

  std::istream &operator>>(std::istream &istr, IOAble &src)
  {
    return src.read(istr);
  }
}