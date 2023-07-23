#include <iomanip>
#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <exception>

#define MAX_SIZE 100

#include "animal.h" //act as node.h
#include "snack.h"
#include "linkedlist.h"
#include "queue.h"
#include "function.h"
#include "banners.h"

using namespace std;

unsigned int ValidInput_int(){
  unsigned int integer;
  bool ok = false;
  
 do{
    try{
        cin >> integer;
        if (cin.fail()){
          cin.clear();
          cin.ignore(1000, '\n');
          throw runtime_error("Input type not matched.");
        }
      else{
        ok = true;
      }
      }
        catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
   if(!ok)
     cout<<"Please enter number again : ";
  }while(!ok);
  return integer;
}

double ValidInput_double(){
  double decimal;
  bool ok = false;

  do{
    try{
        cin >> decimal;
        if (cin.fail()){
          cin.clear();
          cin.ignore(1000, '\n');
          throw runtime_error("Input type not matched.");
        }
      else{
        ok = true;
      }
      }
        catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
    if(!ok)
     cout<<"Please enter number again : ";
  }while(!ok);
  return decimal;
}

void insert_animal(LL &link, int num){
  unsigned int age, type, cal, welcome, user_option;
  string name;
  double weight;
  type_instructions();
  
  int i = 0;
  while (i  < num) {
    cout<<"Animal number : "<<i+1<<"\n";
    do{
      cout << "Type : ";
      type = ValidInput_int();
      if(type>4 || type <1)
        cout<<"Invalid type, please enter again\n";
    }while(type>4 || type <1);
    
    cout << "Name : ";
    cin >> name;
    
    do{
      cout << "Age : ";
      age = ValidInput_int();
      if(age<=0)
        cout<<"Invalid age, please enter again\n";
    }while(age<=0);
    
    do{
      cout << "Weight[kg]: ";
      weight = ValidInput_double();
      if(weight<=0)
        cout<<"Invalid weight, please enter again\n";
    }while(weight<=0);
    cout << "\n";
    
    int inserted = link.insert(type, name, age, weight);

    if (inserted == 0) {
      if (inserted == 0) {
        cout << "Please enter new name\n";
      }
    } 
    else {
      i++;
    }
  }
  cout << setw(30) << setfill('=') << "\n\n";
}

