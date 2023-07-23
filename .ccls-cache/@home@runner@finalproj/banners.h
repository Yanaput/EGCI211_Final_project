#ifndef lol_h
#define lol_h

#include <iostream>
#include <iomanip>

using namespace std;

void banner(){
  cout<<setw(41)<<setfill('=')<<"\n";
  cout << " _ _ _     _ _ _     _ _ _      _     _     " << "\n";
  cout << "|  _ _|   /     \\   |  _ _ \\   | |_ _| |  " << "\n";
  cout << "| |_ _   |  _ _  |  | |_ _| |  |       |    " << "\n";
  cout << "|  _ _|  | |_ _| |  |  _   /   | |\\_/| |   " << "\n";
  cout << "| |      |  _ _  |  | |  \\ \\   | |   | |  " << "\n";
  cout << "|_|      |_|   |_|  |_|   \\_\\  |_|   |_|  " << "\n";
  cout << "\n";
  cout<<setw(41)<<setfill('=')<<"\n";
}

void animal_face(){
  cout << "  _     _       _     _       _     _     "    << "\n";
  cout << "\\| |_ _| |/   \\| |_ _| |/  \\| |_ _| |/ "    << "\n";
  cout << "_|_> _ <_|_   _|_> _ <_|_   _|_> _ <_|_   "    << "\n";
  cout << "|_ _ ~ _ _|   |_ _ ~ _ _|   |_ _ ~ _ _|   "    << "\n";
  cout << "\n";
}

void snack_bag(){
  cout << " ________    "         << "\n";
  cout << "|        \\  []     []" << "\n";
  cout << "| snack  /     []"     << "\n";
  cout << "|________\\ []     []"  << "\n";
  cout << "\n";
}

void truck(){
  cout << "        ___________" << "\n";
  cout << "       |           |_" << "\n";
  cout << "       |           |  \\" << "\n";
  cout << " [] [] |___________|__|" << "\n";
  cout << "        |_|   |_|" << "\n";
  cout << "\n";
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

#endif