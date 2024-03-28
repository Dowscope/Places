COMPILER := gcc
STANDARD := c++20
OUTPUT := game.run
LIBRARIES := -lSDL2 -lSDL2main -lstdc++
FILES := src/*.cpp

main:
	$(COMPILER) -std=$(STANDARD) $(FILES) -o $(OUTPUT) $(LIBRARIES)

clear:
	rm -f $(OUTPUT)