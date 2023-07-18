#ifndef function_h
#define function_h

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "animal.h"
#include "linkedlist.h"
#include "queue.h"
#include "snack.h"
#include "banners.h"

using namespace std;

void snackbubbleSort(vector<Snack *> &snacks) {
  unsigned int size = snacks.size();

  for (unsigned int i = 0; i < size - 1; i++) {
    bool sorted = true;
    for (unsigned int j = 0; j < size - i - 1; j++) {
      if (snacks[j]->get_cal() > snacks[j + 1]->get_cal()) {
        Snack *temp = snacks[j];
        snacks[j] = snacks[j + 1];
        snacks[j + 1] = temp;
        sorted = false;
      }
    }
    if (sorted == true) {
      break;
    }
  }
}

string type_to_lower(string type) {
  for (unsigned int i = 0; i < type.size(); i++) {
    type[i] = tolower(type[i]);
  }
  return type;
}

double cal_avg(LL &animals, string type) {
  double total = 0.0;
  unsigned int count = 0;
  Animal *current = animals.get_head();
  while (current) {
    if (current->get_type() == type) {
      total += current->get_weight();
      count++;
    }
    current = current->get_next(); // problem solved***
  }
  return (count > 0) ? (total / count) : 0.0;
}

void assign_snack(Animal *animal, double avg, vector<Snack *> &snacks, int choice) {
  animal->set_weight(animal->get_weight() + (snacks[choice - 1]->get_cal() * 0.75));
}

void after_eat(LL &animals, double avgPig, double avgChicken, double avgCow,
  double avgSheep, vector<Snack *> &snacks, queue &q, int choice) {
  Animal *current = animals.get_head();
  
  cout << "Animals get snack type " << choice << " containing " << snacks[choice - 1]->get_cal() << " Kilo calories\n";
  
  while (current) {
    double inp_agv = 0;
    if (current->get_type() == "Pig") {
      assign_snack(current, avgPig, snacks, choice);
      inp_agv = avgPig;
    } 
    else if (current->get_type() == "Chicken") {
      assign_snack(current, avgChicken, snacks, choice);
      inp_agv = avgChicken;
    } 
    else if (current->get_type() == "Cow") {
      assign_snack(current, avgCow, snacks, choice);
      inp_agv = avgCow;
    } 
    else if (current->get_type() == "Sheep") {
      assign_snack(current, avgSheep, snacks, choice);
      inp_agv = avgSheep;
    }

    if (current->get_weight() >= inp_agv) {
      q.enqueue(current->get_age(), current->get_weight(), current->get_type(), current->get_name());
      animals.deletes(current->get_name(), current->get_type());
    }
    current = current->get_next();
  }
  cout << "\nAnimal weight updated\n";
}

void print_snack(vector<Snack *> &sna){
  snack_bag();
  cout << "List of snacks\n";
  for (const auto &snack : sna) { // print available snacks
    snack->print_info();
    cout << "\n";
  }
}

#endif