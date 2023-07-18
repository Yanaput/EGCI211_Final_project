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

void type_instructions() {
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
  
  cout << "\n 1. Input the number of animals to intitialize farm.\n";
  cout << "\n 2. Input the type, name, age, and weight of each animal." << "\n";
  cout << "\n 3. Input the calories of each snack type." << "\n";
  cout << "\n 4. Select the option program provided.\n";
  cout << "\n \t4.1 Option 1 : Repeat step 2 for additional animal \n";
  cout << "\n \t4.2 Select type of snack and program will feed animals in farm & increase their weight, then will queue animals with weight above or equal to their type's average weight\n";
  cout << "\n \t4.3 Input number of animals in queue you want to ship\n";
  cout << "\n 5. To end program input 5 as an option \n";
  
  
  cout <<  "\n   The program will then calculate the final weight of each animal after eating the snack. If the animals weight is over average, it is ready to be ship off. If not, the animal will not be queued and continous in the farm, waiting for more snack.\n" << "\n";
}

void print_option(){
  cout << setw(30) << setfill('=') << "=\n";
  cout<<"Options\n";
  cout<<"1. add animals to farm\n";
  cout<<"2. feed & queue animals\n";
  cout<<"3. ship queued animals\n";
  cout<<"4. end program\n";
  cout<<"Select a  option : ";
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
  cout << "Ans : ";
  cin >> welcome;
  if(welcome== 1) 
    guide();
  else
    cout << "\x1B[2J\x1B[H"; //clear console, ANSI escape codes for nixes(using in replit)


  cout<<"starting farm\n";
    do{
    cout << "How many intitial animals ? : ";
    cin >> num;
    if(num<=0)
      cout<<"Invalid number, please enter number of animals again\n";
    if(num>=MAX_SIZE)
      cout<<"Too large number, please enter number of animalsin length [0-99]\n";
  }while(num<=0 && num>=MAX_SIZE);
  
  type_instructions();
  
  int i = 0;
  while (i  < num) {
    cout<<"Animal number : "<<i+1<<"\n";
    do{
      cout << "Type : ";
      cin >> type;
      if(type>4 || type <1)
        cout<<"Invalid type, please enter again\n";
    }while(type>4 || type <1);
    cout << "Name : ";
    cin >> name;
    do{
      cout << "Age : ";
      cin >> age;  
      if(age<=0)
        cout<<"Invalid age, please enter again\n";
    }while(age<=0);
    do{
      cout << "Weight[kg]: ";
      cin >> weight;
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
  
  snackbubbleSort(snacks);
  
  cout << "\x1B[2J\x1B[H";
  
  animal_face();
  link.printList();
  print_avg_weight(avgPig, avgChicken, avgCow, avgSheep);
  print_snack(snacks);
  cout << setw(30) << setfill('=') << "=\n";
  
  do{
    print_option();
    cin>>user_option;
    
    switch(user_option){
      case 1 : {
        cout << "\x1B[2J\x1B[H";
        do{
            animal_face();
            link.printList();
            cout << "How many animals you want to add ? : ";
            cin >> num;
            if(num<=0)
              cout<<"Invalid number, please enter number of animals again\n";
            if(num>=MAX_SIZE)
              cout<<"Too large number, please enter number of animals again\n";
          }while(num<=0 && num>=MAX_SIZE);
          type_instructions();
          
          unsigned int i = 0;
          while (i < num) {
            cout<<"Addition animal number : "<<i+1<<"\n";
            cout << "Type : ";
            cin >> type;
            cout << "Name : ";
            cin >> name;
            do{
              cout << "Age : ";
              cin >> age;  
              if(age<=0)
                cout<<"Invalid age, please enter again\n";
            }while(age<=0);
            do{
              cout << "Weight[kg]: ";
              cin >> weight;
              if(weight<=0)
                cout<<"Invalid weight, please enter again\n";
            }while(weight<=0);
            cout << "\n";
            int inserted = link.insert(type, name, age, weight);
        
            if (type > 4 || type < 1 || inserted == 0) {
              if (inserted == 0) {
                cout << "Please enter new name\n";
              }
              if (type > 4 || type < 1) {
                cout << "Invalid type, please enter animal's info again\n";
              }
            } 
            else {
              i++;
            }
          }
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
            cout << "What type of snacks do you want to feed animals ? [1-3]: ";
            cin >> choice;
            if (choice < 1 || choice > 3) {
              cout << "\x1B[2J\x1B[H";
              cout << "No choice feed snack type 1 instead\n";
              choice = 1;
            }
            cout << "\x1B[2J\x1B[H";
            after_eat(link, avgPig, avgChicken, avgCow, avgSheep, snacks, q, choice);
          }
          else
            cout<<"There is no animal in farm\n";
        
          cout << setw(30) << setfill('=') << "=\n";
    
          if (q.get_size() > 0) {
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
              cin >> ship_num;
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