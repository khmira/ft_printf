#include "ft_printf.h"
#define TEST "%-*s\n",10, (void*)0
int main()
{
    printf("1|%d|\n",ft_printf(TEST));
    printf("2|%d|\n",   printf(TEST));

}