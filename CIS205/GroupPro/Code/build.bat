@echo off

mkdir ..\build
pushd ..\build

cl -Zi ..\code\groupproject.cpp

popd