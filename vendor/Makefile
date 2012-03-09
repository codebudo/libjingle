CMAKE_PLATFORM_DEFINES := -D CMAKE_INSTALL_PREFIX=../

default: configure build

configure: expat-configure jsoncpp-configure

expat-configure:
	cd libexpat && cmake $(CMAKE_PLATFORM_DEFINES) .

expat-build:
	cd libexpat && make 

jsoncpp-configure:
	cd jsoncpp && cmake $(CMAKE_PLATFORM_DEFINES) .

jsoncpp-build:
	cd jsoncpp && make 

build: expat-build jsoncpp-build


clean:
	rm -rf lib include man share `find . -name CMakeCache.txt`
