#!/bin/sh

#git submodule init

if [ ! -e vendor/srtp ]; then
	echo -n "Getting latest srtp..."
    pushd .
	cd vendor
	cvs -d:pserver:anonymous@srtp.cvs.sourceforge.net:/cvsroot/srtp co -P srtp
	echo "done"
    popd
fi

