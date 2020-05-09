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
#ifndef HEADER_H
#define HEADER_H
//function headers

//function to check if there are any saved games
bool previous_game();

//function to restore the saved game
void restore_game(int &grid_size, int &pool_size,string** &computerwordlist, string** &userwordlist, vector<string>pool);

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
string start_options(int &grid_size, int &pool_size, string** computer_wordlist, string** user_wordlist, vector<string> pool);

//function to show the user their grid_size
void view_my_list(int grid_size, string ** mywordlist);

//function to print an introduction to the game
void print_rules(int grid_size, int pool_size, string** computer_wordlist, string** user_wordlist, vector<string> pool);
#endif
