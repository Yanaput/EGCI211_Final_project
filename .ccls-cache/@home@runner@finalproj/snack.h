#ifndef snack_h
#define snack_h

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "animal.h"

using namespace std;

class Snack {
private:
  string name;
  double calories;

public:
  Snack(string _name, double _cal) : name(_name), calories(_cal) {
    set_info(_name, _cal);
  }
  ~Snack(){};

  void set_info(string _name, double _cal) {
    this->name = _name;
    if (_cal >= 0.0) {
      this->calories = _cal;
    } 
    else {
      cout << "Invalid calories entered. Setting calories to 0."
           << "\n";
      this->calories = 0.0;
    }
  }

  void print_info() const {
    cout << "Snack type : " << name << "\n";
    cout << fixed << setprecision(2) << "Calories : " << calories << "\n";
  }

  double get_cal() const { return calories; }

  string snack_name() const { return name; }

};

#endif