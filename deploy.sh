#!/bin/bash

TEMP=temp
OUT=misssnake.arduboy

rm -fr $OUT
rm -fr $TEMP
mkdir -p $TEMP

cp -r deployables/* $TEMP
cp MissSnake/MissSnake.ino.leonardo.hex $TEMP/misssnake.hex

cd $TEMP
zip ../$OUT *
cd - > /dev/null

rm -fr $TEMP
