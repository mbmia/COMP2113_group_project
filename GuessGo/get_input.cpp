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

//function to take input for the size of grid and pool
void get_input(int& grid_size, int& pool_size){
  string reply, gridsize;
  bool looper = false;

  cout << "In GuessGo, your virtual grid will have the same number of rows and columns" <<endl;
  cout<< "How many rows/columns would you like your grid to have? (It must be between 3 and 15!)"<<endl;
  bool keeplooping = false;

  while(!keeplooping){
  grid_size = 0;
  cin >> gridsize;

  try{
    grid_size = stoi(gridsize);
  }
  catch(invalid_argument const &e){
    cout << "Please input an integer" <<endl;
  }

  if (grid_size>=3 && grid_size<=15){
    keeplooping = true;
  }

  else if (grid_size==0){
    continue;
  }

  else{
    cout << "Your choice is out of range. Please try again." <<endl;
  }
}


  cout <<endl;

  int nsquared = grid_size*grid_size;

  cout << "Do you have a preference for the number of words you'll play with? (Y/N)" <<endl;
  cin >> reply;

  while(reply.length()!=1 || (reply.at(0)!='y' && reply.at(0)!='n')){
    cout << "Invalid input. (Y/N)" <<endl;
    cin >> reply;
  }

  if ( tolower(reply.at(0)) == 'y'){
    cout << "How many words would you like to be able to choose from? You can choose any number between "
           <<nsquared <<" and 500." <<endl;
    cin >> pool_size;

    while (pool_size<grid_size*grid_size || pool_size>500){
      cout << "Your choice is out of range. Please choose a number between "<<nsquared <<" and 500" <<endl;
      cin >> pool_size;
      }
    }

  else if (tolower(reply.at(0)) == 'n'){
    cout << "Proceeding with the default pool size..." <<endl;

    if (grid_size<=10)
      pool_size = 100;
    else if (grid_size>10 && grid_size <= 15)
      pool_size = 225;
    }
  }
