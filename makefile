CXX := g++
CXXFLAGS := -g -Wall -std=c++17

CDIR := components

ODIR := obj

SDIR := src

SRC := $(wildcard $(SDIR)/$(CDIR)/*.cpp) $(wildcard $(SDIR)/*.cpp)

OBJ := $(patsubst %,$(ODIR)/%,$(SRC:%.cpp=%.o))

EXE := main

all: $(EXE) clean

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): $(ODIR)/%.o : %.cpp | $(ODIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(ODIR):
	mkdir $(ODIR) && cd $(ODIR) && mkdir $(SDIR) && cd $(SDIR) && mkdir $(CDIR)

clean:
	$(RM) -r $(ODIR)