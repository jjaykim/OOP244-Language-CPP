/*
 < Citation and Sources >

Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.h
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

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include "Patient.h"

namespace sdds
{
  class CovidPatient : public Patient
  {
  public:
    CovidPatient();

    // ======== pure virtual function overwrites ========
    char type() const;
    std::istream &csvRead(std::istream &istr);
    std::ostream &write(std::ostream &ostr) const;
    std::istream &read(std::istream &istr);
  };
}
#endif // !SDDS_COVIDPATIENT_H_
