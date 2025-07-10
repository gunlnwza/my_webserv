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
OBJDIR_MODULES := $(OBJDIR)/srcs $(MODULES:%=$(OBJDIR)/srcs/%)

MAIN := srcs/main.cpp

# add class sources here
CLASS_SRCS := srcs/WebServer.cpp \
	srcs/utils/Logger.cpp srcs/utils/ft_utils.cpp srcs/utils/Path.cpp \
	srcs/HTTPMessage/AHTTPMessage.cpp srcs/HTTPMessage/Request.cpp srcs/HTTPMessage/Response.cpp \
	srcs/Config/WebServerConfig.cpp srcs/Config/ServerConfig.cpp srcs/Config/LocationBlock.cpp \
	srcs/Tokenizer/Tokenizer.cpp srcs/Tokenizer/Tokens.cpp \

SRCS := $(MAIN) $(CLASS_SRCS)
OBJS := $(SRCS:%.cpp=$(OBJDIR)/%.o)
CLASS_HEADERS := $(CLASS_SRCS:srcs/%.cpp=headers/%.hpp)  # class headers must also be present
HEADERS := $(CLASS_HEADERS)


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

debug:
	@echo $(HEADERS)

.PHONY: all clean fclean re debug
