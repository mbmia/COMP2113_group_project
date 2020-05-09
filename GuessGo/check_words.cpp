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

//function to check if the picks are valid
//returns true if a word exists in the pool
bool check_words(string word, vector<string> pool){
  for (int i=0; i<pool.size();i++){
    if (pool[i]==(word)){
      return true;
    }
  }
  return false;
}
