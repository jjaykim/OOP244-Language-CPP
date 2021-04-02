/*
 < Citation and Sources >

Final Project Milestone 4
Module: Patient
Filename: Patient.h
Version 1.0

Author:	        Jungjoo Kim
Student Number: 162 641 195
Email:          jkim594@myseneca.ca
Section:        NCC

Revision History
-----------------------------------------------------------
Date       Reason
2021/3/23  First creating coding Patient module
2021/3/23  Completed coding Patient module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_

#include "IOAble.h"
#include "Ticket.h"

namespace sdds
{
  class Patient : public IOAble
  {
    char *m_NameOfPatient {nullptr}; // to hold the name of the patient
    int m_NumOfOHIP {0};             // to hold the OHIP insurance 9 digits number
    Ticket m_ticket{0};              // A Ticket object to hold the ticket of the patient for the lineup
    bool m_IOFlag;                   // if read file -> true || read console -> false

  public:
    Patient(int ticketNumber = 0, bool fileIO = false);
    ~Patient();
    Patient(const Patient &) = delete;
    Patient &operator=(const Patient &) = delete;

    virtual char type() const = 0;

    const bool fileIO() const;
    void fileIO(bool _reset);
    bool operator==(const char _singleChar) const;
    bool operator==(const Patient &src) const;
    void setArrivalTime();
    operator Time() const;
    int number() const;

    // ======== pure virtual function overwrites ========
    std::ostream &csvWrite(std::ostream &ostr) const;
    std::istream &csvRead(std::istream &istr);
    std::ostream &write(std::ostream &ostr) const;
    std::istream &read(std::istream &istr);
  };
}
#endif