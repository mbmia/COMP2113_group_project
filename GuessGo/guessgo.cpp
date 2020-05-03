#include <iostream>
#include <fstream>
#include <iomanip>
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
