MIA MD BAYEZID, UID: 3035603227  
Najia SHARMIN, UID: 3035550860

## Game description and game structure:  
Name of game: __GuessGo__  
  
Mode of play: Single user versus computer  
  
GuessGo is a game of probability where the players fill a virtual grid with words from a (partially) randomized pool. The players then each take turns to call out words from the pool and the opponent marks it out if it appears on their grid. The objective of the game is to be able to guess a whole row/column on the opponent’s grid, with the first player to do so becoming the winner of the game.  
  
The set of rules governing GuessGo is laid out below:  
- The game starts with the user choosing the grid size they would like to play with. The virtual grid would be of the dimensions n\*n, where the minimum value of n is 3 and the maximum is 15.  
- The game asks the user for the size of the pool of words that should be provided for the game. The minimum size of the pool is n2 and the maximum is 500.  
- If no input for the pool size is provided, the game proceeds with a default pool size of 100 words if the grid has less than or equal to a hundred blocks (n<=10) and 225 if the number of blocks is greater (10<n<=15).  
- When n is greater than 10, the ‘hitword’ mechanism is activated. It is explained in more detail below.  
- The pool of words is provided. User chooses words from the pool for every block of their virtual grid. The computer also fills its grid by drawing words from the pool randomly.  
- Each word from the pool can only be used once by each player.  
- The user and the computer have a toss to determine who would play first.  
- The first player calls out a word from the pool of words provided. If the opponent has that particular word on their grid, the block containing the word is ‘crossed out’. If the word does not appear on their grid, no action is taken.  
  -   The user calls out words from the pool by typing it into the interface. The computer calls out words at random.  
  -  Each word can only be called once.  
- The user and the computer take turns calling out words and crossing out blocks. This continues until on either’s grid, one row/column has been completely crossed out. It does not count if the blocks are crossed out at a stretch diagonally.  
- The game comes to an end. The __*opponent*__ of the player whose grid has an entire row/column crossed out is declared the winner of the game.  
- __The ‘*hitword*’ mechanism:__  
  - When the grid size is greater than 10\*10, the pool will contain 6 ‘*hitword*’.
  - Each player can choose no more than three hitwords. The computer will always choose the maximum permissible number of *hitwords*.  
  - When a player chooses the *hitword*, the block on the opponent’s grid containing the word is crossed out as normal.  
  - However, when a word in a block immediately adjacent to the *hitword* is chosen by the opponent, the *hitword* is activated and the game ends.  
  - The player whose *hitword* has been activated is the winner of the game.
  - If no *hitword* has been activated, the game proceeds as normal.








