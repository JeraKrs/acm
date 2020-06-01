CXX = g++
CFLAGS = -std=c++11
INC_PATHS = ./algorithm/data_structure

# 编译 LIB
LIB_SOURCE_DIR := $(shell find ./algorithm -maxdepth 3 -type d)
LIB_SOURCE = $(foreach dir, $(LIB_SOURCE_DIR), $(wildcard $(dir)/*.cpp))
LIB_OBJECTIVES = $(patsubst %.cpp, %.o, $(LIB_SOURCE))  
LIB_TARGET = libalgorithm.a

# 编译 UT
UT_SOURCE_DIR = ./unittest
UT_SOURCES = $(wildcard $(UT_SOURCE_DIR)/*.cpp)
UT_CPPFILES = $(notdir $(UT_SOURCES))
UT_OBJECTIVES = $(patsubst %.cpp, %, $(UT_CPPFILES))
UT_FLAGS = $(CFLAGS) -lgtest -fno-access-control


all: $(LIB_TARGET) ut end

$(LIB_TARGET): $(LIB_OBJECTIVES)
	mkdir -p output
	# ar cq ./output/$(LIB_TARGET) $<

$(LIB_OBJECTIVES):%.o : %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@  

ut: $(UT_SOURCES) $(LIB_TARGET)
	@for obj in $(UT_OBJECTIVES); do \
		$(CXX) $(UT_FLAGS) -I $(INC_PATHS) $(UT_SOURCE_DIR)/$$obj.cpp -o ./output/$$obj;\
	done;
	# $(CXX) $(UT_FLAGS) -I $(INC_PATHS) ./output/$(LIB_TARGET) $(UT_SOURCE_DIR)/$$obj.cpp -o ./output/$$obj;\

end:
	rm -rf $(LIB_OBJECTIVES)

clean:
	rm -rf output
