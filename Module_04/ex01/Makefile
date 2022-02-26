# COMMANDS
################################################################################
RM			= rm -f
CC			= c++

# SOURCES
################################################################################
SRCS		= main.cpp \
			  Animal.cpp \
			  Cat.cpp \
			  Dog.cpp \
			  WrongAnimal.cpp \
			  WrongCat.cpp \
			  Brain.cpp
OBJS		= $(SRCS:.cpp=.o)

# EXECUTABLES & LIBRARIES
################################################################################
NAME		= animals

# DIRECTORIES
################################################################################
HEADERS		= .

# FLAGS
################################################################################
CPPFLAGS		:= -Wall -Wextra -Werror -std=c++98

ifeq ($(DEBUG), true)
	CPPFLAGS	+= -fsanitize=address -g3 -O0
endif

ifeq ($(SILENT), true)
	CPPFLAGS	+= -DSILENCE
endif

# RULES
################################################################################
.c.o:
			$(CC) $(CPPFLAGS) -c $< -o $(<:.cpp=.o) -I$(HEADERS)

$(NAME):	$(OBJS)
			$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean c.o re