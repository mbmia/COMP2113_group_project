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

// function to randomly select words from word_list.txt to form a pool
//and store them in a vector in alphabetical order
void select_words(int pool_size, vector<string> &wordarray){
  int n  = 0;
  vector<int> numarray;

  srand(time(NULL));
  for (int i = 0; i<pool_size; i++){
    n = rand()%3250;

    if (i==0){
      numarray.push_back(n); }

    else{
      if(find(numarray.begin(), numarray.end(), n) != numarray.end()) {
        i--;
        continue;
      }
      else {
        numarray.push_back(n);
       }
    }
  }

  sort(numarray.begin(), numarray.end());

  string mypath = "txt_files/word_list.txt";
  ifstream fin;
  fin.open(mypath.c_str());

  if (fin.fail()){
    cout << "Sorry, the game has to quit due to an error"<<endl;
    exit(0);
  }
  string myline;
  int mypointer = 0;
  int k = 0;

  while(getline(fin, myline) && mypointer < 3250){
    mypointer++;
    if (mypointer==numarray[k]){
      wordarray.push_back(myline);
      k++;
    }
  }
  fin.close();
}
