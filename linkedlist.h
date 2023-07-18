#ifndef linkedlist_h
#define linkedlist_h

#include <iomanip>
#include <iostream>
#include <limits.h>
#include <string>
#define MAX_SIZE 100

#include "animal.h"
#include "queue.h"

using namespace std;

class LL {
private:
  Animal *head;
  unsigned int size;

public:
  LL();
  ~LL();
  int insert(unsigned int, string, unsigned int, double);
  string deletes(string, string);
  unsigned int isEmpty();
  void printList();
  Animal *get_head() { return head; }
  unsigned int get_size() { return size; }
};

LL::LL() {
  head = nullptr;
  size = 0;
}

LL::~LL() {
  Animal *tmp;
  tmp = head;
  string name;

  for (unsigned int i = 0; i < size; i++) {
    name = tmp->get_name();
    head = head->get_next();
    delete tmp;
    tmp = head;
    cout << "See you next time." << name <<"\n";
  }
}

unsigned int LL::isEmpty() { return head == nullptr; }

int LL::insert(unsigned int choice, string name, unsigned int age, double weight) {
  Animal *new_node = nullptr;
  Animal *checknameptr = head;
  string type;

  while (checknameptr != nullptr) {
    if (checknameptr->get_name() == name) {
      cout << "Name already exists.\n";
      return 0; // Return 0 to indicate duplicate name
    }
    checknameptr = checknameptr->get_next();
  }

  switch (choice) {
  case 1:
    new_node = new Animal(age, weight, type = "Pig", name);
    break;
  case 2:
    new_node = new Animal(age, weight, type = "Chicken", name);
    break;
  case 3:
    new_node = new Animal(age, weight, type = "Cow", name);
    break;
  case 4:
    new_node = new Animal(age, weight, type = "Sheep", name);
    break;
  default:
    cout << "Invalid type please enter type [1-4]\n";
    break;
  }

  Animal *currentptr = new_node;
  Animal *nextptr;
  Animal *prevptr;

  if (size >= MAX_SIZE) {
    cout << "Error \n";
    return -1;
  }

  if (new_node != nullptr) {
    currentptr = head;
    prevptr = nullptr;

    while (currentptr != nullptr && age < currentptr->get_age()) {
      prevptr = currentptr;
      currentptr = currentptr->get_next();
    }

    if (prevptr == nullptr) {
      new_node->set_next(head);
      if (head) {
        head->set_prev(new_node);
      }
      head = new_node;
    } // end if
    else {
      prevptr->set_next(new_node);
      new_node->set_prev(prevptr);
      new_node->set_next(currentptr);
      if (currentptr) {
        currentptr->set_prev(new_node);
      }
    }
    ++size;
  }
  return 1;
}

string LL::deletes(string name, string type) {
  if (isEmpty()) {
    cout << "--List is empty." << "\n";
    return "";
  }

  Animal *currentptr = head;
  Animal *prevptr = nullptr;

  while (currentptr != nullptr) {
    if (name.compare(currentptr->get_name()) == 0 &&
        type.compare(currentptr->get_type()) == 0) {
      if (prevptr == nullptr) {
        head = currentptr->get_next();
      } else {
        prevptr->set_next(currentptr->get_next());
      }

      if (currentptr->get_next() != nullptr) {
        currentptr->get_next()->set_prev(prevptr);
      }

      string deletedName = currentptr->get_name();
      delete currentptr;
      --size;
      return deletedName;
    }

    prevptr = currentptr;
    currentptr = currentptr->get_next();
  }

  cout << "Animal not found.\n";
  return "";
}

void LL::printList() {
  Animal *currentptr;
  currentptr = head;

  if (size == 0) {
    cout << "Animal List is empty." << endl;
  } else {
    cout << "List of Animals in farm :" << endl;
    for (unsigned int i = 0; i < size; i++) {
      currentptr->print_info();
      cout << "\n";
      currentptr = currentptr->get_next();
    }
  }
}

#endif