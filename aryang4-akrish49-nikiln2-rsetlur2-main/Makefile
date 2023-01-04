EXENAME = cs225_project
OBJS = main.o graph.o airport.o bfs.o A_star.o kruskal.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement logic:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
ifneq ($(strip $(SKIP_EWS_CHECK)),True)
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif
endif


.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

graph.o : graph.cpp graph.h edge.h random.h
	$(CXX) $(CXXFLAGS) graph.cpp

bfs.o : bfs.cpp bfs.h
	$(CXX) $(CXXFLAGS) bfs.cpp

A_star.o : A_star.cpp A_star.h airport.h
	$(CXX) $(CXXFLAGS) A_star.cpp airport.cpp

kruskal.o : kruskal.cpp kruskal.h 
	$(CXX) $(CXXFLAGS) kruskal.cpp

airport.o : airport.cpp airport.h 
	$(CXX) $(CXXFLAGS) airport.cpp

random.o : random.cpp random.h
	$(CXX) $(CXXFLAGS) random.cpp

catchmain.o : tests/catch/catchmain.cpp tests/catch/catch.hpp
	$(LD) $(CXXFLAGS) tests/catch/catchmain.cpp

test: output_msg catchmain.o tests.o A_star.o kruskal.o graph.o airport.o bfs.o
	$(LD) catchmain.o tests.o A_star.o kruskal.o graph.o airport.o bfs.o $(LDFLAGS) -o test

tests.o : tests/tests.cpp kruskal.cpp kruskal.h A_star.cpp A_star.h bfs.cpp bfs.h
	$(CXX) $(CXXFLAGS) tests/tests.cpp

main.o : main.cpp bfs.o
	$(CXX) $(CXXFLAGS) main.cpp

clean :
	-rm -f *.o $(EXENAME) test