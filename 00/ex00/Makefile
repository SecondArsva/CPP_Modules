NAME = megaphone

CXX = g++

CXXFLAGS = -std=c++98 -Werror -Wextra -Wall

DIRECTORY = ./

FILES = megaphone.cpp

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