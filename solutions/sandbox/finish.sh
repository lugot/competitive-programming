#!/bin/bash

echo "$1"
$(mv ./"$1"/"$1".cc ..)
$(rm -rf $1)
