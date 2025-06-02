NAME = m05ex00

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -MP

DIRECTORY = ./
FILES = Bureaucrat.cpp	\
		main.cpp

SOURCES := $(addprefix $(DIRECTORY),$(FILES))
OBJECTS := $(SOURCES:.cpp=.o)
DEPS := $(OBJECTS:.o=.d)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

-include $(DEPS)

clean:
	$(RM) $(OBJECTS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
