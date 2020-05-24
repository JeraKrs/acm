CXX = g++
CFLAGS = -std=c++11 -lgtest
INC_PATHS = ./algorithm/data_structure

SOURCE_DIR = ./unittest
SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)
CPPFILES = $(notdir $(SOURCES))
OBJECTIVES = $(patsubst %.cpp, %, $(CPPFILES))

ut: $(SOURCES)
	mkdir -p output;
	@for obj in $(OBJECTIVES); do \
		$(CXX) $(CFLAGS) -I $(INC_PATHS) $(SOURCE_DIR)/$$obj.cpp -o ./output/$$obj;\
	done;

clean:
	rm -rf output;
