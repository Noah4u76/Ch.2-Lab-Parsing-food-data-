//
// File: main.cpp
// Description: Parsing food data
// Created: Sun. Feb 26, 2023
// Author: Noah Sanderson
// mail: Noahs6423@student.vvc.edu
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {

   vector<string> catg, name, desc, status;
   string fname;

   cout <<"Filename: ";
   cin >> fname;

   ifstream file(fname);
   while (getline(file, fname)) {
       size_t pos1 = fname.find('\t');
       size_t pos2 = fname.find('\t', pos1 + 1);
       size_t pos3 = fname.find('\t', pos2 + 1);
       catg.push_back(fname.substr(0, pos1));

       name.push_back(fname.substr(pos1 + 1, pos2 - pos1 - 1));

       desc.push_back(fname.substr(pos2 + 1, pos3 - pos2 - 1));

       status.push_back(fname.substr(pos3 + 1, fname.length() - pos3));

   }
   for (int i = 0; i < name.size(); i++){
       if (status[i] == "Available"){
           cout << name[i] << " (" << catg[i] << ") -- " << desc[i] << endl;
       }
   }
   return 0;
}
