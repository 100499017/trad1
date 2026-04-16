all: back4

back4: back4.tab.c
	gcc back4.tab.c -o back4 -lfl -w
	rm -f back4.tab.c back4.tab.h

back4.tab.c back4.tab.h: back4.y
	bison -d back4.y

clean:
	rm -f back4