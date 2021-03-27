//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop8_LAB
//==============================================
// Line.h

#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include "LblShape.h"

namespace sdds
{
  class Line : public LblShape
  {
    unsigned int m_length {0};

  public:
    Line() {}
    Line(const char *_label, int _length);
    virtual ~Line() {}

    // Override the base class's getSpecs virtual function
    void getSpecs(std::istream &istr);
    // Override the base class's draw virtual function
    void draw(std::ostream &ostr) const;
  };
}
#endif