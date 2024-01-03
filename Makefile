make:
	gcc -Wall -std=c99 game.c -lSDL2 -o game

run:
	./game

clean:
	rm game
