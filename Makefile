all: trad9

trad9: trad9.tab.c
	gcc trad9.tab.c -o trad9 -lfl -w

trad9.tab.c trad9.tab.h: trad9.y
	bison -d trad9.y

clean:
	rm -f trad9.tab.c trad9.tab.h trad9