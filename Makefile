CUR_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
CUR_DIR := $(patsubst %/,%,$(CUR_DIR))
CUR_DIR := $(patsubst %\,%,$(CUR_DIR))

export PROJECT_ROOT_DIR := $(CUR_DIR)
export CC := g++
export CFLAGS := -Wall

include $(PROJECT_ROOT_DIR)/project.mk

IMPS       := forward_link_list

IMPS_DIR   := $(PROJECT_ROOT_DIR)

.PHONY: all

all: 
	$(foreach IMP, $(IMPS), make -f $(IMPS_DIR)/$(IMP)/Makefile all)
	
