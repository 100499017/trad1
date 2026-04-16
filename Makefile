all: back8

back8: back8.tab.c
	gcc back8.tab.c -o back8 -lfl -w
	rm -f back8.tab.c back8.tab.h

back8.tab.c back8.tab.h: back8.y
	bison -d back8.y

clean:
	rm -f back8