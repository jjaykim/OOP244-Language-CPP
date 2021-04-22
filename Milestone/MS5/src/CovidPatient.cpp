/*
 < Citation and Sources >

Final Project Milestone 5
Module: CovidPatient
Filename: CovidPatient.cpp
Version 1.0

Author:	        Jungjoo Kim
Student Number: 162 641 195
Email:          jkim594@myseneca.ca
Section:        NCC

Revision History
-----------------------------------------------------------
Date       Reason
2021/3/27  First creating coding CovidPatient module
2021/3/27  Completed coding CovidPatient module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include "CovidPatient.h"

using namespace std;

namespace sdds {
  int nextCovidTicket = 1;

  // Sets the Ticket number to the current global value
  CovidPatient::CovidPatient() : Patient(nextCovidTicket) {
    nextCovidTicket++;
  }

  // ======== pure virtual function overwrites ========
  char CovidPatient::type() const {
    return 'C';
  }

  // Reads a comma-separated record of a Patient and sets the global ticket number
  std::istream &CovidPatient::csvRead(std::istream &istr) {
    Patient::csvRead(istr);
    nextCovidTicket = Patient::number() + 1;
    istr.ignore();

    return istr;
  }

  // Write the patient in a comma-separated format or a descriptive format for screen or ticket.
  std::ostream &CovidPatient::write(std::ostream &ostr) const {
    if (Patient::fileIO()) Patient::csvWrite(ostr);
    else {
      ostr << "COVID TEST" << endl;
      Patient::write(ostr) << endl;
    }
    return ostr;
  }

  // Read the patient in a comma-separated format from istream or
  // perform a fool-proof entry from the console
  std::istream &CovidPatient::read(std::istream &istr) {
    Patient::fileIO() == true ? csvRead(istr) : Patient::read(istr);
    return istr;
  }
}