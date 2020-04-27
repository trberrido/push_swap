# push_swap
A sorting stacks C program, implementing quick sort algorithm.

A command line to test it

    repeat 10 {
    ARG=`ruby -e "puts (0 ... 100).to_a.shuffle.join(' ')"`; 
    ./push_swap $ARG | ./checker $ARG; 
    ./push_swap $ARG | wc -l | awk '$1 > 700  {print ;}'
    }


[a viewer](https://github.com/thberrid/yapv)
