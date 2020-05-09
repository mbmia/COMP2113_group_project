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

// function to verify the computer and user's guesses
bool check_guess(int grid_size, string guess, string** &wordlist){
  for (int m=0;m<grid_size;m++){
    for (int n=0;n<grid_size;n++){
      if (wordlist[m][n]==guess){
        wordlist[m][n] = "X";//instead of calling the call_out() function, we can just replace the guessed word with "X" int the array.
        return true;
      }
    }
  }
  return false;
}
