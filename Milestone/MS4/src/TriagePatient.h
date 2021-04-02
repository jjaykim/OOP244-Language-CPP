/*
 < Citation and Sources >

Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.h
Version 1.0

Author:	        Jungjoo Kim
Student Number: 162 641 195
Email:          jkim594@myseneca.ca
Section:        NCC

Revision History
-----------------------------------------------------------
Date       Reason
2021/3/27  First creating coding TriagePatient module
2021/3/27  Completed coding TriagePatient module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include "Patient.h"

namespace sdds
{
  class TriagePatient : public Patient
  {
    char *TP_symptoms;

  public:
    TriagePatient();
    ~TriagePatient();

    // ======== pure virtual function overwrites ========
    char type() const;
    std::ostream &csvWrite(std::ostream &ostr) const;
    std::istream &csvRead(std::istream &istr);
    std::ostream &write(std::ostream &ostr) const;
    std::istream &read(std::istream &istr);
  };
}
#endif // !SDDS_TRIAGEPATIENT_H
