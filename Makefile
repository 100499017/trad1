all: back6

back6: back6.tab.c
	gcc back6.tab.c -o back6 -lfl -w
	rm -f back6.tab.c back6.tab.h

back6.tab.c back6.tab.h: back6.y
	bison -d back6.y

clean:
	rm -f back6