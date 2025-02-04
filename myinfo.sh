#!/bin/sh
#SBATCH --job-name=myjob
#SBATCH --partition=Centaurus
#SBATCH --time=10:00:00
#SBATCH --mem=32G

./mergeTest 10
./mergeTest 100
./mergeTest 1000
./mergeTest 10000
./mergeTest 100000
./mergeTest 1000000
./mergeTest 10000000
./mergeTest 100000000
./mergeTest 1000000000

