ifeq ($(PROJECT_ROOT_DIR),)
$(error Please provide PROJECT_ROOT_DIR)
endif

include $(PROJECT_ROOT_DIR)/project.mk

CUR_DIR   := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
CUR_DIR   := $(patsubst %/,%,$(CUR_DIR))
CUR_DIR   := $(patsubst %\,%,$(CUR_DIR))


TESTS     := unit

TESTS_DIR := $(CUR_DIR)

.PHONY: all

all: 
	$(foreach TEST, $(TESTS), @make -f $(TESTS_DIR)/$(TEST)/Makefile all)

clean:
	$(foreach TEST, $(TESTS), @make -f $(TESTS_DIR)/$(TEST)/Makefile clean)