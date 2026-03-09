NAME = Fixed

CC = c++
CFLAGS = -Wall -Werror -Wextra
STD = -std=c++98

RM = rm -rf

SRCS =	main.cpp\
		Fixed.cpp\


OBJ_DIR = obj
OBJ = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

COLOR_YELLOW	=	\033[0;33m
COLOR_GREEN		=	\033[0;32m
COLOR_RED		=	\033[0;31m
COLOR_END		=	\033[0m

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					@$(CC) $(CFLAGS) $(STD) $^ -o $(NAME)
					@echo "\n\e[1m$(COLOR_YELLOW)$(NAME)	$(COLOR_GREEN)[is ready!]\e[0m\n$(COLOR_END)"

$(OBJ_DIR)/%.o	:	%.cpp | $(OBJ_DIR)
					@$(CC) $(CFLAGS) $(STD) -c $< -o $@

$(OBJ_DIR)		:
					@mkdir -p $(OBJ_DIR)

clean			:
					@$(RM) -rf $(OBJ_DIR)
					@echo "\e[1m$(COLOR_YELLOW)objects		$(COLOR_RED)[are deleted!]\e[0m$(COLOR_END)"
			

fclean			:	clean
					@$(RM) $(NAME)
					@echo "\e[1m$(COLOR_YELLOW)$(NAME)	$(COLOR_RED)[is deleted!]\e[0m$(COLOR_END)"

re				:	fclean all

.PHONY			:	all clean fclean re