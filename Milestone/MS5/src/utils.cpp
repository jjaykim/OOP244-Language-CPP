/*
 < Citation and Sources >

Final Project Milestone 5
Module: Utils
Filename: utils.cpp
Version 1.0

Author:	        Jungjoo Kim
Student Number: 162 641 195
Email:          jkim594@myseneca.ca
Section:        NCC

Revision History
-----------------------------------------------------------
Date       Reason
2021/3/13  First creating coding
2021/3/14  Completed coding
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#include "utils.h"
#include "Time.h"

using namespace std;

namespace sdds
{
  bool debug = false; // made global in utils.h

  int getTime()
  {
    int mins = -1;

    if (debug) {
      Time t(0);
      cout << "Enter current time: ";
      do {
        cin.clear();
        cin >> t; // needs extraction operator overloaded for Time
        if (!cin) {
          cout << "Invlid time, try agian (HH:MM): ";
          cin.clear();
        }
        else {
          mins = int(t);
        }

        cin.ignore(1000, '\n');
      } while (mins < 0);
    }
    else {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      mins = lt.tm_hour * 60 + lt.tm_min;
    }

    return mins;
  }

  int getInt(const char *prompt)
  {
    int _input;
    char _buffer;
    bool _flag = false;

    // displayed before the entry as a prompt
    if (prompt) cout << prompt;

    do {
      // If the user enters an invalid integer, display the ERROR message and clear buffer
      cin >> _input;

      if (!cin) {
        cout << "Bad integer value, try again: ";
        cin.clear();
        cin.ignore(BUFFER_SIZE, '\n');
      }
      else {
        // If the user enters any character after a valid integer, display the ERROR message and clear buffer
        cin.get(_buffer);

        if (_buffer != '\n') {
          cout << "Enter only an integer, try again: ";
          cin.clear();
          cin.ignore(BUFFER_SIZE, '\n');
        }
        else _flag = true;
      }
    } while (!_flag);

    return _input;
  }

  int getInt(int min, int max, const char *prompt,
             const char *errorMessage, bool showRangeAtError)
  {
    int _input;
    char _buffer;
    bool _flag = false;

    // displayed before the entry as a prompt
    if (prompt) cout << prompt;

    do {
      // If the user enters an invalid integer, display the ERROR message and clear buffer
      cin >> _input;

      if (!cin) {
        cout << "Bad integer value, try again: ";
        cin.clear();
        cin.ignore(BUFFER_SIZE, '\n');
      }
      else {
        // If the user enters any character after a valid integer,
        // display the ERROR message and clear buffer
        cin.get(_buffer);

        if (_buffer != '\n') {
          cout << "Enter only an integer, try again: ";
          cin.clear();
          cin.ignore(BUFFER_SIZE, '\n');
        }

        // If the value is out of the range specified,
        // display the ERROR message depending on the status of the errorMessage and showRangeAtError
        else if (_input < min || _input > max) {
          if (errorMessage) cout << errorMessage;
          if (showRangeAtError) cout << "[" << min << " <= value <= " << max << "]: ";
        }
        else _flag = true;
      }
    } while (!_flag);

    return _input;
  }

  char *getcstr(const char *prompt, std::istream &istr, char delimiter)
  {
    // Challenge without using the c+_+ string class
    char _input[BUFFER_SIZE]; // Temporary Character Array to Receive Input Values
    char *_outString;         // Character Pointer for Return
    int _size = 0;
    int i     = 0;

    // displayed before the entry as a prompt
    if (prompt) cout << prompt;

    // Receive a value before meeting a delimiter
    istr.getline(_input, BUFFER_SIZE, delimiter);

    // Calculating inputted the value length
    while (_input[_size] != '\0') _size++;

    // Dynamic memory allocation as long as calculated length + 1
    _outString = new char[_size + 1];

    // Copy the value from temporary array to character pointer
    while (_input[i] != '\0') {
      _outString[i] = _input[i];
      i++;
    }
    _outString[i] = '\0';

    return _outString;
  }
}