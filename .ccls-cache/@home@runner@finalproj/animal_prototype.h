#ifndef animalprototype_h
#define animalprototype_h

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "snack.h"

using namespace std;

enum AnimalType {
  PIG,
  CHICKEN,
  COW,
  SHEEP
}; // https://www.programiz.com/cpp-programming/enumeration

class Animal {
private:
  string name;
  AnimalType type;
  unsigned int age;
  double weight;

  // linked lsit
  Animal *next;
  Animal *prev;

public:
  Animal(unsigned int _age, double _weight, AnimalType _type, const string &_name = "Unknown"){
    this->age = _age;
    this->weight = _weight;
    this->type = _type;
    this->name = _name;

    this->next = nullptr;
    this->prev = nullptr;
  }

  // virtual function is the function in main class that will be used in the
  // derived class
  ~Animal(){};

  void set_info(AnimalType _type, unsigned int _age, double _weight, const string &_name) {
    this->type = _type;
    if (_age >= 0) {
      this->age = _age;
    } 
    else {
      cout << "Invalid age entered. Setting age to 0." << endl;
      age = 0;
    }

    if (_weight >= 0) {
      this->weight = _weight;
    } 
    else {
      cout << "Invalid weight entered. Setting weight to 0." << endl;
      this->weight = 0.0;
    }

    this->name = _name;
  }

  AnimalType get_emumtype() const { return type; }

  string get_type() const { return type_to_str(type); }

  string type_to_str(AnimalType _type) const {
    switch (_type) {
    case CHICKEN:
      return "Chicken";
    case PIG:
      return "Pig";
      break;
    case COW:
      return "Cow";
      break;
    case SHEEP:
      return "Sheep";
      break;
    default:
      return "Unknown";
      break;
    }
  }

  void print_info() const {
    cout << "Name : " << name << "\n";
    cout << "Type : " << type_to_str(type) << "\n";
    cout << "Age : " << age << "\n";
    cout << "Weight : " << fixed << setprecision(2) << weight << "\n";
  }

  void set_new_weight(double new_weight) { this->weight = new_weight; }

  double set_weight(double new_weight) { return this->weight = new_weight; }

  double get_weight() const { return weight; }

  unsigned int get_age() const { return age; }

  const string &get_name() { return name; }

  void set_next(Animal *next) { this->next = next; }

  Animal *get_next() const { return next; }

  Animal *get_prev() const { return prev; }

  void set_prev(Animal *prev) { this->prev = prev; }
};

#endif