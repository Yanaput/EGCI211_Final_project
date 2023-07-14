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
#endif