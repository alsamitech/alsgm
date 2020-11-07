#!/bin/sh

# You may configure this to your liking assuming you are not on a cloned repository intened to merge back with public-official or private

CFLAGS= -lvulkan -lX11 -lpthread -Wwrite-strings

pwd
sleep 3
echo what compiler do you want to use?
read CC
echo Any compiler flags that are not used by alsgm?
read usr_cflags
echo what is your source?
read source
echo What is your target?
read target

$CC -o $target $source $CFLAGS $usr_cflags
