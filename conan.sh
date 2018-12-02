#!/usr/bin/env bash

case "$1" in
    add_remote)echo "Configure conan with community remotes to get needed dependencies"
        conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
        ;;
    debug)echo "Installing dependencies for debug"
        conan install . -s build_type=Debug --install-folder=cmake-build-debug
        wait
        ;;
    release)echo  "Installing dependencies for release"
        conan install . -s build_type=Release --install-folder=cmake-build-release
        wait
        ;;
    *)echo "Unknown arg, user: debug or release"
        echo "---------------------------"
        exit 1
        ;;
esac

exit 0
