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

//function to select who guesses first
bool do_toss(){
  srand(time(NULL));
  string myPick;
  char pick;
  cout<<"\nIt's time for a toss. Do you want to pick first?(Y/N)"<<endl;
  cin>>myPick;
  pick=tolower(myPick.at(0));

  while (myPick.length()!=1 ||( pick!='y' && pick!='n')){
    cout<<"Invalid choice.(Y/N)"<<endl;
    cin>>myPick;
    pick=tolower(myPick.at(0));
  }
  if (pick=='y'){
    cout<<"H or T?"<<endl;
    cin>>myPick;
    pick=tolower(myPick.at(0));
    while (myPick.length()!=1 ||( pick!='h' && pick!='t')){
      cout<<"Invalid choice.(H or T)"<<endl;
      cin>>myPick;
      pick=tolower(myPick.at(0));
    }
    int toss=rand()%2;
    if ((toss==0&&pick=='h')||(toss==1&&pick=='t')){
      cout<<"Congratulations, you won the toss! You will guess first.\n"<<endl;
      return true;
    }
    else {
      cout<<"You lost the toss! Computer guesses first.\n"<<endl;
      return false;
    }
  }
   else {
    int choice_toss=rand()%2;
    if (choice_toss==0){
      pick='h';
      cout<<"Computer chooses Head!"<<endl;
    }
    else{
      cout<<"Computer chooses Tail!"<<endl;
      pick='t';
    }
    int toss=rand()%2;
    if ((toss==0&&pick=='h')||(toss==1&&pick=='t')) {
      cout<<"You lost the toss! Computer guesses first.\n"<<endl;
      return false;
    }
    else {
      cout<<"Congratulations, you won the toss! You will guess first.\n"<<endl;
      return true;
    }
   }
}
