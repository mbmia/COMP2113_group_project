#include <iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
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

int main(){
  int grid_size, pool_size;
  bool tossResult;
  string** userwordlist;
  string** computerwordlist;
  vector<string> pool;
  vector<int> hitnumbers;


  cout << "Welcome to GuessGo!" << '\n' <<endl;


  get_input(grid_size, pool_size);

    select_words(pool_size, pool);
    cout <<"\nThis is your pool" <<endl;
    show_pool(pool);

    pick_user_words(grid_size, userwordlist, pool);
    cout << "Your grid looks like this: " << endl;
    view_my_list(grid_size, userwordlist);
    pick_computer_words(grid_size, pool_size, computerwordlist, pool);
    tossResult = do_toss();


  //does toss to determine the turn


  //game continues till there is a winner
  while(get_winner(grid_size, userwordlist)!=true
        && get_winner(grid_size, computerwordlist)!=true){
    if (tossResult == true){
      user_play(grid_size, computerwordlist, pool);
      computer_play(grid_size, pool_size, computerwordlist, userwordlist, pool, hitnumbers);
    }
    else{
      computer_play(grid_size, pool_size, computerwordlist, userwordlist, pool, hitnumbers);
      user_play(grid_size, computerwordlist, pool);
    }
  }
  if (get_winner(grid_size, computerwordlist)==true){
    cout << "Congrats! You have won the game :D" <<endl;
  }

  else if (get_winner(grid_size, userwordlist)==true){
    cout << "The computer won the game :(" <<endl;
  }

  return 0;
}
