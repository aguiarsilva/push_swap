#include "../push_swap/include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if(argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if(argc == 2)
        argv = ft_split(argv[1], ' ');
    
    return(0);
}