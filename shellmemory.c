#include<stdlib.h>
#include<stdio.h>
#include <string.h>

struct MEM {
    char * var;
    char * val;
};


struct MEM mem[1000];// create struct array

int insert(char* var, char* val)
{
    int counter;
    for (int i = 0; i <= 1000; i++)
    {
        if (mem[i].var == NULL)
        {
            mem[i].var = strdup(var);
            mem[i].val = strdup(val);
            return 0;
        }
        if (!strcmp(mem[i].var, var))
        {
            mem[i].val= val;
            return 0;

        }
        counter ++;
       
    }

    if (counter ==1000){
        printf("Shell memory full\n");
    }

    return 1;
}


char *getVal(char *var) {
	 for (int i = 0; i < 1000; i++)
    {
        if (mem[i].var == NULL)
            return "Variable does not exist";
        if (!strcmp(mem[i].var, var))
            return mem[i].val;
    }
	
	return "Variable does not exist";
}