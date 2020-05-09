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

//functio to let computer play
void computer_play(int grid_size, int pool_size, string** &computer_list, string** &user_list, vector<string> pool, vector<int> hit_numbers){
  //computer guesses
  string reply;

  string computerguess = get_computer_guess(pool_size, pool, hit_numbers);
  //guess is checked
  //the game shows whether the user's word has been hit or not
  if (check_guess(grid_size, computerguess, computer_list)){
    cout << "The computer hit a word in your grid" <<endl;
    cout << "\nYour grid now is: " <<endl;
    view_my_list(grid_size, user_list);
  }
  else{
    cout << "The computer's guess was a miss!" <<endl;
  }
}
