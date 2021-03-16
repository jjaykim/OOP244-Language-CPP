//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop6_DIY
//==============================================
// Stats.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "cstring.h"
#include "Stats.h"

using namespace std;

namespace sdds
{
  // ============ private member function ============
  // Get the total number of values in the file
  void Stats::setNoOfList()
  {
    m_noOfList = 0;
    ifstream readFile(m_filename);
    string read_comma;

    if (readFile.is_open()) {
      // read the file, before meet comma
      while (getline(readFile, read_comma, ','))
        m_noOfList++;
    }
    else {
      delete[] m_filename;
      m_filename = nullptr;
    }
  }

  // Allocate dynamic memory and store values there
  void Stats::loadValue()
  {
    ifstream readFile(m_filename);
    char _delimiter;
    unsigned count = 0;

    if (m_eachValue != nullptr) {
      delete[] m_eachValue;
      m_eachValue = nullptr;
    }

    // dynamically allocate an array of values with the size kept in m_noOfList
    m_eachValue = new double[m_noOfList];

    if (readFile.is_open()) {
      // In a loop reads each value and comma
      while (readFile) {
        // Save the read value to m_eachValue in order
        readFile >> m_eachValue[count] >> _delimiter;
        count++;
      }
    }

    // make sure to update the value of m_noOfList to the actual number of values read
    m_noOfList = count;
  }

  // Read sub-file and save as main file
  void Stats::saveAs(const char *main_fName, const char *sub_fName) const
  {
    ifstream readFile(sub_fName);
    string readStr;

    if (readFile.is_open()) {
      readFile.seekg(0, std::ios::end); // positon of the character moves to the end
      unsigned size = readFile.tellg(); // get the position of the current character
      readStr.resize(size);             // resizes the string to a length
      readFile.seekg(0, std::ios::beg); // positon of the character moves to the beginning
      readFile.read(&readStr[0], size); // extract by the size and store on array pointed

      ofstream out(main_fName);
      out << readStr;
    }
  }

  // ============ public member function ============
  Stats::Stats(unsigned _colWidth, unsigned _numCol, unsigned _precision)
  {
    m_columnWidth = _colWidth;
    m_noOfColumns = _numCol;
    m_precision   = _precision;
    m_noOfList    = 0;
    m_sort        = NON_SORT;
  }

  Stats::Stats(const char *_filename, unsigned _colWidth, unsigned _numCol, unsigned _precision)
  {
    m_columnWidth = _colWidth;
    m_noOfColumns = _numCol;
    m_precision   = _precision;
    m_noOfList    = 0;
    m_sort        = NON_SORT;

    ifstream readFile(_filename);

    if (readFile.is_open()) {
      m_filename = new char[strLen(_filename) + 1];
      strCpy(m_filename, _filename);


      setNoOfList();
      loadValue();
    }
  }

  Stats::Stats(const Stats &src)
  {
    this->m_columnWidth = src.m_columnWidth;
    this->m_noOfColumns = src.m_noOfColumns;
    this->m_precision   = src.m_precision;
    this->m_noOfList    = src.m_noOfList;
    this->m_sort        = src.m_sort;

    // Deep copying
    if (this != &src) {
      if (src.m_eachValue && src.m_noOfList > 0) {
        m_filename = new char[strLen(m_prefix) + strLen(src.m_filename) + 1];
        strCpy(m_filename, m_prefix);
        strCat(m_filename, src.m_filename);

        saveAs(m_filename, src.m_filename);
        loadValue();
      }
    }
  }

  Stats &Stats::operator=(const Stats &src)
  {
    // Deep copying
    if (this != &src) {
      if (m_eachValue != nullptr) {
        delete[] m_eachValue;
        m_eachValue = nullptr;
      }

      if (src.m_eachValue && src.m_noOfList > 0) {
        this->m_columnWidth = src.m_columnWidth;
        this->m_noOfColumns = src.m_noOfColumns;
        this->m_precision   = src.m_precision;
        this->m_noOfList    = src.m_noOfList;
        this->m_sort        = src.m_sort;

        saveAs(m_filename, src.m_filename);
        loadValue();
      }
    }

    return *this;
  }

  Stats::~Stats()
  {
    if (m_filename != nullptr) {
      delete[] m_filename;
      m_filename = nullptr;
    }

    if (m_eachValue != nullptr) {
      delete[] m_eachValue;
      m_eachValue = nullptr;
    }
  }

