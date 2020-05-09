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

//function to let user pick words for their grid
//the words chosen by the user are stored in a 2D dynamic array
void pick_user_words(int grid_size, string** &picked_words, vector<string> word_pool){
  picked_words = new string*[grid_size];
  for (int i=0; i<grid_size; i++){
    picked_words[i] = new string[grid_size];
  }
  string strChoice, myword;
  char choice;

  cout<< "Please type the words from the pool that you would like to place in the cells" <<endl;
  for (int m=0; m<grid_size; m++){
    for (int n=0; n<grid_size; n++){
      bool isValid = false;

      while(!isValid){
        cout << "Row: "<<(m+1)<<", column: "<<(n+1)<<" --> ";
        cin>> myword;
        //check if the word is vaild, i.e. exists in the pool
        if (check_words(myword, word_pool)==false){
          cout << "That word does not exist in the pool. Do you want to view the pool again? (Y/N)" <<endl;
          cin >> strChoice;
          choice = strChoice.at(0);
          choice = tolower(choice);

          while(strChoice.length()!=1 || (choice!='y' && choice!='n')){
            cout << "Invalid response. (Y/N)"<<endl;
            cin >> strChoice;
            choice = strChoice.at(0);
            choice = tolower(choice);
          }

          if (choice=='y'){
            show_pool(word_pool);}

          else if (tolower(choice)=='n'){
            cout<< "Please input a word again" <<endl;
          }
        }
        else{
          picked_words[m][n] = myword;
          isValid = true;
        }
      }
    }
  }
}
