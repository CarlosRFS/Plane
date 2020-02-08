#!/bin/sh
meson build
cd build
ninja
mv plane ../
cd ..
