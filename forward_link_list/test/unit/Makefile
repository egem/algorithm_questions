ifeq ($(PROJECT_ROOT_DIR),)
$(error Please provide $(PROJECT_ROOT_DIR))
endif

ifeq ($(PROJECT_FORWARD_LIST_DIR),)
$(error Please provide $(PROJECT_FORWARD_LIST_DIR))
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

SRCS = $(shell find $(SRC_DIR) -name *.cpp)

OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
DEPS := $(patsubst %.cpp, $(DEP_DIR)/%.d, $(notdir $(SRCS)))
TESTS := $(patsubst %.cpp, $(BIN_DIR)/%, $(notdir $(SRCS)))

#OBJS      := $(addprefix $(OBJ_DIR)/,$(subst .cpp,.o,$(notdir $(SRCS))))
#TESTS     := $(addprefix $(BIN_DIR)/,$(basename $(notdir $(SRCS))))
#DEPS      := $(addprefix $(DEP_DIR)/,$(subst .cpp,.d,$(notdir $(SRCS))))

CFLAGS += -I$(INC_DIR) 
CFLAGS += -I$(PROJECT_FORWARD_LIST_INC_DIR) 
CFLAGS += -I$(GOOGLETEST_BUILD_INC_DIR)

LFLAGS += -l$(GTEST_LIB_NAME)
LFLAGS += -l$(GMOCK_LIB_NAME)

LFLAGS += -L$(GOOGLETEST_BUILD_LIB_DIR)

# Check whether the compiler support this feature.
# The GNU Compiler Collection contains a C preprocessor that can generate make dependency files.
# For furher information, please visit the following pages:
# "http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/#combine" Title : Combining Compilation and Dependency Generation
# https://www.gnu.org/software/make/manual/make.html#Automatic-Prerequisites Title : 4.14 Generating Prerequisites Automatically 
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td

.PHONY : all clean cleanObj cleanDep cleanTest

all : $(TESTS) $(GOOGLETEST_DIR)
	$(foreach TEST, $(TESTS), $(TEST))

$(BIN_DIR)/% : $(OBJ_DIR)/%.o | $(BIN_DIR)
	@printf "Building $(notdir $@) in $(BIN_DIR) path\n"
	@$(CC) -o $@ $< $(LFLAGS)
	
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(DEP_DIR)/%.d | $(OBJ_DIR) $(DEP_DIR)
	@printf "Compiling $(notdir $@)\n"
	@$(CC) $(DEPFLAGS) -c $< -o $@ $(CFLAGS) && \
	mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@

$(DEP_DIR)/%.d: ;
.PRECIOUS: $(DEP_DIR)/%.d $(OBJ_DIR)/%.o

include $(wildcard $(DEPS))

$(DEP_DIR):
	@printf "Creating directory $(DEP_DIR)"
	@mkdir $(DEP_DIR)

$(OBJ_DIR):
	@printf "Creating directory $(OBJ_DIR)"
	@mkdir $(OBJ_DIR)
	
$(BIN_DIR):
	@printf "Creating directory $(BIN_DIR)"
	@mkdir $(BIN_DIR)
	
clean: cleanObj cleanDep cleanTest
	@printf "Object, dependency and test executable files under $(CUR_DIR) folder are cleaned"

cleanObj:
	@printf "Cleaning objects...\n"
	@rm -rf $(OBJ_DIR)

cleanDep:
	@printf "Cleaning dependencies...\n"
	@rm -rf $(DEP_DIR)

cleanTest:
	@printf "Cleaning test executables...\n"
	@rm -rf $(BIN_DIR)

$(GOOGLETEST_DIR): | $(THIRD_PARTY_DIR)
	@printf "Downloading Google Test to $(GOOGLETEST_DIR) path" && \
	@cd $(THIRD_PARTY_DIR) &&\
	git clone $(GOOGLETEST_REPO) && \
	cd $(GOOGLETEST_DIR) && \
	git checkout $(GOOGLETEST_VERSION) && \
	mkdir $(GOOGLETEST_BUILD_DIR) && \
	cd $(GOOGLETEST_BUILD_DIR) && \
	cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=$(GOOGLETEST_BUILD_DIR) .. && \
	make && \
	make install

$(THIRD_PARTY_DIR):
	@printf "Creating directory $(THIRD_PARTY_DIR)"
	mkdir $(THIRD_PARTY_DIR)

	