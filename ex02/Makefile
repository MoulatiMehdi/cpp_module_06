RM  = rm 
CXX = c++

RMFLAGS  = -rf 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

DEPS = ./Base.hpp ./A.hpp ./B.hpp ./C.hpp 
SRCS = ./Base.cpp ./main.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = run 

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@  -I ./

%.o : %.c $(DEPS)
	$(CXX) $(CXXFLAGS) -c  $< -o $@

clean : 
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean 
	$(RM) $(RMFLAGS) $(NAME) $(TEST)

re : fclean all 

.PHONY : re fclean clean all test 
