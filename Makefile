include project.mk

IMPLEMENTATIONS := $(CURDIR)/forward_link_list

.PHONY: all

all: $(IMPLEMENTATIONS)

$(CURDIR)/%: | $(GOOGLETEST_DIR)
	make -f $@/Makefile all CURDIR=$@

$(GOOGLETEST_DIR): | $(THIRD_PARTY_DIR)
	cd $(THIRD_PARTY_DIR) &&\
	git clone $(GOOGLETEST_REPO) && \
	cd $(GOOGLETEST_DIR) && \
	git checkout $(GOOGLETEST_VERSION) && \
	mkdir $(GOOGLETEST_BUILD_DIR) && \
	cd $(GOOGLETEST_BUILD_DIR) && \
	cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=$(GOOGLETEST_BUILD_DIR) .. && \
	make && \
	make install

$(THIRD_PARTY_DIR):
	mkdir $(THIRD_PARTY_DIR)