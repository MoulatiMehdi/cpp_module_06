RM  = rm 
CXX = c++

RMFLAGS  = -rf 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

DEPS = AType.hpp FloatType.hpp 
SRCS = AType.cpp FloatType.cpp
TEST_SRCS = $(SRCS) tests/FloatType.test.cpp

OBJS = $(SRCS:.cpp=.o)
TEST = test
NAME = run 

all : $(TEST)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ 

%.o : %.c $(DEPS)
	$(CXX) $(CXXFLAGS) -c  $< -o $@

clean : 
	$(RM) $(RMFLAGS) $(OBJS)

test : $(TEST_SRCS) 
	$(CXX) $(CXXFLAGS) $^ -o $@  -I ./

fclean : clean 
	$(RM) $(RMFLAGS) $(NAME) $(TEST)

re : fclean all 

.PHONY : re fclean clean all test 
