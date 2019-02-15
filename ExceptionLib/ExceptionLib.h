#pragma once
#include <iostream>
#include <string>
using namespace std;

class Exc 
{
private:
  string s;
public:
  Exc(string _s) : s(_s) {}
  void Print() { cout << "Exception caught: " << s << endl; }
};
