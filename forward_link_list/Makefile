CC := g++

SRC_DIR := ${CURDIR}/src
INC_DIR := ${CURDIR}/inc
DEP_DIR := $(CURDIR)/dep
BIN_DIR := ${CURDIR}/bin
OBJ_DIR := ${CURDIR}/obj


EXE_NAME := main

SRCS = $(shell find $(SRC_DIR) -name *.cpp)
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
DEPS := $(patsubst %.cpp, $(DEP_DIR)/%.d, $(notdir $(SRCS)))


CFLAGS := -I$(INC_DIR) -Wall

# Check whether the compiler support this feature.
# The GNU Compiler Collection contains a C preprocessor that can generate make dependency files.
# For furher information, please visit the following pages:
# "http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/#combine" Title : Combining Compilation and Dependency Generation
# https://www.gnu.org/software/make/manual/make.html#Automatic-Prerequisites Title : 4.14 Generating Prerequisites Automatically 
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td

.PHONY: all clean cleanObj cleanBin cleanDep

all : $(BIN_DIR)/$(EXE_NAME) 
	
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
	mkdir $(BIN_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(DEP_DIR):
	mkdir $(DEP_DIR)

cleanObj:
	rm -rf $(OBJ_DIR)

cleanBin:
	rm -rf $(BIN_DIR)

cleanDep:
	rm -rf $(DEP_DIR)
	
clean: cleanObj cleanBin cleanDep
