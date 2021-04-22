/*
 < Citation and Sources >

Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0

Author:	        Jungjoo Kim
Student Number: 162 641 195
Email:          jkim594@myseneca.ca
Section:        NCC

Revision History
-----------------------------------------------------------
Date       Reason
2021/3/27  First creating coding
2021/3/27  Completed coding
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"


using namespace std;

namespace sdds {
  // =========================== Public function ===========================
  // ******* Initialize member variables to corresponding values *******
  PreTriage::PreTriage(const char *dataFilename) :
    m_averCovidWait (15), m_averTriageWait (5),
    m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
    m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
    m_dataFilename = new char[strlen(dataFilename) + 1];
    strcpy(m_dataFilename, dataFilename);

    load();
  }

  // ******* Lineup patients are saved and dynamic memory is deleted *******
  PreTriage::~PreTriage() {
    ofstream out(m_dataFilename);

    if (out.is_open()) {
      cout << "Saving Average Wait Times," << endl;
      cout << "   COVID Test: " << m_averCovidWait << endl;
      cout << "   Triage: " << m_averTriageWait << endl;
      cout << "Saving m_lineup..." << endl;

      // The average COVID and Triage wait time is written in the first line
      out << m_averCovidWait << "," << m_averTriageWait << endl;

      // All the patients are written comma-separated in individual lines.
      for (int i = 0; i < m_lineupSize; i++) {
        m_lineup[i]->fileIO(true);
        cout << (i + 1) << "- " << *m_lineup[i] << endl;
        out << *m_lineup[i] << endl;
      }
    }
    else cout << "Failed to SAVE File !!" << endl;

    // Delete all Dynamic memory m_lineup and m_dataFilename
    for (int i = 0; i < m_lineupSize; i++) {
      delete m_lineup[i];
      m_lineup[i] = nullptr;
    }

    delete[] m_dataFilename;
    m_dataFilename = nullptr;

    cout << "done!" << endl;
  }

  // ******* Display General Hospital Pre-Triage Application Menu *******
  void PreTriage::run(void) {
    int _selectMenu;

    while (m_appMenu >> _selectMenu) {
      switch (_selectMenu) {
        case 1:
          reg();
          break;

        case 2:
          admit();
          break;

        default:
          break;
      }
    }
  }

  // =========================== Private function ===========================
  // ******* Registers a new patient *******
  void PreTriage::reg() {
    if (m_lineupSize == maxNoOfPatients) cout << "Line up full!" << endl;
    else {
      int _selectMenu;
      m_pMenu >> _selectMenu;

      // in the next available lineup pointer instantiate class according to the user's choice
      switch (_selectMenu) {
        case 1:
          m_lineup[m_lineupSize] = new CovidPatient();
          break;

        case 2:
          m_lineup[m_lineupSize] = new TriagePatient();
          break;

        default:
          break;
      }

      m_lineup[m_lineupSize]->setArrivalTime(); // set the patient's arrival time
      cout << "Please enter patient information: " << endl;
      m_lineup[m_lineupSize]->fileIO(false);
      cin >> *m_lineup[m_lineupSize]; // Call read function corresponding the type through IOAble class
      cout << endl;

      cout << "******************************************" << endl;
      cout << *m_lineup[m_lineupSize]; // Call write function corresponding the type through IOAble class
      cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
      cout << "******************************************" << endl << endl;
      m_lineupSize++;
    }
  }

  // ******* Calls the next patient in line to be admitted to the COVID test centre or Triage centre *******
  void PreTriage::admit() {
    int _selectMenu;
    int _found;
    char _type = '\0';

    // Determine the type of the patient to admit.
    m_pMenu >> _selectMenu;
    switch (_selectMenu) {
      case 1:
        _type = 'C';
        break;

      case 2:
        _type = 'T';
        break;

      default:
        break;
    }

    // if no patient is found, terminate the function
    _found = indexOfFirstInLine(_type);
    if (_found != -1) {
      cout << endl;
      cout << "******************************************" << endl;
      m_lineup[_found]->fileIO(false);
      cout << "Calling for " << *m_lineup[_found]; // Call write function corresponding the type through IOAble class
      cout << "******************************************" << endl << endl;
      setAverageWaitTime(*m_lineup[_found]);
      removePatientFromLineup(_found);
    }
  }

  // ******* Estimated wait time for that type of Patient (COVID or Triage) *******
  const Time PreTriage::getWaitTime(const Patient &p) const {
    unsigned int count = 0;

    // Find the number of Patients matching the type of the Patient Reference
    for (int i = 0; i < m_lineupSize; i++) {
      if (p == *m_lineup[i]) count++;
    }

    // Estimated wait time by the number of patients
    return Time(p) * count;
  }

  // ******* Adjusts the average wait time of that type of patient base on the admittance time of the patient *******
  void PreTriage::setAverageWaitTime(const Patient &p) {
    int _ptt = Time(p);

    // Determine what the actual object is using "==" defined in Patient base class
    if (p == 'C')
      m_averCovidWait = ((getTime() - _ptt) + (int(m_averCovidWait) * (p.number() - 1))) / p.number();
    else
      m_averTriageWait = ((getTime() - _ptt) + (int(m_averTriageWait) * (p.number() - 1))) / p.number();
  }

  // ******* Removes a Patient form the line up at a specific index and also removes it from memory *******
  void PreTriage::removePatientFromLineup(int index) {
    // Using removeDynamicElement template function
    removeDynamicElement<Patient>(m_lineup, index, m_lineupSize);
  }

  // ******* Finds the index of the first patient in line which matches the type argument *******
  int PreTriage::indexOfFirstInLine(char type) const {
    int i      = 0;
    int _find  = -1;

    // Determine what the actual object is using "==" defined in Patient base class
    while (i < m_lineupSize && _find == -1) {
      if (*m_lineup[i] == type) _find = i;
      i++;
    }
    return _find;
  }

  // ******* Loads the average wait times and the patient records from the data file and stores them in m_lineuup array *******
  void PreTriage::load() {
    int _index  = 0;
    char _comma = '\0';
    bool _exit  = false;

    cout << "Loading data..." << endl;

    ifstream readfile(m_dataFilename);

    if (!readfile) cout << "No data or bad data file!" << endl << endl;

    else {
      // 1. Read the covid average wait time
      readfile >> m_averCovidWait;

      // 2. no records in the file, do nothing
      if (!readfile) _exit = true;

      // 3. ignore the comma and read the triage average wait
      readfile >> _comma >> m_averTriageWait;

      // 4. ignore the newline
      readfile.ignore(32767, '\n');

      // 5. Do loop until the maximum number of patients or EOF or reading properly
      while (_index < maxNoOfPatients && !readfile.eof() && !_exit) {
        // 5-1. Creating a temporary a patient-pointer and single character
        char _type     = '\0';
        Patient *_temp = nullptr;

        // 5-2. Read the type and ignore the comma
        readfile >> _type >> _comma;

        // 5-3. Instantiate a Covid or Triage class according to types
        if (_type == 'C') _temp = new CovidPatient();
        else if (_type == 'T') _temp = new TriagePatient();

        // 5-4. If Instantiation happened, stores the record
        if (_temp != nullptr) {
          _temp->fileIO(true);
          readfile >> *_temp;       // Call read function corresponding the type through IOAble class
          _temp->fileIO(false);
          m_lineup[_index] = _temp; // Copy the patient pointer to the lineup array of pointers
          m_lineupSize++;           // Increase the lineup size
        }

        _index++;
      }

      if (!readfile.eof()) {
        cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
        cout << m_lineupSize << " Records imported..." << endl << endl;
      }
      else if (_exit)
        cout << "No data or bad data file!" << endl << endl;
      else
        cout << m_lineupSize << " Records imported..." << endl << endl;
    }
  }
}