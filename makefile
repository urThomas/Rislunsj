#Setting location of Header Files
IDIR2=./
#defining compiler
CC=gcc

#setting the flags for the compiler
CFLAGS=-Wall  #-I$(IDIR2)  
#setting source code
SRC = main.c ADC_driver.c io.c track_simulation.c 

benchmake:$(SRC)
	$(CC) -o bench $(SRC) $(CFLAGS) -lwiringPi -lpthread -std=c99 -lm









