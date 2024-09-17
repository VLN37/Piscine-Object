NAME    = ex.exe

CC      = clang++
CFLAGS  = -g3 -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -MP
SRC     = main.cpp \

INC     = car.hpp \
          GearLever.hpp \
          Gear.hpp \
          Pedal.hpp \
          ALinkablePart.hpp \
          Injector.hpp \
          ExplosionChamber.hpp \
          Crankshaft.hpp \
          Motor.hpp \

INCPATH = -I./src -I./src/cockpit -I./src/interfaces -I./src/motor -I./src/parts

OBJDIR  = obj
OBJ     = $(SRC:%.cpp=$(OBJDIR)/%.o)
DEPS    = $(SRC:%.cpp=$(OBJDIR)/%.d)

vpath %.cpp src
vpath %.hpp src src/cockpit src/interfaces src/motor src/parts

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCPATH)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

re: fclean all

run: all
	valgrind ./$(NAME)

-include $(DEPS)
