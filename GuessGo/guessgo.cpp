#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


//function to check if there are any saved games
bool previous_game();

//function to restore the saved game
void restore_game();

//function to take input for the size of grid and pool
void get_input();

// function to randomly select words
void select_words();

//function to let user pick words for their grid
void pick_words();

//function to check if the picks are valid
void check_words();

//function to select who guesses first
void do_toss();

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

//function for options at the start of games
void start_options(){
  int answer;

  cout << "To view the rules, press 1" << endl;
  cout << "To start a new game, press 2" <<endl;

  if (previous_game){
    cout << "To continue the previous game, press 3" << endl;
  }

    cout << '\n';
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

  string rule_path = "txt_files/ruleook.txt";
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
