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

//function headers

//function to check if there are any saved games
bool previous_game();

//function to restore the saved game
void restore_game(int &grid_size, int &pool_size, bool &tossResult,string** &computerwordlist, string** &userwordlist, vector<string>pool);

//function to take input for the size of grid and pool
void get_input(int& grid_size, int& pool_size);

// function to randomly select words from word_list.txt to form a pool
//and store them in a vector in alphabetical order
void select_words(int pool_size, vector<string> &wordarray);

//function to print the pool of words
void show_pool(vector<string> pool);

//function to check if the picks are valid
//returns true if a word exists in the pool
bool check_words(string word, vector<string> pool);

//function to let user pick words for their grid
//the words chosen by the user are stored in a 2D dynamic array
void pick_user_words(int grid_size, string** &picked_words, vector<string> word_pool);

//function for the computer to pick its words (at random)
void pick_computer_words(int grid_size, int pool_size, string** &computer_wordlist, vector<string> word_pool);


//function to select who guesses first
bool do_toss();

//function to get guesses from the user
//checks if the guess exists in the pool
string get_user_guess(vector<string> pool);

//function to get computer's guess
string get_computer_guess(int pool_size, vector<string> pool, vector<int> hit_numbers);

// function to verify the computer and user's guesses
bool check_guess(int grid_size, string guess, string** &wordlist);

//function to check for the overall winner
//returns 0 if the winner is the user
//returns 1 if the winner is the computer
//dummy function for now
bool get_winner(int grid_size, string** &wordlist);

//function to save game for later
void save_game(int grid_size, int pool_size, bool &tossResult, vector<string> pool, string** &computer_wordlist, string** &picked_words);

//function to let user play
void user_play(int grid_size, string** &users_list, vector<string> pool);

//functio to let computer play
void computer_play(int grid_size, int pool_size, string** &computer_list, string** &user_list, vector<string> pool, vector<int> hit_numbers);

//function for options at the start of games
string start_options(int &grid_size, int &pool_size, bool &tossResult, string** computer_wordlist, string** user_wordlist, vector<string> pool);

//function to show the user their grid_size
void view_my_list(int grid_size, string ** mywordlist);

//function to print an introduction to the game
void print_rules(int grid_size, int pool_size, bool &tossResult, string** computer_wordlist, string** user_wordlist, vector<string> pool);



//function to check if there are any saved games
bool previous_game(){
  ifstream fin;
  fin.open("txt_files/prev_game.txt");
  if (fin.fail()){
    return false;
  }
  else {
    int game_status;
    fin>>game_status;
    if (game_status==1){
      return true;
    }
  }
  fin.close();
  return false;
}

//function to restore the saved game
void restore_game(int &grid_size, int &pool_size, bool &tossResult, string** &computerwordlist, string** &userwordlist, vector<string>pool){
  cout<<"hello"<<endl;
  ifstream fin;
  fin.open("txt_files/save_sizes.txt");
  cout<<"help!!"<<endl;
  int num;
  fin>>num;
  pool_size=num;
  fin>>num;
  grid_size=num;
  bool toss;
  fin>>toss;
  tossResult=toss;
  fin.close();
  fin.open("txt_files/save_pool.txt");
  string pool_word;
  while (fin>>pool_word){
    pool.push_back(pool_word);
  }
  fin.close();
  for (int i;i<pool_size;i++)
  cout<<pool[i]<<endl;
  grid_size=sqrt(pool_size);
  userwordlist = new string*[grid_size];
  for (int i=0; i<grid_size; i++){
    userwordlist[i] = new string[grid_size];
  }

  fin.open("txt_files/save_picked_words.txt");
  string line;
  string user_words;
  int m=0;
  while (getline(fin, line) && m<grid_size){
    istringstream iss(line);
    int n=0;
    while (iss>>user_words&& n<grid_size){
      userwordlist[m][n]=user_words;
      n++;
    }
    m++;
  }
  fin.close();
  computerwordlist = new string*[grid_size];
  for (int k=0; k<grid_size; k++){
    computerwordlist[k] = new string[grid_size];
  }

  fin.open("txt_files/save_computer_wordlist.txt");
  string comp_line;
  int i=0;
  while (getline(fin, comp_line) && i<grid_size){
    string comp_words;
    istringstream iss(comp_line);
    int j=0;
    while (iss>>comp_words&& j<grid_size){
      computerwordlist[i][j]=comp_words;
      j++;
    }
    i++;
  }
  fin.close();
  for (int k=0; k<grid_size;++k){
    for (int l=0; l<grid_size;l++){
      cout<<computerwordlist[k][l]<<"       "<<userwordlist[k][l]<<endl;
    }
  }
}

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

