//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop8_LAB
//==============================================
// LblShape.h

#ifndef SDDS_Lblshape_H_
#define SDDS_Lblshape_H_

#include "Shape.h"

namespace sdds
{
  class LblShape : public Shape
  {
    char *m_label {nullptr};

  protected:
    const char *label() const;

  public:
    LblShape() {}
    LblShape(const char *_label);
    virtual ~LblShape();

    // prevent copying
    LblShape(const LblShape &src) = delete;
    LblShape &operator=(const LblShape &src) = delete;

    // Override the base class's getSpecs pure virtual function
    void getSpecs(std::istream &istr);
  };
}
#endif