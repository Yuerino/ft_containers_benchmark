
GBM_DIR		=	./google-benchmark

GBM_SRCS		=	$(wildcard $(GBM_DIR)/src/*.cc)
GBM_OBJS		=	$(GBM_SRCS:.cc=.o)

NAME			=	compare

USER_HEADERS	=	..

CXX				=	clang++

CPPFLAGS		+=	-isystem $(GBM_DIR)/include -I$(GBM_DIR) -I$(USER_HEADERS)

CXXFLAGS		+=	-g -Wall -Wextra -Werror -pthread -std=c++14 -Wshadow -fstrict-aliasing  -pedantic-errors -Wfloat-equal -DNDEBUG

# vector benchmark
VECTOR_DIR		=	vector/
VECTOR_SRCS		=	pushback.cpp
VECTOR_OBJS		=	$(addprefix $(VECTOR_DIR), $(VECTOR_SRCS:.cpp=.o))

.PHONY: all clean re

all: $(NAME)

$(NAME): $(VECTOR_OBJS) $(GBM_OBJS) Makefile
		$(CXX) $(CXXFLAGS) $(CPPFLAGS) -lpthread $(VECTOR_OBJS) $(GBM_OBJS) -o $(NAME)

clean:
		$(RM) $(NAME) $(GBM_OBJS) $(VECTOR_OBJS)

re: clean all
