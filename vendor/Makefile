CMAKE_BUILD_DIR ?= work
VENDOR_INSTALL_PREFIX := $(shell pwd)/$(CMAKE_BUILD_DIR)
export VENDOR_INSTALL_PREFIX

THIRD_PARTY_LIBS := libexpat jsoncpp googletest srtp

PACKAGES_INSTALL = $(foreach pkg,$(THIRD_PARTY_LIBS),$(pkg)-install)
PACKAGES_CLEAN = $(foreach pkg,$(THIRD_PARTY_LIBS),$(pkg)-clean)
PACKAGES_MRPROPER = $(foreach pkg,libexpat jsoncpp googletest,$(pkg)-mrproper)

.PHONY: all 
all: configure $(THIRD_PARTY_LIBS) 

.PHONY: install
install: $(PACKAGES_INSTALL)

.PHONY: clean
clean: $(PACKAGES_CLEAN)

.PHONY: mrproper
mrproper: $(PACKAGES_MRPROPER)
	rm -rf work

configure:
	cd srtp; ./configure --prefix=$(VENDOR_INSTALL_PREFIX) CFLAGS="-m32"

.PHONY: $(THIRD_PARTY_LIBS)
$(THIRD_PARTY_LIBS): 
	$(MAKE) -C $@

.PHONY: $(PACKAGES_CLEAN)
$(PACKAGES_CLEAN):
	-$(MAKE) -C $(subst -, ,$@)

.PHONY: $(PACKAGES_MRPROPER)
$(PACKAGES_MRPROPER):
	-$(MAKE) -C $(subst -, ,$@)

.PHONY: $(PACKAGES_INSTALL)
$(PACKAGES_INSTALL):
	-$(MAKE) -C $(subst -, ,$@)

