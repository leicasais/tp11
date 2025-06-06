cc:= gcc -Wall

tp11: main.o hardware.o
	${cc} main.o hardware.o -o tp11

main.o: main.c hardware.h 
	${cc} main.c -c
hardware.o: hardware.c hardware.h
	${cc} hardware.c -c 

clean:
	rm * .o tp11
