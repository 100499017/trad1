all: back3

back3: back3.tab.c
	gcc back3.tab.c -o back3 -lfl -w
	rm -f back3.tab.c back3.tab.h

back3.tab.c back3.tab.h: back3.y
	bison -d back3.y

clean:
	rm -f back3