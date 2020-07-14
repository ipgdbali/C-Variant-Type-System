.PHONY : clean run all

all : bin/main

bin/main : main.cpp bin/CVariant.o bin/CTypedVariant.o bin/CInt.o
	@printf "Making binary main ... "
	@g++ -fsanitize=leak -g -o bin/main -Iheader $^
	@printf "done\n"

bin/%.o : source/%.cpp
	@printf "Compiling $@ ... "
	@g++ -c -g -fsanitize=leak -o $@ -Iheader $<
	@printf "done\n"

run	: bin/main
	@./bin/main

clean	: bin/main
	@printf "Cleaning binary folder ... "
	@rm bin/*
	@printf "done\n"

