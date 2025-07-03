NAME := webserv
# NAME := test

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -rf

# HEADERS := 
HEADERS := Logger.hpp WebServer.hpp ft_utils.hpp \
	HTTPMessage/Request.hpp HTTPMessage/Response.hpp HTTPMessage/AHTTPMessage.hpp

SRCS := main.cpp \
	WebServer.cpp \
	Logger.cpp ft_utils.cpp \
	HTTPMessage/AHTTPMessage.cpp HTTPMessage/Request.cpp HTTPMessage/Response.cpp  
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
