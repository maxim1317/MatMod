set term wxt position 0,0 size 955,540
set title "Cookie"
set xlabel "time"
set ylabel "temperature"
set zlabel "f(x,t)"

set autoscale

set style data line
plot "tmp/out.txt" u 1:2