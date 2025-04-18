NAME = m05ex03

CXX = c++

CXXFLAGS = -std=c++98 -Werror -Wextra -Wall

DIRECTORY = ./

FILES = Bureaucrat.cpp	\
		AForm.cpp		\
		ShrubberyCreationForm.cpp	\
		RobotomyRequestForm.cpp		\
		PresidentialPardonForm.cpp	\
		Intern.cpp	\
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
