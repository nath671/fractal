

#set palette rgbformulae 22,13,-31
set palette defined (0"midnight-blue", 0.7"orange", 0.8"gold",0.95"white",  1"black")
#set cbrange [1:30]
set pm3d map interpolate 0,0 # interpolation auto

set terminal png size 1300, 1200
set output "fractal4.png"


unset colorbox
unset xtics
unset ytics
splot "fractal.txt" u 1:2:3 w pm3d



set terminal x11
