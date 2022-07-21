main:
	gcc -std=c++20 src/*.cpp -o game.run -lSDL2 -lSDL2main -lstdc++

clear:
	rm game.run