CC = cc

all:
	$(CC) -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b

program: all
	bin/gauss dane/A dane/b dane/x