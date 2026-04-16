all: back2

back2: back2.tab.c
	gcc back2.tab.c -o back2 -lfl -w
	rm -f back2.tab.c back2.tab.h

back2.tab.c back2.tab.h: back2.y
	bison -d back2.y

clean:
	rm -f back2