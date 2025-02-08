#!/usr/bin/env bash
set -xe

cmake --workflow --preset=linux-debug-workflow
sudo cmake --install build