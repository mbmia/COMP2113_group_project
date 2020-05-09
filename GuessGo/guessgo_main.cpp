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
using namespace std;

//function to print an introduction to the game
void print_rules(int grid_size, int pool_size, string** computer_wordlist, string** user_wordlist, vector<string> pool){
  string ans;
  char reply;
  bool keeplooping = true;

  string rule_path = "txt_files/rulebook.txt";
  ifstream fin;
  fin.open(rule_path.c_str());

  if (fin.fail()){
    cout << "Sorry, there was an error in displaying the rules. Would you like to continue? (Y/N)" << endl;
    keeplooping = false;
  }

  while (!keeplooping){
    cin >> ans;
    cout << '\n';
    if (ans.length()==1 && tolower(ans.at(0)) == 'y'){
      start_options(grid_size, pool_size, computer_wordlist, user_wordlist, pool);
      keeplooping = true;
    }
    else if (ans.length()==1 && tolower(ans.at(0)) == 'n'){
      cout << "You have exited the game."<<endl;
      exit(0);
    }

    else
      cout << "Invalid input. (Y/N)"<<'\n'<<endl;
  }

  string x;
  while (fin >> x){
    cout << x << " ";
  }

  cout << '\n' <<endl;

  fin.close();
  start_options(grid_size, pool_size, computer_wordlist, user_wordlist, pool);
}
