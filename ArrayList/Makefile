CXX=g++
CXXFLAGS= -Wall -g
TARGET=build/arrayList_test
SOURCES=test/check_ArrayList.cpp
INCLUDE= -Iinclude/
STD= -std=c++17

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(STD) $(CXXFLAGS) $(INCLUDE) -o $(TARGET) $(SOURCES)

clean:
	$(RM) $(TARGET)
