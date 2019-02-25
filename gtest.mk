include third_party.mk

GOOGLETEST_DIR                       := $(THIRD_PARTY_DIR)/googletest
GOOGLETEST_REPO                      := https://github.com/google/googletest.git
GOOGLETEST_VERSION                   := release-1.8.1
GOOGLETEST_BUILD_DIR                 := $(GOOGLETEST_DIR)/build
GOOGLETEST_BUILD_LIB_DIR             := $(GOOGLETEST_DIR)/build/lib
GOOGLETEST_BUILD_INC_DIR             := $(GOOGLETEST_DIR)/build/include

GTEST_LIB_NAME                       := gtest
GTEST_LIB_FULL_NAME                  := $(GOOGLETEST_BUILD_LIB_DIR)/lib$(GTEST_LIB_NAME).a

GMOCK_LIB_NAME                       := gmock
GMOCK_LIB_FULL_NAME                  := $(GOOGLETEST_BUILD_LIB_DIR)/lib$(GMOCK_LIB_NAME).a