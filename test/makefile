.PHONE : clean

all : bin/CVariant bin/CTypedVariant

bin/% : %.cpp
	@printf "Compiling $@ ... "
	@g++ -g -I./../header -L./../bin -o $@ $^ -lVariant
	@printf "Done\n"
	@printf "Executing $@ ... "
	@$$@
	@printf "Done\n"

clean :
	rm bin/*
