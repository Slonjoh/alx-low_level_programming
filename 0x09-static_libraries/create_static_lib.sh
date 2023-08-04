#!/bin/sh -e
gcc -c *.c
ar cr liball.a *.o
