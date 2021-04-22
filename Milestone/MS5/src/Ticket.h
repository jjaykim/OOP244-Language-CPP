/*
 < Citation and Sources >

Final Project Milestone 5
Module: Ticket
Filename: Ticket.h
Version 1.0

Author:	        Jungjoo Kim
Student Number: 162 641 195
Email:          jkim594@myseneca.ca
Section:        NCC

Revision History
-----------------------------------------------------------
Date       Reason
2021/3/23  First creating coding Ticket module
2021/3/23  Completed coding Ticket module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_TICKET_H_
#define SDDS_TICKET_H_

#include "Time.h"
#include "IOAble.h"

namespace sdds
{
  class Ticket : public IOAble
  {
    Time m_time;  // The time the Ticket was issued
    int m_number; // The ticket number

  public:
    Ticket(int number);
    operator Time() const;
    int number() const;
    void resetTime();
    std::ostream &csvWrite(std::ostream &ostr) const;
    std::istream &csvRead(std::istream &istr);
    std::ostream &write(std::ostream &ostr) const;
    std::istream &read(std::istream &istr);
  };
}
#endif // !SDDS_TICKET_H_
