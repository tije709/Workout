EXENAME = workout
OBJS = main.o workout.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpthread -lm
#-lc++abi

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp workout.h
	$(CXX) $(CXXFLAGS) main.cpp

workout.o : workout.cpp workout.h
	$(CXX) $(CXXFLAGS) workout.cpp


clean :
	-rm workout *.o $(EXENAME)
