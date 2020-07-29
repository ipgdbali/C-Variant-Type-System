.PHONY : clean run all

all : bin/libVariant

bin/libVariant : bin/CVariant.o bin/CTypedVariant.o bin/CStronglyTyped.o bin/CInt.o bin/CUInt.o
	@printf "Making library ... "
	@ar rcs $@ $^
	@printf "done\n"

bin/%.o : source/%.cpp
	@printf "Compiling $@ ... "
	@g++ -c -g -fsanitize=leak -o $@ -Iheader $<
	@printf "done\n"

clean	: bin/libVariant
	@printf "Cleaning binary folder ... "
	@rm bin/*
	@printf "done\n"

