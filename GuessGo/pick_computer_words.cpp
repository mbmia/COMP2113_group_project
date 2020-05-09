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

//function for the computer to pick its words (at random)
void pick_computer_words(int grid_size, int pool_size, string** &computer_wordlist, vector<string> word_pool){
  int r  = 0;
  vector<int> p;

  srand(time(NULL));
  for (int i = 0; i<grid_size*grid_size; i++){
    r = rand()%pool_size;

    if (i==0){
      p.push_back(r); }

    else{
      if(find(p.begin(), p.end(), r) != p.end()) {
        i--;
        continue;
      }
      else {
        p.push_back(r);
       }
    }
  }

  computer_wordlist = new string*[grid_size];
  for (int k=0; k<grid_size; k++){
    computer_wordlist[k] = new string[grid_size];
  }

  int z = 0;
  for (int x = 0; x<grid_size; x++){
    for (int y=0; y<grid_size; y++){
      computer_wordlist[x][y]=word_pool[p[z]];
      z++;
    }
  }
}
