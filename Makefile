#Makefile for GuessGo#
FLAGS = -pedantic-errors -std=c++11
previous_game.o: header.h previous_game.cpp
  g++ $(FLAGS) -c previous_game.cpp
restore_game.o: header.h restore_game.cpp
  g++ $(FLAGS) -c restore_game.cpp
get_input.o: header.h get_input.cpp
  g++ $(FLAGS) -c get_input.cpp
select_words.o: header.h select_words.cpp
  g++ $(FLAGS) -c select_words.cpp
show_pool.o: header.h show_pool.cpp
  g++ $(FLAGS) -c show_pool.cpp
check_words.o: sheader.h check_words.cpp
  g++ $(FLAGS) -c check_words.cpp

pick_user_words.o: header.h pick_user_words.cpp
  g++ $(FLAGS) -c pick_user_words.cpp
pick_computer_words.o: header.h pick_computer_words.cpp
   g++ $(FLAGS) -c pick_computer_words.cpp
do_toss.o: header.h do_toss.cpp
  g++ $(FLAGS) -c do_toss.cpp
get_user_guess.o: header.h get_user_guess.cpp
  g++ $(FLAGS) -c get_user_guess.cpp
get_computer_guess.o: header.h get_computer_guess.cpp
  g++ $(FLAGS) -c get_computer_guess.cpp
check_guess.o: header.h check_guess.cpp
  g++ $(FLAGS) -c check_guess.cpp
get_winner.o: header.h get_winner.cpp
  g++ $(FLAGS) -c get_winner.cpp
save_game.o: header.h save_game.cpp
  g++ $(FLAGS) -c save_game.cpp

user_play.o: header.h user_play.cpp
  g++ $(FLAGS) -c user_play.cpp
computer_play.o: header.h computer_play.cpp
  g++ $(FLAGS) -c computer_play.cpp
start_options.o: header.h start_options.cpp
  g++ $(FLAGS) -c start_options.cpp
view_my_list.o: header.h view_my_list.cpp
  g++ $(FLAGS) -c view_my_list.cpp
print_rules.o: header.h print_rules.cpp
  g++ $(FLAGS) -c print_rules.cpp
guessgo_main.o: header.h guessgo_main.cpp
  g++ $(FLAGS) -c guessgo_main.cpp
guessgo_main: previous_game.o restore_game.o get_input.o select_words.o show_pool.o check_words.o pick_user_words.o pick_computer_words.o do_toss.o get_user_guess.o get_computer_guess.o check_guess.o get_winner.o save_game.o user_play.o computer_play.o start_options.o view_my_list.o print_rules.o guessgo_main.o
  g++ $(FLAGS) previous_game.o restore_game.o get_input.o select_words.o show_pool.o check_words.o pick_user_words.o pick_computer_words.o do_toss.o get_user_guess.o get_computer_guess.o check_guess.o get_winner.o save_game.o user_play.o computer_play.o start_options.o view_my_list.o print_rules.o guessgo_main.o - guessgo_main
clean:
  rm -f *o guessgo_main()
.PHONY: clean
