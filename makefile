CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -g
ADDLIB = -lncurses
INCLUDES = -I include
TARGET = main

SRCDIR = src
INCDIR = include
OBJDIR = obj

SOURCES = $(wildcard $(SRCDIR)/*/*.cpp) $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(addprefix $(OBJDIR)/,$(notdir $(SOURCES:.cpp=.o)))


$(TARGET): $(OBJECTS) $(OBJDIR)/$(TARGET).o
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@ $(ADDLIB)

$(OBJDIR)/$(TARGET).o: $(TARGET).cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(TARGET).cpp -o $(OBJDIR)/$(TARGET).o

$(OBJDIR)/%.o: $(SRCDIR)/*/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS) $(OBJDIR)/$(TARGET).o

.PHONY: clean
