//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop7_LAB
//==============================================
// Truck.h

#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H

#include <iostream>
#include "MotorVehicle.h"

namespace sdds
{
  class Truck : public MotorVehicle
  {
    double m_MaxCapacity{0.00};
    double m_CurrCapacity{0.00};

  public:
    Truck(){}
    Truck(const char *_license, int _year, double _capacity,
          const char *_address = nullptr);
    ~Truck(){}

    bool addCargo(const double cargo);
    bool unloadCargo();

    // Display the information of MotorVehicle
    std::ostream &write(std::ostream &os) const;

    // Receive new information from the user
    std::istream &read(std::istream &in);
  };
  std::ostream &operator<<(std::ostream &ostr, const Truck &src);
  std::istream &operator>>(std::istream &istr, Truck &src);
}

#endif