NAME := test

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -rf

HEADERS := ../../headers/Tokenizer/Tokenizer.hpp ../../headers/Tokenizer/Tokens.hpp \
	../../headers/Config/WebServerConfig.hpp ../../headers/Config/ServerConfig.hpp ../../headers/Config/LocationBlock.hpp \
	../../headers/utils/ft_utils.hpp \

SRCS := test.cpp \
	Tokenizer.cpp Tokens.cpp \
	../Config/WebServerConfig.cpp ../Config/ServerConfig.cpp ../Config/LocationBlock.cpp \
	../utils/ft_utils.cpp \

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
