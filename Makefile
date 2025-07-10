NAME := webserv

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -rf

RESET := \033[0m
BOLD_GRAY := \033[1;30m
BOLD_RED := \033[1;31m
BOLD_GREEN := \033[1;32m
BOLD_YELLOW := \033[1;33m
BOLD_BLUE := \033[1;34m


OBJDIR := build
MODULES := utils HTTPMessage Config Tokenizer

HEADERS := headers/WebServer.hpp \
	headers/utils/Logger.hpp headers/utils/ft_utils.hpp headers/utils/Path.hpp \
	headers/HTTPMessage/Request.hpp headers/HTTPMessage/Response.hpp headers/HTTPMessage/AHTTPMessage.hpp \
	headers/Config/WebServerConfig.hpp headers/Config/ServerConfig.hpp headers/Config/LocationBlock.hpp \
	headers/Tokenizer/Tokenizer.hpp headers/Tokenizer/Tokens.hpp \

SRCS := srcs/main.cpp srcs/WebServer.cpp \
	srcs/utils/Logger.cpp srcs/utils/ft_utils.cpp srcs/utils/Path.cpp \
	srcs/HTTPMessage/AHTTPMessage.cpp srcs/HTTPMessage/Request.cpp srcs/HTTPMessage/Response.cpp \
	srcs/Config/WebServerConfig.cpp srcs/Config/ServerConfig.cpp srcs/Config/LocationBlock.cpp \
	srcs/Tokenizer/Tokenizer.cpp srcs/Tokenizer/Tokens.cpp \

OBJS := $(SRCS:%.cpp=$(OBJDIR)/%.o)
OBJDIR_MODULES := $(OBJDIR)/srcs $(MODULES:%=$(OBJDIR)/srcs/%)


all:  $(NAME)

mkdir:
	mkdir -p $(OBJDIR_MODULES)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BOLD_GREEN)✅ Built successfully:$(RESET) $(NAME)"

$(OBJDIR)/%.o: %.cpp $(HEADERS) | $(OBJDIR) $(OBJDIR_MODULES)
	@echo "$(BOLD_BLUE)🚀 Compiling:$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) $(OBJDIR_MODULES):
	@if [ ! -d "$@" ]; then \
		mkdir -p "$@"; \
		echo "$(BOLD_GRAY)📁 Create directory:$(RESET) $@"; \
	fi

clean:
	@$(RM) $(OBJDIR)
	@echo "$(BOLD_YELLOW)🧹 Clean:$(RESET) Removed $(OBJDIR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BOLD_RED)🔥 Full clean:$(RESET) Removed $(NAME)"

re: fclean all


.PHONY: all clean fclean re