// function to randomly select words from word_list.txt to form a pool
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
      wordarray.push_back(myline);
      k++;
    }
  }
  fin.close();
}

//function to print the pool of words
void show_pool(vector<string> pool){
  for (int i = 0; i<pool.size();i++)
    cout << left << setw(16) << pool[i]<<endl;
}

//function to check if the picks are valid
//returns true if a word exists in the pool
bool check_words(string word, vector<string> pool){
  if ( find(pool.begin(), pool.end(), word) != pool.end())
    return true;
else
   return false;
}

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

//function for the computer to pick its words (at random)
void pick_computer_words(int grid_size, int pool_size, string** &computer_wordlist, vector<string> word_pool){
  int r  = 0;
  vector<int> p;

  srand(time(NULL));
  for (int i = 0; i<grid_size*grid_size; i++){
    r = rand()%pool_size;

    if (i==0){
      p.push_back(r); }

    else{
      if(find(p.begin(), p.end(), r) != p.end()) {
        i--;
        continue;
      }
      else {
        p.push_back(r);
       }
    }
  }

  computer_wordlist = new string*[grid_size];
  for (int k=0; k<grid_size; k++){
    computer_wordlist[k] = new string[grid_size];
  }

  int z = 0;
  for (int x = 0; x<grid_size; x++){
    for (int y=0; y<grid_size; y++){
      computer_wordlist[x][y]=word_pool[p[z]];
      z++;
    }
  }
}


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

