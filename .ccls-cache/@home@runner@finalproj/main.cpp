//  g++ farm_prototype.cpp -o test
//  ./test

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "animal_prototype.h" //act as node.h
#include "function.h"
#include "snack.h"
#include "linkedlist.h"
#include "queue.h"

using namespace std;

void instructions(){
  cout << "Select the species" << "\n";
  cout << setw(3) << "1. Pig" << "\n";
  cout << setw(3) << "2. Chicken" << "\n";
  cout << setw(3) << "3. Cow" << "\n";
  cout << setw(3) << "4. Sheep" << "\n";
  cout << "\n";
}


int main(int argc, char* argv[]){
  LL link;
  queue q;
  vector<Snack *> snacks;  // keep in vector as size of vector is more flexible than array
  
  unsigned int age, type, num, cal;
  unsigned int animals_number = 0;
  string name;
  double weight;
  
  instructions();

  cout << "How many animals? : ";
  cin >> num;

  for(unsigned int i = 0; i < num; i++){
    cout << "Type : ";
    cin >> type;
    cout << "Name : ";
    cin >> name;
    cout << "Age : ";
    cin >> age;
    cout << "Weight : ";
    cin >> weight;
    cout << "\n";
    link.insert(type, name, age, weight);
  }
  cout << setw(30) << setfill('=') << "\n";
  
  link.printList();
  
  cout << setw(30) << setfill('=') << "\n";

  double avgPig = cal_avg(link, "Pig");
  double avgChicken = cal_avg(link, "Chicken");
  double avgCow = cal_avg(link, "Cow");
  double avgSheep = cal_avg(link, "Sheep");
  
  cout << "\n";
  
  cout << "avg pig " << setw(10)<<setfill(' ') << avgPig << "\n";
  cout << "avg chicken " << setw(6)<<setfill(' ') << avgChicken << "\n";
  cout << "avg cow " << setw(10)<<setfill(' ') << avgCow << "\n";
  cout << "avg sheep " << setw(8)<<setfill(' ') << avgSheep << "\n";
  cout << "\n";
  
  for(unsigned int i = 1 ; i <= 3; i++){
    cout<<"Calories of Snack type "<< i <<" : ";
    cin >> cal;
    snacks.push_back(new Snack(to_string(i), cal));
  }

  cout<<"\nList of snacks\n";
  snackbubbleSort(snacks);
  for (const auto &sna : snacks) { // print available snacks
    sna->print_info();
    cout << "\n";
  }

  after_eat(link, avgPig, avgChicken, avgCow, avgSheep, snacks);
  //wtf. this is the fuckin hard function to code loey ai here mae yed
  cout<<"Queued above average weight animals \n";
  
  string ship;
  do{
    unsigned int ship_num;
    cout<<"Do you want to ship animal in queue ? [y/n] : ";
    cin>>ship;
    cout<<"How many animals you want to ship ?\n : ";
    do{//for error
      cin>>ship_num;
    }while(ship_num<=0);
    
    if(ship!="n"){
      for(int i=0;i<ship_num;i++){
        link.dequeue();
      }
    }
    after_eat(link, avgPig, avgChicken, avgCow, avgSheep, snacks);
    cout<<"Queue updated\n";
    link.printList();
  }while(ship!= "n" && link.get_size()!=0);

  return 0;
}


//sort age  [done]
//fix avg cal  [fixed : done]
//change most of int to unsigned int? [done]
//eat snack ++weight && weight >= average {enqueue} [done]
//{dequeue} ask how whether user want to ship them. if yes, dequeue them. else, do nothing