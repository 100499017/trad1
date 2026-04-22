all: trad back

trad back: trad.tab.c back.tab.c
	gcc trad.tab.c -o trad -lfl -w
	gcc back.tab.c -o back -lfl -w
	rm -f trad.tab.c trad.tab.h back.tab.c back.tab.h

trad.tab.c trad.tab.h:
	bison -d trad.y

back.tab.c back.tab.h: back.y
	bison -d back.y

clean:
	rm -f trad back