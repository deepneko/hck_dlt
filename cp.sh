#!/bin/zsh

cd $1
make clean
cd ../
cp -R $1 $2
sed s/$3/$4/ $1/Makefile > $2/Makefile
mv $2/$3.c $2/$4.c
