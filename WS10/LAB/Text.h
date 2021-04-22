//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop10_LAB
//==============================================
// Text.h

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>

namespace sdds {
  class Text {
    char *m_filename {nullptr};
    char *m_content {nullptr};
    int getFileLength() const;

  protected:
    const char &operator[](int index) const;

  public:
    Text(const char *filename = nullptr);
    Text(const Text &src);
    Text &operator=(const Text &src);

    virtual ~Text();
    void read();
    virtual void write(std::ostream &os) const;
  };

  std::ostream &operator<< (std::ostream &os, const Text &src);
}
#endif // !SDDS_PERSON_H__
