.PHONY : clean run all

all : bin/main

bin/main : main.cpp bin/CVariant.o
	@printf "Making binary main ... "
	@g++ -fsanitize=leak -g -o bin/main -Iheader main.cpp bin/CVariant.o
	@printf "done\n"

bin/CVariant.o : source/CVariant.cpp
	@printf "Compiling CVariant ... "
	@g++ -c -g -fsanitize=leak -o bin/CVariant.o -Iheader source/CVariant.cpp
	@printf "done\n"

run	: bin/main
	@./bin/main

clean	: bin/main
	@printf "Cleaning binary folder ... "
	@rm bin/*
	@printf "done\n"

