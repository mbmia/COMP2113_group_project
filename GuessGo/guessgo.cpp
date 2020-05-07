#include <iostream>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<ctime>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


//function to check if there are any saved games
bool previous_game();

//function to restore the saved game
void restore_game();

//function to take input for the size of grid and pool
void get_input(int& grid_size, int& pool_size){
  char reply;
  bool looper = false;

  cout << "In GuessGo, your virtual grid will have the same number of rows and columns" <<endl;
  cout<< "How many rows/columns would you like your grid to have? (It must be between 3 and 15!)"<<endl;
  cin >> grid_size;

  while (grid_size<3 || grid_size>15){
    cout << "Your choice is out of range. Please try again." <<endl;
    cin >> grid_size;
  }
  cout <<endl;

  int nsquared = grid_size*grid_size;

  cout << "Do you have a preference for the number of words you'll play with? (Y/N)" <<endl;
  cin >> reply;

  while (!looper){
    if ( reply == 'Y'){
      cout << "How many words would you like to be able to choose from? You can choose any number between "
           <<nsquared <<" and 500." <<endl;
      cin >> pool_size;

      while (pool_size<grid_size*grid_size || pool_size>500){
        cout << "Your choice is out of range. Please choose a number between "<<nsquared <<" and 500" <<endl;
        cin >> pool_size;
      }
      looper = true;
    }

    else if (reply == 'N'){
      cout << "Proceeding with the default pool size..." <<endl;

      if (grid_size<=10)
        pool_size = 100;
      else if (grid_size>10 && grid_size <= 15)
        pool_size = 225;

      looper = true;
    }

    else
      cout << "Invalid input, please try again" <<endl;
  }
}

// function to randomly select words from word_list.txt
//and store them in a vector in alphabetical order
void select_words(int pool_size, vector<string> &wordarray){
  int n  = 0;
  vector<int> numarray;

  srand(time(NULL));
  for (int i = 0; i<pool_size; i++){
    n = rand()%3250;

    if (i==0){
      numarray.push_back(n); }

    else{
      if(find(numarray.begin(), numarray.end(), n) != numarray.end()) {
        i--;
        continue;
      }
      else {
        numarray.push_back(n);
       }
    }
  }

  sort(numarray.begin(), numarray.end());

  string mypath = "txt_files/word_list.txt";
  ifstream fin;
  fin.open(mypath.c_str());

  if (fin.fail()){
    cout << "Sorry, the game has to quit due to an error"<<endl;
    exit(0);
  }
  string myline;
  int mypointer = 0;
  int k = 0;

  while(getline(fin, myline) && mypointer < 3250){
    mypointer++;
    if (mypointer==numarray[k]){
      cout << myline << endl;
      wordarray.push_back(myline);
      k++;
    }
  }
}

//function to let user pick words for their grid
void pick_words();

//function to check if the picks are valid
void check_words();

//function to select who guesses first
bool do_toss(){
  srand(time(NULL));
  char pick;
  cout<<"Do you want to pick first?(Y/N)"<<endl;
  cin>>pick;
  pick=tolower(pick);
  while (pick!='y' && pick!='n'){
    cout<<"Invaid choice.(Y/N)"<<endl;
    cin>>pick;
    pick=tolower(pick);
  }
  if (pick=='y'){
    cout<<"H or T?"<<endl;
    cin>>pick;
    pick=tolower(pick);
    while (pick!='h'&& pick!='t'){
      cout<<"Invalid choice.(H or T)"<<endl;
      cin>>pick;
      pick=tolower(pick);
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




// function to verify the computer and user's guesses
void check_guess();

// function to cross out guessed words
void call_out();

//function to check for the winner
void get_winner();

//function to save game for later
void save_game();

//function to control game flow
void play_game();

//declaration of print_rules()
void print_rules();

//function for options at the start of games
void start_options(){
  int answer;

  cout << "To view the rules, press 1" << endl;
  cout << "To start a new game, press 2" <<endl;

  if (previous_game){
    cout << "To continue the previous game, press 3" << endl;
  }

    cin >> answer;

    if (answer == 1){
      cout << '\n';
      print_rules(); }

    else if (answer == 2){
      play_game();
    }

    else if (answer==3){
      restore_game();
      return; }

    else{
      cout << "Invalid input. Please try again." << endl;
      cin >> answer; }
}

//function to print an introduction to the game
void print_rules(){
  char ans;
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
    if (ans == 'Y'){
      start_options();
      keeplooping = true;
    }
    else if (ans == 'N'){
      cout << "You have exited the game."<<endl;
      exit(0);
    }

    else
      cout << "Invalid input. Please try again"<<'\n'<<endl;
  }

  string x;
  while (fin >> x){
    cout << x << " ";
  }

  cout << '\n' <<endl;

  fin.close();
  start_options();
}

int main(){
  return 0;
}
