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

//function to check for the overall winner
//returns 0 if the winner is the user
//returns 1 if the winner is the computer
//dummy function for now
bool get_winner(int grid_size, string** &wordlist){
  int flag_col=0,n=0;
  while (n<grid_size){
    for (int m=0;m<grid_size;m++){ //for the columns
      if (wordlist[m][n]!="X"){
        flag_col=1;
        break;
      }
    }
    if (flag_col==0)
      return true;
    else
      flag_col=0;
    n++;
  }
  for (int m=0;m<grid_size;m++){
    for (int j=0;j<grid_size;j++){  //for the rows
      if (wordlist[m][j]!="X"){
        return false;
      }
    }
  }
  return true;
}