  Stats::operator bool() const
  {
    return m_eachValue && m_filename;
  }

  double &Stats::operator[](unsigned idx)
  {
    if (m_noOfList > 0 && m_eachValue) {
      if (idx >= m_noOfList)
        idx %= m_noOfList;
    }
    // If the Stats object is empty, return the reference of a dummy reference
    else {
      idx = 0;
      m_eachValue = new double[idx + 1];
      m_eachValue[idx] = 0.00;
      cout.setf(ios::fixed);
      cout.precision(2);
    }
    return m_eachValue[idx];
  }

  double Stats::operator[](unsigned idx) const
  {
    double _result = 0.00;

    if (m_noOfList > 0 && m_eachValue) {
      if (idx >= m_noOfList)
        idx %= m_noOfList;

      _result = m_eachValue[idx];
    }
    // If the Stats object is empty, it should return 0.00
    else {
    cout.setf(ios::fixed);
    cout.precision(2);
    }

    return _result;
  }

  unsigned Stats::size() const
  {
    return m_noOfList;
  }

  const char *Stats::name() const
  {
    return m_filename;
  }

  // Display all values with a specified number of columns, column width and precision
  std::ostream &Stats::display(std::ostream &ostr) const
  {
    if (m_filename != nullptr && m_filename[0] != '\0')
    {
      ostr << m_filename << endl;

      ostr.fill('=');
      ostr.width(strLen(m_filename));
      ostr << '=' << endl << endl;

      ostr.fill(' ');
      ostr << fixed;
      ostr.precision(m_precision);

      for (unsigned i = 0; i < m_noOfList; i++) {
        ostr.width(m_columnWidth);
        ostr << m_eachValue[i];

        if (i != 0 && (i + 1) % m_noOfColumns == 0)
          ostr << endl;
        else if ((m_noOfList - i) == 1)
          ostr << endl;
      }
      ostr.unsetf(ios::fixed);

      ostr << "Total of " << m_noOfList << " listed!" << endl;
    }

    return ostr;
  }

  // displays the numbers that fall within a specific range
  unsigned Stats::occurrence(double min, double max, std::ostream &ostr) const
  {
    unsigned count = 0;

    if (m_noOfList > 0) {

      // Display values within a specific range
      ostr << fixed;
      ostr.precision(m_precision);
      ostr << endl;
      for (unsigned i = 0; i < m_noOfList; i++) {
        if (m_eachValue[i] >= min && m_eachValue[i] <= max) {
          ostr.width(m_columnWidth);
          ostr << m_eachValue[i];
          count++;

          if (count != 0 && (count + 1) % m_noOfColumns == 1)
            ostr << endl;
        }

    }

    ostr << endl;
    ostr << "Total of " << count << " numbers are between " << min << " and " << max << endl;
    }

    return count;
  }

  // Change sorting order based on input
  void Stats::sort(const bool ascending)
  {
    // Using a Boubble sort algorithms
    if (ascending) {
      for (unsigned i = 0; i < m_noOfList; i++) {
        for (unsigned j = 0; j < (m_noOfList - i - 1); j++) {
          if (m_eachValue[j] > m_eachValue[j + 1]) {
            double _temp = m_eachValue[j];
            m_eachValue[j] = m_eachValue[j + 1];
            m_eachValue[j + 1] = _temp;
          }
        }
      }
    }
    else {
      for (unsigned i = 0; i < m_noOfList; i++) {
        for (unsigned j = 0; j < (m_noOfList - i - 1); j++) {
          if (m_eachValue[j] < m_eachValue[j + 1]) {
            double _temp = m_eachValue[j];
            m_eachValue[j] = m_eachValue[j + 1];
            m_eachValue[j + 1] = _temp;
          }
        }
      }
    }
  }

  std::istream& Stats::getFile(std::istream &istr)
  {
    string _input;
    istr >> _input;

    m_filename = new char[strLen(_input.c_str()) + 1];
    strCpy(m_filename, _input.c_str());
    istr.ignore(32767, '\n');

    setNoOfList();
    loadValue();

    return istr;
  }

  // Receive the file name and read the value according to the conditions
  std::istream &operator>>(std::istream &istr, Stats &src)
  {
    return src.getFile(istr);
  }

  std::ostream &operator<<(std::ostream &ostr, const Stats &src)
  {
    return src.display(ostr);
  }
}