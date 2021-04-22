/*
 < Citation and Sources >

Final Project Milestone 4
Module: Patient
Filename: Patient.cpp
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

#include <string>
#include <cstring>
#include "Patient.h"
#include "utils.h"

using namespace std;

namespace sdds
{
  Patient::Patient(int ticketNumber, bool fileIO) {
    m_ticket = ticketNumber;
    m_IOFlag = fileIO;
  }

  Patient::~Patient() {
    if (m_NameOfPatient) {
      delete[] m_NameOfPatient;
      m_NameOfPatient = nullptr;
    }
  }

  const bool Patient::fileIO() const {
    return m_IOFlag;
  }

  void Patient::fileIO(bool _reset) {
    m_IOFlag = _reset;
  }

  bool Patient::operator==(const char _singleChar) const {
    // Compare the current object with an incoming single characte
    return this->type() == _singleChar;
  }

  bool Patient::operator==(const Patient &src) const {
    // Compare the current object to another patient
    return this->type() == src.type();
  }

  void Patient::setArrivalTime() {
    // Sets the time of the ticket of the patient to the current time
    m_ticket.resetTime();
  }

  Patient::operator Time() const {
    // return the time of the ticket
    return Time(m_ticket);
  }


  int Patient::number() const {
    return m_ticket.number();
  }

  std::ostream& Patient::csvWrite(std::ostream &ostr) const {
    // Inserts the following values into the ostream in a comma-separated format
    ostr << this->type() << ',' << m_NameOfPatient << ',' << m_NumOfOHIP << ',';
    m_ticket.csvWrite(ostr);

    return ostr;
  }

  std::istream& Patient::csvRead(std::istream &istr) {
    string temp;
    char _comma;

    // Read the name of the patient up to the comma
    getline(istr, temp, ',');

    // Deleted before the allocation to guarantee there is no memory leak
    if (m_NameOfPatient) {
      delete[] m_NameOfPatient;
      m_NameOfPatient = nullptr;
    }

    m_NameOfPatient = new char[strlen(temp.c_str()) + 1];
    strcpy(m_NameOfPatient, temp.c_str());

    // Extract an integer from istream into the OHIP member variable and discard the comma
    istr >> m_NumOfOHIP >> _comma;

    // Extraction by calling the csvRead of the member ticket object
    m_ticket.csvRead(istr);

    return istr;
  }

  std::ostream& Patient::write(std::ostream &ostr) const {
    // Inserts the patient information into the ostream to be displayed on the console
    ostr << "Ticket No: " << m_ticket.number() << ", Issued at: " << Time(*this) << endl;

    // insert the name up to 25 character
    if (strlen(m_NameOfPatient) > 25) {
      for (int i = 0; i < 25; i++)
        ostr << m_NameOfPatient[i];
    }
    else ostr << m_NameOfPatient;

    ostr << ", OHIP: " << m_NumOfOHIP;

    return ostr;
  }

  std::istream& Patient::read(std::istream &istr) {
    // Extracts the ticket information from the console
    char *temp = getcstr("Name: ", istr);

    // Deleted before the allocation to guarantee there is no memory leak
    if (m_NameOfPatient) {
      delete[] m_NameOfPatient;
      m_NameOfPatient = nullptr;
    }

    // Allocate dynamically memory up to inputted the value length
    m_NameOfPatient = new char[strlen(temp) + 1];
    strcpy(m_NameOfPatient, temp);

    // Delete allocated dynamic memory when input is received
    delete[] temp;

    // Extract the 9 digit OHIP number
    m_NumOfOHIP = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ");

    return istr;
  }
}