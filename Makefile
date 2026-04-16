all: back5

back5: back5.tab.c
	gcc back5.tab.c -o back5 -lfl -w
	rm -f back5.tab.c back5.tab.h

back5.tab.c back5.tab.h: back5.y
	bison -d back5.y

clean:
	rm -f back5