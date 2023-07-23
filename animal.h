#ifndef animalprototype_h
#define animalprototype_h

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "snack.h"

using namespace std;

class Animal {
private:
  string name;
  string type;
  unsigned int age;
  double weight;

  // node for linked lsit
  Animal *next;
  Animal *prev;

public:
  Animal(unsigned int _age, double _weight, string &_type,
         const string &_name = "Unknown") {
    this->age = _age;
    this->weight = _weight;
    this->type = _type;
    this->name = _name;

    this->next = nullptr;
    this->prev = nullptr;
  }

  ~Animal(){};

  void set_info(const string &_type, unsigned int _age, double _weight,
                const string &_name) {
    this->type = _type;
    if (_age >= 0) {
      this->age = _age;
    } else {
      cout << "Invalid age entered. Setting age to 0." << endl;
      age = 0;
    }

    if (_weight >= 0) {
      this->weight = _weight;
    } else {
      cout << "Invalid weight entered. Setting weight to 0." << endl;
      this->weight = 0.0;
    }

    this->name = _name;
  }

  string get_type() const { return type; }

  void print_info() const {
    cout << "Name : " << name << "\n";
    cout << "Type : " << type << "\n";
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