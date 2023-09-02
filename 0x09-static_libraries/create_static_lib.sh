#!/bin/bash

for i in *.c;
do
    gcc -c $i;
done

for i in *.o;
do
    ar rcs liball.a $i;
done

ar -t liball.a;
nm liball.a;