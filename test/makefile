.PHONE : clean

all : bin/CVariant bin/CSimpleType bin/CCString
	@echo Executing 
	@for f in $^; do printf " - $$f ... "; $$f; printf "Done\n"; done

bin/% : %.cpp
	@printf "Compiling $@ ... "
	@g++ -g -fsanitize=leak -I./../header -L./../bin -o $@ $^ -lVariant
	@printf "Done\n"

clean :
	rm bin/*
