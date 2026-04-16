all: back7

back7: back7.tab.c
	gcc back7.tab.c -o back7 -lfl -w
	rm -f back7.tab.c back7.tab.h

back7.tab.c back7.tab.h: back7.y
	bison -d back7.y

clean:
	rm -f back7