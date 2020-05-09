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

//function to get guesses from the user
//checks if the guess exists in the pool
string get_user_guess(vector<string> pool){
    string guess, response;
    cout << "Please type in your guess" <<endl;
    bool guessOk = false;
    while (!guessOk){
      cin >> guess;
      if (check_words(guess, pool)==true){
        guessOk = true;
      }
      else{
        cout << "The word does not exist in the pool." <<endl;
        cout << "Do you want to view the pool again? (Y/N)" <<endl;

        cin >> response;

        while(response.length()!=1 || (tolower(response.at(0))!='y'&& tolower(response.at(0))!='n')){
          cout << "Invalid response. (Y/N)"<<endl;
          cin >> response;
          }

          if (tolower(response.at(0))=='y'){
            show_pool(pool);
            cout << "Please guess again." <<endl;}

          else if (tolower(response.at(0))=='n'){
            cout<< "Please guess again" <<endl;
          }
        }
      }
  return guess;
}
