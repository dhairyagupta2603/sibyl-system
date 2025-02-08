#!/usr/bin/env bash
set -xe

# sibyl shared library
pushd sibyl

cmake -G Ninja -B build
cmake --build build
sudo cmake --install build

popd

# system executable
pushd system

cmake -G Ninja -B build
cmake --build build
sudo cmake --install build

popd

./system/build/src/sybil-system
