all: trad11

trad11: trad11.tab.c
	gcc trad11.tab.c -o trad11 -lfl -w

trad11.tab.c trad11.tab.h: trad11.y
	bison -d trad11.y

clean:
	rm -f trad11.tab.c trad11.tab.h trad11