#include <iomanip>
#include <iostream>
#include <limits.h>
#include <string>
#include <vector>


#define MAX_SIZE 100

#include "animal.h" //act as node.h
#include "function.h"
#include "linkedlist.h"
#include "banners.h"
#include "queue.h"
#include "snack.h"

using namespace std;

void print_avg_weight(double Pig, double Chicken, double Cow, double Sheep){
  cout << setw(30) << setfill('=') << "\n\n";
  cout << "Pig's average weight " << setw(10) << setfill(' ') << Pig << "\n";
  cout << "Chicken's average weight " << setw(6) << setfill(' ') << Chicken << "\n";
  cout << "Cow's average weight " << setw(10) << setfill(' ') << Cow << "\n";
  cout << "sheep's average weight " << setw(8) << setfill(' ') << Sheep << "\n\n";
  cout << setw(30) << setfill('=') << "=\n";
}

void instructions() {
  cout << setw(30) << setfill('=') << "=\n";
  cout << "Select the species type" << "\n";
  cout << setw(3) << "1. Pig" << "\n";
  cout << setw(3) << "2. Chicken" << "\n";
  cout << setw(3) << "3. Cow" << "\n";
  cout << setw(3) << "4. Sheep" << "\n";
  cout << "\n";
  cout << setw(30) << setfill('=') << "=\n";
}

void guide(){
  cout << "\n< USER GUIDE >" << "\n";
  cout << "   Hello, This guide was written for users to have a better understanding of our program. The main function in this program is to calculate the weight of animals in the farm for shipping." << "\n";
  
  cout << "\n 1. Input the number of animals adding in the farm." << "\n";
  cout << "\n 2. Input the type, name, age, and weight of each animal." << "\n";
  cout << "\n 3. Input the calories of each snack type." << "\n";
  cout << "\n 4. Choose what type of snack user want to feed all the animal in the farm." << "\n";
  
  cout <<  "\n   The program will then calculate the final weight of each animal after eating the snack. If the animals weight is over average, it is ready to be ship off. If not, the animal will not be queued and continous in the farm, waiting for more snack.\n" << "\n";
}

