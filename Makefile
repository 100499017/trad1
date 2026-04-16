all: back1

back1: back1.tab.c
	gcc back1.tab.c -o back1 -lfl -w
	rm -f back1.tab.c back1.tab.h

back1.tab.c back1.tab.h: back1.y
	bison -d back1.y

clean:
	rm -f back1