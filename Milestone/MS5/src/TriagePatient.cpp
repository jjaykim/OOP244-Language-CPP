/*
 < Citation and Sources >

Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.cpp
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

#include <string>
#include <cstring>
#include "TriagePatient.h"
#include "utils.h"

using namespace std;

namespace sdds {
  int nextTriageTicket = 1;

  TriagePatient::TriagePatient() : Patient(nextTriageTicket) {
    TP_symptoms = nullptr;
    nextTriageTicket++;
  }

  TriagePatient::~TriagePatient() {
    if (TP_symptoms) {
      delete[] TP_symptoms;
      TP_symptoms = nullptr;
    }
  }

  // ======== pure virtual function overwrites ========
  char TriagePatient::type() const {
    return 'T';
  }

  // Adds the symptoms to the comma-separated values of the patient.
  std::ostream &TriagePatient::csvWrite(std::ostream &ostr) const {
    Patient::csvWrite(ostr) << ',' << TP_symptoms;

    return ostr;
  }

  // Reads a comma-separated record of a triage Patient and sets the global ticket number
  std::istream &TriagePatient::csvRead(std::istream &istr) {
    string _temp;
    char _comma;

    if (TP_symptoms) {
      delete[] TP_symptoms;
      TP_symptoms = nullptr;
    }

    Patient::csvRead(istr);
    istr >>_comma;

    getline(istr, _temp, '\n');
    TP_symptoms = new char[strlen(_temp.c_str()) + 1];
    strcpy(TP_symptoms, _temp.c_str());

    nextTriageTicket = Patient::number() + 1;

    return istr;
  }

  // Write the patient in a comma-separated format or a descriptive format for screen or ticket
  std::ostream &TriagePatient::write(std::ostream &ostr) const {
    if (Patient::fileIO()) csvWrite(ostr);
    else {
      ostr << "TRIAGE" << endl;
      Patient::write(ostr) << endl;
      ostr << "Symptoms: " << TP_symptoms << endl;
    }
    return ostr;
  }

  // Read the patient in a comma-separated format from istream or
  // perform a fool-proof entry from the console
  std::istream &TriagePatient::read(std::istream &istr) {
    char *_temp;

    if (Patient::fileIO()) csvRead(istr);
    else {
      if (TP_symptoms) {
        delete[] TP_symptoms;
        TP_symptoms = nullptr;
      }

      Patient::read(istr);
      _temp = getcstr("Symptoms: ", istr);
      TP_symptoms = new char[strlen(_temp) + 1];
      strcpy(TP_symptoms, _temp);

      delete[] _temp;
    }
    return istr;
  }
}