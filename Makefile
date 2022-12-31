#objects
OBJS = codes/*.cpp
#compiler
CC = g++
#flags
FLAGS = -w
#linkers
LINKERS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -o RIOT
all : $(OBJS)
		$(CC) $(OBJS) $(FLAGS) $(LINKERS) && ./RIOT
