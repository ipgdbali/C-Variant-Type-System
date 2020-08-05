.PHONY : clean run all

all : bin/libVariant.a

bin/libVariant.a : bin/CVariant.o bin/CTypedVariant.o bin/CValueType.o bin/CCString.o
	@printf "Making library $@ ... "
	@ar rcs $@ $^
	@printf "done\n"

bin/%.o : source/%.cpp
	@printf "Compiling $@ ... "
	@g++ -c -g -fsanitize=leak -o $@ -Iheader $<
	@printf "done\n"

clean : 
	@printf "Cleaning binary folder ... "
	@rm bin/*
	@printf "done\n"

