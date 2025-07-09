NAME := webserv

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -rf

HEADERS := headers/WebServer.hpp \
	headers/utils/Logger.hpp headers/utils/ft_utils.hpp headers/utils/Path.hpp \
	headers/HTTPMessage/Request.hpp headers/HTTPMessage/Response.hpp headers/HTTPMessage/AHTTPMessage.hpp \
	headers/Config/WebServerConfig.hpp headers/Config/ServerConfig.hpp headers/Config/LocationBlock.hpp \

SRCS := srcs/main.cpp \
	srcs/WebServer.cpp \
	srcs/utils/Logger.cpp srcs/utils/ft_utils.cpp srcs/utils/Path.cpp \
	srcs/HTTPMessage/AHTTPMessage.cpp srcs/HTTPMessage/Request.cpp srcs/HTTPMessage/Response.cpp \
	srcs/Config/WebServerConfig.cpp srcs/Config/ServerConfig.cpp srcs/Config/LocationBlock.cpp \

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
