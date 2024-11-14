@echo off
pushd %~dp0\..\
call srcipts\bin\premake\premake5.exe vs2022
popd
PAUSE