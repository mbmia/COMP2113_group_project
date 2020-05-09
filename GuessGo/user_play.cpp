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

//function to let user play
void user_play(int grid_size, string** &users_list, vector<string> pool){
  //user guesses
  string userguess = get_user_guess(pool);
  //guess is checked
  //the game tells user if the guess was a hit or miss
  if (check_guess(grid_size, userguess, users_list)){
    cout << "You hit a word in the computer's grid!" <<endl;
  }
  else{
    cout << "That word is not in the computer's grid" <<endl;
  }
}
