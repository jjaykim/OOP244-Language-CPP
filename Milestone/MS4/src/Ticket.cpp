/*
 < Citation and Sources >

Final Project Milestone 4
Module: Ticket
Filename: Ticket.cpp
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

#include "Ticket.h"

namespace sdds {
  Ticket::Ticket(int number) {
    m_number = number;
  }

  Ticket::operator Time() const {
    return m_time;
  }

  int Ticket::number() const {
    return m_number;
  }

  void Ticket::resetTime() {
    // Sets the Ticket time to the current time.
    m_time.setToNow();
  }

  std::ostream& Ticket::csvWrite(std::ostream& ostr) const {
    // Inserts comma-separated ticket number and time into ostream
    return ostr << m_number << "," << m_time;
  }

  std::istream& Ticket::csvRead(std::istream& istr) {
    // Extracts the ticket number and time in a comma-separated format from istream.
    istr >> m_number;
    istr.ignore();
    return istr >> m_time;
  }

  std::ostream& Ticket::write(std::ostream& ostr) const {
    // Inserts a ticket into the ostream to be displayed on the console.
    return ostr << "Ticket No: " << m_number << ", Issued at: " << m_time ;
  }

  std::istream& Ticket::read(std::istream& istr) {
    // Extracts the ticket information from istream.
    return csvRead(istr);
  }
}
