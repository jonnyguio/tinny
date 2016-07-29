CC = g++
CFLAGS = -Wall -std=c++11
MAIN = ./bin/main.out
SRCS = src/main.cpp src/face.cpp src/halfedge.cpp src/vertex.cpp src/interpreter.cpp src/vector2d.cpp
OBJS = $(SRCS:.cpp=.o)
CONFIG = $(shell pkg-config --cflags --libs allegro-5 allegro_color-5 allegro_dialog-5 allegro_main-5 allegro_primitives-5)

.PHONY: clean

all: $(MAIN)
	@echo "Compilation of Half-Edge Projected completed."

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS) $(CONFIG)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variables)
.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(CONFIG)

clean:
	$(RM) *.o */*.o *~ $(MAIN)
