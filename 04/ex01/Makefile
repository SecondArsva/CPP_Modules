NAME = the_ink_spots

CXX = c++

CXXFLAGS = -std=c++98 -Werror -Wextra -Wall

DIRECTORY = ./

FILES = Animal.cpp		\
		Cat.cpp			\
		Dog.cpp			\
		WrongAnimal.cpp	\
		WrongCat.cpp	\
		Brain.cpp		\
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
