.PHONE : clean

all : bin/CAdapterInt

bin/% : %.cpp
	g++ -I./../header -L./../bin -o $@ $^ -lVariant

clean :
	rm bin/*
