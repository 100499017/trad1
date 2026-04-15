all: trad12

trad12: trad12.tab.c
	gcc trad12.tab.c -o trad12 -lfl -w

trad12.tab.c trad12.tab.h: trad12.y
	bison -d trad12.y

clean:
	rm -f trad12.tab.c trad12.tab.h trad12