int main(int argc, char *argv[]) {
  LL link;
  queue q;
  vector<Snack *> snacks; // keep in vector as size of vector is more flexible than array

  unsigned int age, type, num, cal, welcome, idk;
  unsigned int animals_number = 0;
  string name;
  double weight;

  banner();

  cout << "Welcome to our program!" << "\n";
  cout << "1. Program Guide" << "\n";
  cout << "2. Start farming" << "\n";
  cout << "Ans:";
  cin >> welcome;
  if(welcome== 1) 
    guide();
  cout<<"Starting farm\n";
  do{
    cout << "How many animals? : ";
    cin >> num;
    if(num<=0)
      cout<<"Invalid number, please enter number of animals again\n";
  }while(num<=0);
  instructions();
  
  unsigned int i = 0;
  while (i < num) {
    cout<<"Animal number : "<<i+1<<"\n";
    cout << "Type : ";
    cin >> type;
    cout << "Name : ";
    cin >> name;
    cout << "Age : ";
    cin >> age;
    cout << "Weight[kg]: ";
    cin >> weight;
    cout << "\n";
    int inserted = link.insert(type, name, age, weight);

    if (type > 4 || type < 1 || inserted == 0) {
      if (inserted == 0) {
        cout << "Already has this name in the same type, please enter new name\n";
      }
      if (type > 4 || type < 1) {
        cout << "Invalid type, please enter animal's info again\n";
      }
    } 
    else {
      i++;
    }
  }

  cout << setw(30) << setfill('=') << "\n\n";

  double avgPig = cal_avg(link, "Pig");
  double avgChicken = cal_avg(link, "Chicken");
  double avgCow = cal_avg(link, "Cow");
  double avgSheep = cal_avg(link, "Sheep");

  snack_bag();

  for (unsigned int i = 1; i <= 3; i++) {
    cout << "Calories of Snack type " << i << " [kcal]: ";
    cin >> cal;
    snacks.push_back(new Snack(to_string(i), cal));
  }
  cout << "\033[2J\033[0;0H";//clear console, idk does it works i just found it on replit community

  snackbubbleSort(snacks);
  string countinue_program = "y";
  
  cout << "\n";
  do {
    int choice = 0, ship_num = 0;
    string ship;

    animal_face();
    link.printList();
    cout << setw(30) << setfill('=') << "=\n\n";
    if(link.get_size()!=0){
      print_snack(snacks);
    }
    
    print_avg_weight(avgPig, avgChicken, avgCow, avgSheep);
    
    if(link.get_size()!=0)
    {
      cout << "\nFeed animals\n";
      cout << "What type of snacks do you want to feed animals ? [1-3]: ";
      cin >> choice;
      if (choice < 1 || choice > 3) {
        cout << "\033[2J\033[0;0H";
        cout << "No choice feed snack type 1 instead\n";
        choice = 1;
      }
      else
        cout << "\033[2J\033[0;0H";
      
      after_eat(link, avgPig, avgChicken, avgCow, avgSheep, snacks, q, choice);
    }
    cout << setw(30) << setfill('=') << "=\n";
    
    if (q.get_size() > 0) {
      cout << "\nQueued above average weight animals \n\n";
      cout << "There are " << q.get_size() << " animals in queue.\n";
      q.print_queue();

      cout << "Do you want to ship animals in queue ? [y/n] : ";
      cin >> ship;
      if (ship == "y" || ship == "Y") {
        do {
          cout << "How many animals you want to ship ? : ";
          cin >> ship_num;
          if (ship_num > q.get_size()) {
            cout << "\033[2J\033[0;0H";
            cout << "Animals in queue is lower than your demand, ship all animals in queue instead\n";
            ship_num = q.get_size();
          } 
          else if (ship_num < 0) {
            cout << "Invalid number please enter again\n";
          }
          else 
            cout << "\033[2J\033[0;0H";
        } while (ship_num < 0);
          
        if (ship_num == 0) {
          cout << "\033[2J\033[0;0H";
          cout << "\n\nNo shipping\n\n";
        }
        
        for (int i = 0; i < ship_num; i++) {
          q.dequeue();
        }

        if(ship_num != 0)
          truck();
      } 
      else if (ship != "y") {
        cout << "\033[2J\033[0;0H";
        cout << "\nNo shipping\n\n";
      }
    }
    if(link.get_size() != 0 || q.get_size() != 0){  
      cout << "Do you want to countinue manage your farm? [y/n]: ";
      cin >> countinue_program;
    }

    // cout<<"\nendloop\n";
  } while ((link.get_size() != 0 || q.get_size() != 0) && (countinue_program != "n" && countinue_program != "N"));

  cout << setw(30) << setfill('=') << "=\n";
  
  cout << ((q.get_size() >= 0) ? q.get_size() : 0) << " animals left in queue\n";
  (q.get_size() != 0) ? q.print_queue() : void();

  cout << ((link.get_size() >= 0) ? link.get_size() : 0) << " animals waiting for more snacks\n\n";
  (link.get_size() != 0) ? link.printList() : void();

  
  cout << "end of program\n\n";


  //printing credits
  cout << "<Credit>" << "\n"; 
  cout << "Yanaput\t\tMakbonsonglop\t(Lead Programmer)" << "\n";
  cout << "Pakkapak\tJungjaroen\t\t(Lead Programmer)" << "\n";
  cout << "Andaman\t\tJamprasitsakul\t(Debugger)" << "\n";
  cout << "Jinnaphat\tGuntawang\t\t(Debugger)" << "\n\n";
  cout << "Special Thanks: Prof.Dr.Mingmanas Sivaraksa\n " << "\n";
  

  for (const auto sna : snacks) {
    delete sna;
  }

  return 0;
}

// sort age by linked list  [done]
// fix avg cal  [done]
// change most of int to unsigned int [done]
// enqueue animals that weight >= average from linked list [done]
// eat snack ++weight by cal of snack*0.75 [done]
// {dequeue} ask whether user want to feed & ship them. if yes, [done]
// case error [done]
// interface [done]
// delete new variable [done]

/*
PROJECT UPDATED FROM MIDTERM
-- use linked list in the animal class to replace sorting algo
-- use enum to get type of animals rather than using 
***
1. input the animals into the linked list // sort by age
2. input the snacks
3. cal avg for each animals
4. if(oldest animals that weight >= average) enqueue // (for those lower that avg) ask which type of snack user want to give and then if they meet conditions, enqueue them.
5. ask whether user want to ship them or not // if (y/Y) ask the number that they want to ship then dequeue and then keep the remainings
6. ask user if user wants to ship more animals (if they are available in the queue or linked list, if yes loop again to the case that we want how many of them to be shipped. Or else ask if they want to feed animals more?
7. at the end, tell user that how many animals ready to be ship and animals that still be in the farm (weight < avg)

Note : 

Things Herb want to add(I ll do later):
1.show unit of weight, cal[done]
2.
3.some errors when false input(string & int)(maybe my personal problem)
4.maybe add some program guide[done]
5.credit at the end of the program lol[done]
*/
