NAME    = ex.exe

CC      = clang++
CFLAGS  = -g3 -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -MP
SRC     = Bank.cpp \
          Account.cpp \
          main.cpp \

INC     = Bank.hpp \
          Account.hpp \

INCPATH = -I./src
OBJDIR  = obj
OBJ     = $(SRC:%.cpp=$(OBJDIR)/%.o)
DEPS    = $(SRC:%.cpp=$(OBJDIR)/%.d)

vpath %.cpp src
vpath %.hpp src

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
	./$(NAME)

-include $(DEPS)
