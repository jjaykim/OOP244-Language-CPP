/*
 < Citation and Sources >

Final Project Milestone 4
Module: IOAble
Filename: IOAble.h
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

#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H

#include <iostream>

namespace sdds
{
  // IOAble class is a pure virtual functions
  class IOAble
  {
  public:
    virtual std::ostream &csvWrite(std::ostream &ostr) const = 0;
    virtual std::istream &csvRead(std::istream &istr) = 0;
    virtual std::ostream &write(std::ostream &ostr) const = 0;
    virtual std::istream &read(std::istream &istr) = 0;
    virtual ~IOAble() {};
  };

  std::ostream &operator<<(std::ostream &ostr, const IOAble &src);
  std::istream &operator>>(std::istream &istr, IOAble &src);
}

#endif