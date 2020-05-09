## Group 33
MIA MD BAYEZID, UID: 3035603227  
Najia SHARMIN, UID: 3035550860

## Game description and game structure:  
Name of game: __GuessGo__  
  
Mode of play: Single user versus computer  
  
GuessGo is a game of probability where the players fill a virtual grid with words from a (partially) randomized pool. The players then each take turns to call out words from the pool and the opponent marks it out if it appears on their grid. The objective of the game is to be able to guess a whole row/column on the opponent's grid, with the first player to do so becoming the winner of the game.  
  
The set of rules governing GuessGo is laid out below:  
- The game starts with the user choosing the grid size they would like to play with. The virtual grid would be of the dimensions n×n, where the minimum value of n is 3 and the maximum is 15.  
- The game asks the user for the size of the pool of words that should be provided for the game. The minimum size of the pool is n^2 and the maximum is 500.  
- If no input for the pool size is provided, the game proceeds with a default pool size of 100 words if the grid has less than or equal to a hundred blocks (n<=10) and 225 if the number of blocks is greater (10<n<=15).  
- When n is greater than 10, the 'hitword' mechanism is activated. It is explained in more detail below.  
- The pool of words is provided. User chooses words from the pool for every block of their virtual grid. The computer also fills its grid by drawing words from the pool randomly.  
- Each word from the pool can only be used once by each player.  
- The user and the computer have a toss to determine who would play first.  
- The first player calls out a word from the pool of words provided. If the opponent has that particular word on their grid, the block containing the word is 'crossed out'. If the word does not appear on their grid, no action is taken.  
  -   The user calls out words from the pool by typing it into the interface. The computer calls out words at random.  
  -  Each word can only be called once.  
- The user and the computer take turns calling out words and crossing out blocks. This continues until on either's grid, one row/column has been completely crossed out. It does not count if the blocks are crossed out at a stretch diagonally.  
- The game comes to an end. The player who has been able to guess the all the words in a row/column in the opponent's grid is declared the winner.  
  
## A list of features/functions that we implemented

- *previous_game()*: Function to check if there are any saved games

- *restore_game()*: Function to restore the previous saved game when the player wants to resume last attempt

- *get_input()*: Function to take the input of the size of the grid and the pool size.

- *select_words()*: Function to randomly select the pool of  words from a .txt file. The pool is then displayed for the first time. The pool is also stored in a vector of strings named *pool* in alphabetical order.

- *show_pool()*: Function to show the pool of words whenever necessary.

- *pick_user_words()*: Function to let the user pick words for the grid. Words stored in a dynamic 2D array of strings named *userwordlist*.Grid displayed.

- *pick_computer_words()*: Function to let the computer pick its words randomly. Words stored in another dynamic 2D array named *computerwordlist*.

- *check_words()*: Function to check if the picks are valid.

- *do_toss()*: Function to have a toss to select who guesses first.

- *check_guess()*: Function to verify computer's and user's guesses. I is made sure the guessed word, if present in the user/computer's grid, is replaced with X in the same dynamic array.

- *get_winner()*: Function to check for the winner.

- *start_options()*: Function to display the options at the start of the game.

- *print_rules()*: Function to display the rules of GuessGo from a separate .txt file called *rulebook.txt* in *txt_files* directory.
		
- *main()*: The main function controls the game-flow. Note that the user and computer will be asked for calling out guesses in this function by calling out two different functions, i.e. *user_play()* and *computer_play()* respectively. There
  will be an option to end the game. If the game is ended by the user, then all the updated arrays, vectors and the numbers will be stored in several
  output files (by a separate function, *save_game()*), i.e. *save_pool.txt* for saving the pool of words, *save_picked_words.txt* to save the user's grid, *save_computer_wordlist.txt* to save the computer's grid, and *save_sizes.txt* to store the toss result, grid_size and pool_size. The next time the user wants to play the game, s/he will be asked if they want to resume the last trial
  or start a new game. If the last game is resumed, then all the information is taken from the previously saved file and the game is
  continued. Another function, namely the *restore_game()* function will be implemented for this.








