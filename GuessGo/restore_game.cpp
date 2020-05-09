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

void restore_game(int &grid_size, int &pool_size, string** &computer_wordlist, string** &user_wordlist, vector<string>&pool){
  ifstream fin;
  string line;

  string s = "txt_files/sizes";
  fin.open(s.c_str());
  fin >> grid_size >>pool_size;
  fin.close();

  computer_wordlist = new string*[grid_size];
  user_wordlist = new string*[grid_size];

  for (int i = 0; i<grid_size;i++){
    computer_wordlist[i] = new string[grid_size];
  }

  for (int j = 0;j<grid_size; j++){
    user_wordlist[j] = new string[grid_size];
  }

  s= "txt_files/save_pool.txt";
  fin.open(s.c_str());
  if (fin.fail()){
    cout << "Error" <<endl;
    exit(0);
  }
  else{
    while(fin>>line){
      pool.push_back(line);
    }
  }
  fin.close();

  s = "txt_files/save_user_wordlist.txt";

  fin.open(s.c_str());
  if (fin.fail()){
    cout << "Error" <<endl;
    exit(0);
  }
  else{
    while(fin>>line){
      for (int m = 0; m<grid_size; m++){
        for (int n = 0; n<grid_size; n++){
          user_wordlist[m][n] = line;
        }
      }
    }
  }
  fin.close();

  s = "txt_files/save_computer_wordlist.txt";

  fin.open(s.c_str());
  if (fin.fail()){
    cout << "Error" <<endl;
    exit(0);
  }
  else{
    while(fin>>line){
      for (int u = 0;u<grid_size;u++){
        for (int v = 0; v<grid_size; v++){
          computer_wordlist[u][v] = line;
        }
      }
    }
  }
}
