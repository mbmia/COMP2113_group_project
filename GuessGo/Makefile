#Makefile for GuessGo#
FLAGS = -pedantic-errors -std=c++11

get_input.o: guessgo.h get_input.cpp
	g++ $(FLAGS) -c get_input.cpp
select_words.o: guessgo.h select_words.cpp
	g++ $(FLAGS) -c select_words.cpp
show_pool.o: guessgo.h show_pool.cpp
	g++ $(FLAGS) -c show_pool.cpp
check_words.o: guessgo.h check_words.cpp
	g++ $(FLAGS) -c check_words.cpp

pick_user_words.o: guessgo.h pick_user_words.cpp
	g++ $(FLAGS) -c pick_user_words.cpp
pick_computer_words.o: guessgo.h pick_computer_words.cpp
	g++ $(FLAGS) -c pick_computer_words.cpp
do_toss.o: guessgo.h do_toss.cpp
	g++ $(FLAGS) -c do_toss.cpp
get_user_guess.o: guessgo.h get_user_guess.cpp
	g++ $(FLAGS) -c get_user_guess.cpp
get_computer_guess.o: guessgo.h get_computer_guess.cpp
	g++ $(FLAGS) -c get_computer_guess.cpp
check_guess.o: guessgo.h check_guess.cpp
	g++ $(FLAGS) -c check_guess.cpp
get_winner.o: guessgo.h get_winner.cpp
	g++ $(FLAGS) -c get_winner.cpp

user_play.o: guessgo.h user_play.cpp
	g++ $(FLAGS) -c user_play.cpp
computer_play.o: guessgo.h computer_play.cpp
	g++ $(FLAGS) -c computer_play.cpp
view_my_list.o: guessgo.h view_my_list.cpp
	g++ $(FLAGS) -c view_my_list.cpp
guessgo_main.o: guessgo.h guessgo_main.cpp
	g++ $(FLAGS) -c guessgo_main.cpp
guessgo_main: get_input.o select_words.o show_pool.o check_words.o pick_user_words.o pick_computer_words.o do_toss.o get_user_guess.o get_computer_guess.o check_guess.o get_winner.o user_play.o computer_play.o view_my_list.o guessgo_main.o
	g++ $(FLAGS) get_input.o select_words.o show_pool.o check_words.o pick_user_words.o pick_computer_words.o do_toss.o get_user_guess.o get_computer_guess.o check_guess.o get_winner.o user_play.o computer_play.o  view_my_list.o guessgo_main.o -o guessgo_main
clean:
	rm -f *o guessgo_main
.PHONY: clean
