SRCS = $(wildcard *.cpp)
PROGS = $(patsubst %.cpp,%,$(SRCS))
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -pedantic

all: $(PROGS)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)
