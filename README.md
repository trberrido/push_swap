# push_swap
a sorting stack C program

command line to test it

    repeat 10 {ARG=`ruby -e "puts (0 ... 100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l | awk '$1 > 700  {print ;}'} | wc -l

[a viewer](https://github.com/thberrid/yapv)

[preview](http://pushswap.machine.ovh)