int main(){
  LL link;
  queue q;
  vector<Snack *> snacks;
  unsigned int age, type, num, cal, welcome, user_option;
  unsigned int animals_number = 0;
  string name;
  double weight;

  banner();

  cout << "Welcome to our program!" << "\n";
  cout << "1. Program Guide" << "\n";
  cout << "2. Start farming" << "\n";
  do{
    cout << "Ans : ";
    welcome = ValidInput_int();
    if(welcome != 1 && welcome != 2)
      cout<<"Please select 1 or 2\n";
  }while(welcome != 1 && welcome != 2);
  if(welcome == 1) 
    guide();
  else
    cout << "\x1B[2J\x1B[H"; //clear console, ANSI escape codes for cross-platform package manager(using in replit)


  cout<<"starting farm\n";
    do{
    cout << "How many initial animals ? : ";
      num = ValidInput_int();
    if(num<=0)
      cout<<"Invalid number, please enter number of animals again\n";
    if(num>=MAX_SIZE)
      cout<<"Too large number, please enter number of animalsin length [0-99]\n";
  }while(num<=0 || num>=MAX_SIZE);
  
  insert_animal(link,num);
  
  double avgPig = cal_avg(link, "Pig");
  double avgChicken = cal_avg(link, "Chicken");
  double avgCow = cal_avg(link, "Cow");
  double avgSheep = cal_avg(link, "Sheep");
  
  snack_bag();

  for (unsigned int i = 1; i <= 3; i++) {
    cout << "Calories of Snack type " << i << " [kcal]: ";
      cal = ValidInput_double();
    if(cal > 0 )
      snacks.push_back(new Snack(to_string(i), cal));
    else{
      cout<<"Invalid calrories, please enter again\n"; 
      i--;
    }
  }
  
  snackbubbleSort(snacks);
  
  cout << "\x1B[2J\x1B[H";
  
  animal_face();
  link.printList();
  print_avg_weight(avgPig, avgChicken, avgCow, avgSheep);
  print_snack(snacks);
  cout << setw(30) << setfill('=') << "=\n";
  
  do{
    print_option();
    user_option = ValidInput_int();
    
    switch(user_option){
      case 1 : {
        cout << "\x1B[2J\x1B[H";
        animal_face();
        link.printList();
        do{
            cout << "How many animals you want to add ? : ";
            num = ValidInput_int();
            if(num<=0)
              cout<<"Invalid number, please enter number of animals again\n";
            if(num>=MAX_SIZE)
              cout<<"Too large number, please enter number of animals again\n";
          }while(num<=0 || num>=MAX_SIZE);
        
          insert_animal(link,num);
      }
        cout << setw(30) << setfill('=') << "\n\n";
        avgPig = cal_avg(link, "Pig");
        avgChicken = cal_avg(link, "Chicken");
        avgCow = cal_avg(link, "Cow");
        avgSheep = cal_avg(link, "Sheep");
        
        cout << "\x1B[2J\x1B[H";
        animal_face();
        cout<<"Updated animal list and animals average weight\n";
        link.printList();
        print_avg_weight(avgPig, avgChicken, avgCow, avgSheep);
        break;
      
      case 2 : {
          cout << "\x1B[2J\x1B[H";
          int choice = 0;
          animal_face();
          link.printList();
          cout << setw(30) << setfill('=') << "=\n\n";
        
          if(link.get_size()!=0){
            print_snack(snacks);
          }
            
          print_avg_weight(avgPig, avgChicken, avgCow, avgSheep);
    
          if(link.get_size()!=0) {
            cout << "\nFeed animals\n";
            cout << "What type of snacks do you want to feed animals ? [1-3] : ";
            do{
            choice = ValidInput_int();
              if(choice < 1 || choice > 3)
                cout << "Unavailable snack type, please enter type[1-3] : ";
            }while(choice < 1 || choice > 3);
            
            cout << "\x1B[2J\x1B[H";
            after_eat(link, avgPig, avgChicken, avgCow, avgSheep, snacks, q, choice);
          }
          else
            cout<<"There is no animal in farm\n";
        
          cout << setw(30) << setfill('=') << "=\n";
    
          if (q.get_size() > 0) {
          print_avg_weight(avgPig, avgChicken, avgCow, avgSheep);
          cout << "\nQueued above average weight animals \n\n";
          cout << "There are " << q.get_size() << " animals in queue.\n";
          q.print_queue();
          }
      break;
      }

      case 3 : {
        unsigned int ship_num = 0;
        cout << "\x1B[2J\x1B[H";
        cout << setw(30) << setfill('=') << "=\n";
        if(q.get_size()<=0){
          cout<<"There is no animal in queue\n";
          cout << "\n\nNo shipping\n\n";
          break;
        }
            do {
              cout <<"There are "<< q.get_size() <<" animals in queue\n";
              q.print_queue();
              cout << "How many animals you want to ship ? : ";
              ship_num = ValidInput_int();
              if (ship_num > q.get_size()) {
                cout << "\x1B[2J\x1B[H";
                cout << "Animals in queue is lower than your demand, ship all animals in queue instead\n";
                ship_num = q.get_size();
              } 
              else if (ship_num < 0) {
                cout << "Invalid number please enter again\n";
              }
              else 
                cout << "\x1B[2J\x1B[H";
            } while (ship_num < 0);
              
            if (ship_num == 0) {
              cout << "\x1B[2J\x1B[H";
              cout << "\n\nNo shipping\n\n";
            }
            else{
              truck();
              for (int i = 0; i < ship_num; i++) {
                q.dequeue();
              }
            }  
        break;
        }
      case 4 : break;
      default: {
        cout<<"Invalid option please select again\n";
        continue;
      }
    }    
  }while(user_option!=4);

  cout << setw(30) << setfill('=') << "=\n";
  
  cout << ((q.get_size() >= 0) ? q.get_size() : 0) << " animals left in queue\n";
  (q.get_size() != 0) ? q.print_queue() : void();

  cout << ((link.get_size() >= 0) ? link.get_size() : 0) << " animals waiting for more snacks\n\n";
  (link.get_size() != 0) ? link.printList() : void();
  cout << "end of program\n\n";

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