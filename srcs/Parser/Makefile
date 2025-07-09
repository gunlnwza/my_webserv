NAME := test

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -rf

HEADERS := ../../headers/Parser/Tokenizer.hpp ../../headers/Parser/Tokens.hpp ../../headers/Parser/Parser.hpp \
	../../headers/Config/WebServerConfig.hpp ../../headers/Config/ServerConfig.hpp ../../headers/Config/RouteConfig.hpp \
	../../headers/utils/ft_utils.hpp \

SRCS := test.cpp \
	Tokenizer.cpp Tokens.cpp Parser.cpp \
	../Config/WebServerConfig.cpp ../Config/ServerConfig.cpp ../Config/RouteConfig.cpp \
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
