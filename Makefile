all: trad10

trad10: trad10.tab.c
	gcc trad10.tab.c -o trad10 -lfl -w

trad10.tab.c trad10.tab.h: trad10.y
	bison -d trad10.y

clean:
	rm -f trad10.tab.c trad10.tab.h trad10