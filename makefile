./bin/encodeInput: ./obj/main.o ./obj/validations.o ./obj/asmEncoding.o ./obj/srecEncoding.o
	cc -g ./obj/main.o ./obj/validations.o ./obj/asmEncoding.o ./obj/srecEncoding.o -o ./bin/encodeInput

./obj/main.o: ./src/main.c ./inc/functions.h
	cc -g -I./inc -c ./src/main.c -o ./obj/main.o

./obj/validations.o: ./src/validations.c ./inc/functions.h
	cc -g -I./inc -c ./src/validations.c -o ./obj/validations.o

./obj/asmEncoding.o: ./src/asmEncoding.c ./inc/functions.h
	cc -g -I./inc -c ./src/asmEncoding.c -o ./obj/asmEncoding.o

./obj/srecEncoding.o: ./src/srecEncoding.c ./inc/functions.h
	cc -g -I./inc -c ./src/srecEncoding.c -o ./obj/srecEncoding.o

all: ./bin/encodeInput

clean:
	rm -f ./bin/*
	rm -f ./obj/*.o
