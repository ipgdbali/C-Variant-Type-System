.PHONE : clean

all : bin/CVariant

bin/% : %.cpp
	g++ -I./../header -L./../bin -o $@ $^ -lVariant

clean :
	rm bin/*
