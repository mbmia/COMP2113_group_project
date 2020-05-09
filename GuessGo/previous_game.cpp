#include <iostream>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<ctime>
#include <fstream>
#include<sstream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include "guessgo.h"
using namespace std;

bool previous_game(){
  ifstream fin;
  string s;
  s = "txt_files/save_pool.txt";
  fin.open(s.c_str());
  if (fin.fail()){
    //cout<<"Error loading the previous game status. Continue to play a new game."<<endl;
    return false;
  }
  else {
    string game_status;
    fin>>game_status;
    if (game_status=="1"){
      return true;
    }
  }
  fin.close();
  return false;
}
