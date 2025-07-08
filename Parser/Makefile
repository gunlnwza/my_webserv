NAME := test

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -rf

HEADERS := Tokenizer.hpp Tokens.hpp ../utils/ft_utils.hpp

SRCS := Tokenizer.cpp Tokens.cpp test.cpp ../utils/ft_utils.cpp

OBJS := $(SRCS:%.cpp=%.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
