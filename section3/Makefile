
CXX = g++
FLAGS = -m32

LD_PATHS = StanfordCPPLib
LD_PATHS_ = $(LD_PATHS:%=-L%)

INC = StanfordCPPLib
INC_ = $(INC:%=-I%)

LIBS = StanfordCPPLib
LIBS_ = $(LIBS:%=-l%)

FWKS = Carbon Cocoa QuickTime
FWKS_ = $(FWKS:%=-framework %)

FLAGS_ = $(FLAGS) $(LD_PATHS_) $(LIBS_) $(INC_) $(FWKS_)

TARGETS = 1-weights 4-anagrams
SOLUTIONS = $(TARGETS:%=%_sol)


.SILENT: clean

all: try sol

try: $(TARGETS)

sol: $(SOLUTIONS)

clean:
	-@rm $(TARGETS) $(SOLUTIONS) 2>/dev/null || true

%: %.cpp
	$(CXX) $(FLAGS_) -o $* $*.cpp

%_sol: %.cpp
	$(CXX) $(FLAGS_) -DSOLUTIONS -o $*_sol $*.cpp

