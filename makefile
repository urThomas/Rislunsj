#Setting location of Header Files
IDIR2=./
#defining compiler
CC=gcc

#setting the flags for the compiler
CFLAGS=-Wall  -I$(IDIR2)  
#setting source code
SRC = main.c ADC_driver.h io.c track_simulation.c 

test_benchmake: $(SRC)
	$(CC) -o test_bech.o $(SRC) $(CFLAGS) -lwiringPi -phtread -std=c99









