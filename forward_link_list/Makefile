ifeq ($(PROJECT_ROOT_DIR),)
$(error Please provide PROJECT_ROOT_DIR)
endif

include $(PROJECT_ROOT_DIR)/project.mk

CUR_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
CUR_DIR := $(patsubst %/,%,$(CUR_DIR))
CUR_DIR := $(patsubst %\,%,$(CUR_DIR))

SRC_DIR  := ${CUR_DIR}/src
INC_DIR  := ${CUR_DIR}/inc
DEP_DIR  := $(CUR_DIR)/dep
BIN_DIR  := ${CUR_DIR}/bin
OBJ_DIR  := ${CUR_DIR}/obj
TEST_DIR := ${CUR_DIR}/test

export PROJECT_FORWARD_LIST_DIR        := $(CUR_DIR)
export PROJECT_FORWARD_LIST_INC_DIR    := $(INC_DIR)

EXE_NAME := main

SRCS = $(shell find $(SRC_DIR) -name *.cpp)
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
DEPS := $(patsubst %.cpp, $(DEP_DIR)/%.d, $(notdir $(SRCS)))

CFLAGS += -I$(INC_DIR)

# Check whether the compiler support this feature.
# The GNU Compiler Collection contains a C preprocessor that can generate make dependency files.
# For furher information, please visit the following pages:
# "http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/#combine" Title : Combining Compilation and Dependency Generation
# https://www.gnu.org/software/make/manual/make.html#Automatic-Prerequisites Title : 4.14 Generating Prerequisites Automatically 
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td

.PHONY: all test clean cleanObj cleanBin cleanDep cleanTest

all : build test

build : $(BIN_DIR)/$(EXE_NAME)

test :
	@make -f $(TEST_DIR)/Makefile all

$(BIN_DIR)/$(EXE_NAME): $(OBJS) | $(BIN_DIR)
	@printf "Building $(notdir $@) in $(BIN_DIR) path\n"
	@$(CC) -o $@ $?

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(DEP_DIR)/%.d | $(OBJ_DIR) $(DEP_DIR)
	@printf "Compiling $(notdir $@)\n"
	@$(CC) $(DEPFLAGS) -c $< -o $@ $(CFLAGS) && \
	mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@

include $(wildcard $(DEPS))

$(DEP_DIR)/%.d: ;
.PRECIOUS: $(DEP_DIR)/%.d $(OBJ_DIR)/%.o

$(BIN_DIR):
	@printf "Creating directory $(BIN_DIR)\n"
	@mkdir $(BIN_DIR)

$(OBJ_DIR):
	@printf "Creating directory $(OBJ_DIR)\n"
	@mkdir $(OBJ_DIR)

$(DEP_DIR):
	@printf "Creating directory $(DEP_DIR)\n"
	@mkdir $(DEP_DIR)

clean: cleanObj cleanBin cleanDep cleanTest

cleanObj:
	@printf "Cleaning objects...\n"
	@rm -rf $(OBJ_DIR)

cleanBin:
	@printf "Cleaning executables...\n"
	@rm -rf $(BIN_DIR)

cleanDep:
	@printf "Cleaning dependencies...\n"
	@rm -rf $(DEP_DIR)

cleanTest:
	@printf "Cleaning test outputs...\n"
	@make -f $(TEST_DIR)/Makefile clean

