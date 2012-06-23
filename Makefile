CMAKE_BUILD_DIR ?= work
SOURCE_DIR ?= $(shell pwd)
CMAKE_PLATFORM_DEFINES :=
VENDOR_INSTALL_PREFIX := $(SOURCE_DIR)/vendor/$(CMAKE_BUILD_DIR)

ifeq ($(findstring Darwin,$(shell uname)), Darwin)
    PLATFORM := OSX
else
ifeq ($(findstring CYGWIN,$(shell uname)), CYGWIN)
    PLATFORM := WIN
else
ifeq ($(findstring Linux,$(shell uname)), Linux)
    PLATFORM := LINUX
endif
endif
endif

CMAKE_PLATFORM_DEFINES += -D CMAKE_INSTALL_PREFIX=$(VENDOR_INSTALL_PREFIX)
CMAKE_PLATFORM_DEFINES += -D VENDOR_INSTALL_PREFIX=$(VENDOR_INSTALL_PREFIX)

ifeq ($(PLATFORM),OSX)
	CMAKE_PLATFORM_DEFINES += -D CMAKE_OSX_SYSROOT="/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk"
	CMAKE_PLATFORM_DEFINES += -D CMAKE_OSX_ARCHITECTURES=i386
endif

.PHONY: all
all: setup build
	echo vendor $(VENDOR_INSTALL_PREFIX)
	$(MAKE) -C $(CMAKE_BUILD_DIR)

.PHONY: clean
	$(MAKE) -C $(CMAKE_BUILD_DIR) clean

.PHONY: mrproper
mrproper: 
	rm -rf $(CMAKE_BUILD_DIR)

configure:
	mkdir -p $(CMAKE_BUILD_DIR)

build: configure
	cd $(CMAKE_BUILD_DIR) && cmake $(CMAKE_PLATFORM_DEFINES) $(SOURCE_DIR)

setup:
	$(MAKE) -C vendor install
