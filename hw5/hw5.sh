#!/bin/bash

# check for exactly one argument
if [ $# -ne 1 ] ; then
  echo "Usage: $0 number"
  exit 1
fi

# check that it is a nonnegative integer
if [[ ! "$1" =~ ^[0-9]+$ ]] ; then
  echo "Error: argument must be a nonnegative integer"
  exit 1
fi

module load gcc/14.2.0

# pass the number to the hw5 program
echo "$1" | ./build-gcc14/hw5
