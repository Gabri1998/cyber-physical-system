#!/usr/local/bin/gnuplot
set datafile separator ','
set terminal pngcairo enhanced font 'Verdana,10'
set output 'build/performance_analysis.png'
set title 'Performance Analysis'
set xlabel 'Time (ms)'
set ylabel 'Steering Accuracy'
plot 'build/res.csv' using 1:2 with lines title 'Calculated Steering', '' using 1:3 with lines title 'Actual Steering'
