all: trad8

trad8: trad8.tab.c
	gcc trad8.tab.c -o trad8 -lfl -w

trad8.tab.c trad8.tab.h: trad8.y
	bison -d trad8.y

clean:
	rm -f trad8.tab.c trad8.tab.h trad8