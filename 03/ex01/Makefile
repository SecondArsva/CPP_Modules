NAME = serena_my_love

CXX = g++

CXXFLAGS = -std=c++98 -Werror -Wextra -Wall

DIRECTORY = ./

FILES = ClapTrap.cpp	\
		ScavTrap.cpp	\
		main.cpp

SOURCES  := $(addprefix $(DIRECTORY),$(FILES))

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
