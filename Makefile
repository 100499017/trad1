all: trad7

trad7: trad7.tab.c
	gcc trad7.tab.c -o trad7 -lfl -w

trad7.tab.c trad7.tab.h: trad7.y
	bison -d trad7.y

clean:
	rm -f trad7.tab.c trad7.tab.h trad7