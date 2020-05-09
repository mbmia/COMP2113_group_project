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

//function for options at the start of games
string start_options(int &grid_size, int &pool_size, string** computer_wordlist, string** user_wordlist, vector<string> pool){
  string answer;

  cout << "To view the rules, press 1" << endl;
  cout << "To start a new game, press 2" <<endl;

  if (previous_game()){
    cout << "To continue the previous game, press 3" << endl;
  }

    cin >> answer;

    while (answer.length()!=1|| (answer.at(0)!='1' && answer.at(0)!='2' && answer.at(0)!='3')){
      cout << "Invalid input. Please try again." << endl;
      cin >> answer;
    }

    if (answer.at(0) == '1'){
      cout << '\n';
      print_rules(grid_size, pool_size, computer_wordlist, user_wordlist, pool);
      return "1";
    }

    else if (answer.at(0) == '2'){
      get_input(grid_size, pool_size);
      return "2";
    }

    else if (answer.at(0)=='3'){
      restore_game(grid_size, pool_size, computer_wordlist, user_wordlist, pool);
      return "3";
    }
    return "0";
}
