# push_swap
sorting stack

command line to test it

    repeat 10 {ARG=`ruby -e "puts (0 ... 100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l | awk '$1 > 700  {print ;}'} | wc -l

[preview](http://pushswap.machine.ovh)
