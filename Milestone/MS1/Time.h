//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Final Project Milestone 1
//==============================================
// Time.h

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <iostream>

    namespace sdds
{
  class Time
  {
    unsigned int m_min;

  public:
    Time &setToNow();
    Time(unsigned int min = 0);
    std::ostream &write(std::ostream &ostr) const;
    std::istream &read(std::istream &istr);

    Time &operator-=(const Time &D);
    Time operator-(const Time &D) const;
    Time &operator+=(const Time &D);
    Time operator+(const Time &D) const;

    Time &operator=(unsigned int val);
    Time &operator*=(unsigned int val);
    Time operator*(unsigned int val) const;
    Time &operator/=(unsigned int val);
    Time operator/(unsigned int val) const;

    operator unsigned int() const;
    operator int() const;
  };

  std::ostream &operator<<(std::ostream &ostr, const Time &D);
  std::istream &operator>>(std::istream &istr, Time &D);
}
#endif // !SDDS_TIME_H
