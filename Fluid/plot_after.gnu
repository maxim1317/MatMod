set title "Approximate"
set xlabel "x"
set ylabel "time"
set zlabel "f(x,t)"

set autoscale

splot "plots/diff.txt" u 1:2:3, \
      "plots/after.txt" u 1:2:3
set style data lines
set hidden3d
set dgrid3d 50,50 qnorm 2
splot "plots/diff.txt" u 1:2:3, \
      "plots/after.txt" u 1:2:3 with lines