//function to get guesses from the user
//checks if the guess exists in the pool
string get_user_guess(vector<string> pool){
    string guess, response;
    cout << "Please type in your guess:" <<endl;
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

//function to get computer's guess
string get_computer_guess(int pool_size, vector<string> pool, vector<int> hit_numbers){
  bool isHit = false;

  srand(time(NULL));
  int rnd = rand()%pool_size;

  if (hit_numbers.size()==0){
    hit_numbers.push_back(rnd);
  }

  if (hit_numbers.size()>0){
    while(!isHit){
      int rnd = rand()%pool_size;
      //if the number exists in the hit_numbers vector
      if (find(hit_numbers.begin(), hit_numbers.end(), rnd) != hit_numbers.end()){
        continue;
      }
      else{
        //guess hasn't been hit yet
        isHit = true;
      }
    }
  }

  string computer_guess = pool[rnd];
  if (check_guess){
    hit_numbers.push_back(rnd);
  }
  return computer_guess;
}

// function to verify the computer and user's guesses
bool check_guess(int grid_size, string guess, string** &wordlist){
  for (int m=0;m<grid_size;m++){
    for (int n=0;n<grid_size;n++){
      if (wordlist[m][n]==guess){
        wordlist[m][n] = "X";//instead of calling the call_out() function, we can just replace the guessed word with "X" int the array.
        return true;
      }
    }
  }
  return false;
}

//function to check for the overall winner
//returns 0 if the winner is the user
//returns 1 if the winner is the computer
//dummy function for now
bool get_winner(int grid_size, string** &wordlist){
  int flag_col=0,n=0;
  while (n<grid_size){
    for (int m=0;m<grid_size;m++){ //for the columns
      if (wordlist[m][n]!="X"){
        flag_col=1;
        break;
      }
    }
    if (flag_col==0)
      return true;
    else
      flag_col=0;
    n++;
  }
  for (int m=0;m<grid_size;m++){
    int flag_row=0;
    for (int j=0;j<grid_size;j++){  //for the rows
      if (wordlist[m][j]!="X"){
        flag_row=1;
        break;
      }
    }
    if (flag_row==0){
      return true;
    }
  }
  return false;

}

//function to save game for later
void save_game(int grid_size, int pool_size, bool &tossResult, vector<string> pool, string** &computer_wordlist, string** &picked_words){
  ofstream fout;
  fout.open("txt_files/prev_game.txt");
  fout<<1<<endl;
  fout.close();
  fout.open("txt_files/save_pool.txt");
  if (fout.fail()){
    cout<<"Sorry, there was an error in saving the game. Game status could not be saved!\n"<<endl;
  }
  else{
    fout<<endl;
    for (int i=0;i<pool_size;i++){
      fout<<pool[i]<<endl;
    }
    fout.close();
    fout.open("txt_files/save_picked_words.txt");
    if (fout.fail()){
      cout<<"Sorry, there was an error in saving the game. Game status could not be saved!\n"<<endl;
    }
    else {
      for (int m=0;m<grid_size;m++){
        for (int n=0;n<grid_size;n++){
          fout<<picked_words[m][n]<<" ";
        }
        fout<<"\n";
      }
      fout.close();
      fout.open("txt_files/save_computer_wordlist.txt");
      if (fout.fail()){
        cout<<"Sorry, there was an error in saving the game. Game status could not be saved!\n"<<endl;
      }
      else {
        for (int m=0;m<grid_size;m++){
          for (int n=0;n<grid_size;n++){
            fout<<computer_wordlist[m][n]<<" ";
          }
          fout<<"\n";
        }
        fout.close();
        ofstream fout("txt_files/save_sizes.txt");
        fout<<pool_size<<" "<<grid_size<<" "<<tossResult<<endl; //will add whose turn to guess after implementing the playgame function.
        fout.close();
      }
    }
  }
}

//function to let user play
void user_play(int grid_size, string** &computer_list, vector<string> pool){
  //user guesses
  string userguess = get_user_guess(pool);
  //guess is checked
  //the game tells user if the guess was a hit or miss
  if (check_guess(grid_size, userguess, computer_list)){
    cout << "You hit a word in the computer's grid!" <<endl;
  }
  else{
    cout << "That word is not in the computer's grid" <<endl;
  }
}

//functio to let computer play
void computer_play(int grid_size, int pool_size, string** &computer_list, string** &user_list, vector<string> pool, vector<int> hit_numbers){
  //computer guesses
  string reply;

  string computerguess = get_computer_guess(pool_size, pool, hit_numbers);
  //guess is checked
  //the game shows whether the user's word has been hit or not
  if (check_guess(grid_size, computerguess, user_list)){
    cout << "The computer hit a word in your grid" <<endl;
    cout << "\nYour grid now is: " <<endl;
    view_my_list(grid_size, user_list);
  }
  else{
    cout << "The computer's guess was a miss!" <<endl;
  }
}

void view_my_list(int grid_size, string ** mywordlist){
  int largestlength = mywordlist[0][0].length();
  for (int m = 0; m < grid_size; m++){
    for (int n = 0; n<grid_size; n++){
      if (mywordlist[m][n].length()>largestlength)
        largestlength = mywordlist[m][n].length();
    }
  }
 for (int i = 0; i<grid_size; i++){
    for (int j = 0; j<grid_size; j++){
      cout << left << setw(largestlength)<< mywordlist[i][j] <<" ";
    }
    cout << endl;
  }
}


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
      save_game(grid_size, pool_size, tossResult, pool, computerwordlist, userwordlist);
      user_play(grid_size, computerwordlist, pool);
      computer_play(grid_size, pool_size, computerwordlist, userwordlist, pool, hitnumbers);
    }
    else{
      save_game(grid_size, pool_size, tossResult, pool, computerwordlist, userwordlist);
      computer_play(grid_size, pool_size, computerwordlist, userwordlist, pool, hitnumbers);
      user_play(grid_size, computerwordlist, pool);
    }
  }
  if (get_winner(grid_size, computerwordlist)==true){
    cout << "Congrats! You have won the game :D" <<endl;
    ofstream fout;
    fout.open("txt_files/prev_game.txt");
    fout<<0<<endl;
    fout.close();
  }
  else if (get_winner(grid_size, userwordlist)==true){
    cout << "The computer won the game :(" <<endl;
    ofstream fout;
    fout.open("txt_files/prev_game.txt");
    fout<<0<<endl;
    fout.close();
  }

  return 0;
}
