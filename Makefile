NAME := webserv
# NAME := test

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -rf

# HEADERS := 
HEADERS := Logger.hpp WebServer.hpp Request.hpp Response.hpp 

SRCS := main.cpp Logger.cpp WebServer.cpp Request.cpp Response.cpp
# SRCS := Request.cpp
# SRCS := Response.cpp
# SRCS := WebServer.cpp Logger.cpp main.cpp

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
