# compiler flag
CXX = g++
CFLAGS = -Wall -ansi -pedantic -g -std=c++0x -c -Wall -I ./include 

# linker flags
LIBS = -lGL -lGLU -lSDL -lSDL_ttf -lSDL_image -lluabind -llua5.1 

# list of cpp sources
SOURCES = src/main.cpp src/App.cpp src/Property.cpp src/Resource.cpp \
		  src/Game.cpp src/Writer.cpp src/Player.cpp src/Play.cpp \
		  src/Menu.cpp src/Renderer.cpp src/MenuItem.cpp src/Sprite.cpp \
		  src/Highscore.cpp src/SpriteManager.cpp src/MapManager.cpp \
		  src/Map.cpp src/LiveBar.cpp src/SoundManager.cpp src/Splash.cpp \
		  src/RendererGL.cpp src/Logger.cpp src/EnemyManager.cpp \
		  src/Enemy.cpp src/Background.cpp

# extension compiled cpp file
OBJECTS=$(SOURCES:.cpp=.o)

# name of output file
EXECUTABLE = AstroRush.bin

# build all game
all: $(SOURCES) $(EXECUTABLE)
	 @echo "\n ---- Udało się ---- "

# linking application
$(EXECUTABLE): $(OBJECTS) 
	 @echo "\n ---- Linkowanie ---- "
	$(CC)  $(OBJECTS)  -o $(EXECUTABLE) $(LIBS)

# compile cpp files
.cpp.o:
	 @echo "Kompilowanie pliku: $<"
	 @$(CXX) $(CFLAGS) $< -o $@ 

# remove temporary file and binary  
clean:
	rm -rf ./src/*.o
	rm ./AstroRush.bin
	@echo "Wyczyszczono"
