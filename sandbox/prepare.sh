#!/bin/bash

echo "$1"
mkdir $1
cd $1
$(wget https://open.kattis.com/problems/$1/file/statement/samples.zip)
$(unzip samples.zip)
$(rm samples.zip)
$(cp ../../library/template.cc $1.cc)
