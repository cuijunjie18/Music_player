#!/bin/zsh
# 删除记录
rm Makefile
rm .qmake.stash

# 重新编译
qmake 
bear -- make
mv *.h include/
mv *.o build/
mv *.cpp src/
mv main bin/main