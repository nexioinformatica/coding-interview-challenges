#!/bin/bash

source compile.sh

anagram
angle-between-clock-hands
time-slot-booking

rm -rf .build
mkdir -p .build
mv **/*.pdf .build
