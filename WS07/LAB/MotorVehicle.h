//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop7_LAB
//==============================================
// MotorVehicle.h

#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

#include <iostream>

namespace sdds
{
  class MotorVehicle
  {
    char m_license[9]{'\0'};
    char m_address[64]{'\0'};
    unsigned int m_year{0};

  public:
    MotorVehicle(){}
    MotorVehicle(const char *_license, int _year, const char *_location = "Factory");
    ~MotorVehicle(){}

    // moves the vehicle to the new address
    void moveTo(const char* _address);

    // Display the information of MotorVehicle
    std::ostream &write(std::ostream &os) const;

    // Receive new information from the user
    std::istream &read(std::istream &in);
  };

  std::ostream &operator<<(std::ostream &ostr, const MotorVehicle &src);
  std::istream &operator>>(std::istream &istr, MotorVehicle &src);
}
#endif