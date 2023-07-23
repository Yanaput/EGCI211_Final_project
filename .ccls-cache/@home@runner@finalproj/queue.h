#ifndef queue_h
#define queue_h

#include <iomanip>
#include <iostream>

#include "animal.h"

using namespace std;

class queue {
private:
  Animal *head;
  Animal *tail;
  int size = 0;

public:
  queue();
  ~queue();
  void enqueue(unsigned int, double, string, const string);
  void dequeue();
  int get_size() { return size; }
  Animal *get_head() { return head; }
  bool isEmpty();
  void print_queue();
};

queue::queue() {
  head = nullptr;
  tail = nullptr;
  size = 0;
}

queue::~queue() {
  Animal *tmp;
  string name;

  for (int i = 0; i <= size; i++) {
    if (head != nullptr) {
      tmp = head;
      name = tmp->get_name();
      head = head->get_next();
      delete tmp;
      if (size == 0) {
        tail = nullptr;
      }
    }
    --size;
    if(tail!=nullptr)
      cout << "Have a good day to " << name << "\n";
  }
}

void queue::enqueue(unsigned int age, double weight, string type, const string name) {
  Animal *new_animal = new Animal(age, weight, type, name);
  if (new_animal) {
    if (size == 0) {
      head = new_animal;
    } 
    else {
      tail->set_next(new_animal);
    }
    tail = new_animal;
    size++;
  } 
  else {
    cout << "Overflow."
         << "\n";
  }
}

void queue::dequeue() {
  string name, type;
  int age;
  double weight;
  Animal *tmp;

  if (head != nullptr) {
    tmp = head;
    name = tmp->get_name();
    type = tmp->get_type();
    age = tmp->get_age();
    weight = tmp->get_weight();
    head = head->get_next();
    delete tmp;
    if (size == 0) {
      tail = nullptr;
    }
    --size;
    cout << "Bye Bye! Name : " << name << " | Type : " << type << " | Age : " << age << " | Weight : " << weight << "\n";
  }
}

bool queue::isEmpty() { return size == 0; }

void queue::print_queue() {
  Animal *currentptr = head;

  if (size == 0) {
    cout << "--Queue is empty.\n";
  } else {
    cout << "Animals in queue : \n";
    for (unsigned int i = 0; i < size; i++) {
      currentptr->print_info();
      cout << "\n";
      currentptr = currentptr->get_next();
    }
  }
}

#endif