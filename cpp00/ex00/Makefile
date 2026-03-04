
NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
SRC = Megaphone.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re