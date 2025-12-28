RM  = rm 
CXX = c++

RMFLAGS  = -rf 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

DEPS = AType.hpp DoubleType.hpp IntType.hpp FloatType.hpp CharType.hpp 
SRCS = AType.cpp DoubleType.cpp IntType.cpp FloatType.cpp CharType.cpp
TEST_SRCS = $(SRCS) tests/main.test.cpp

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
