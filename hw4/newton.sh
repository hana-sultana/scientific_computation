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

# pass the number to the newton program
echo $1 | ./newton
