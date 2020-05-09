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

//function to get computer's guess
string get_computer_guess(int pool_size, vector<string> pool, vector<int> hit_numbers){
  bool isHit = false;

  srand(time(NULL));
  int rnd = rand()%pool_size;

  if (hit_numbers.size()==0){
    hit_numbers.push_back(rnd);
  }

  if (hit_numbers.size()>0){
    while(!isHit){
      int rnd = rand()%pool_size;
      //if the number exists in the hit_numbers vector
      if (find(hit_numbers.begin(), hit_numbers.end(), rnd) != hit_numbers.end()){
        continue;
      }
      else{
        //guess hasn't been hit yet
        isHit = true;
      }
    }
  }

  string computer_guess = pool[rnd];
  if (check_guess){
    hit_numbers.push_back(rnd);
  }
  return computer_guess;
}
