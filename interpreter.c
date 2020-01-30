#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "shellmemory.h"
#include "shell.h"


int errCode = 0;// 0=help,set,print,run
                // 1=unknown command,
                //-1=quit

int help() {
	printf("COMMAND                 DESCRIPTION \n");
    printf(" \n");
	printf("help                   Displays all the commands \n");
	printf("quit                   Exits / terminates the shell with “Bye!”\n");
	printf("set VAR STRING         Assigns a value to shell memory \n");
	printf("print VAR              Displays the STRING assigned to VAR \n");
	printf("run SCRIPT.TXT         Executes the file SCRIPT.TXT \n");
	return 0;
}

int quit(){
	return -1;
}

int set(char *words[]) {
	insert(words[1],words[2]);

	return 0;
}

int print(char *words[]) {
	printf(getVal(words[1]),"%s");
	printf("\n");
	return 0;
}


int run(char *words[]) {

	int errCode = 0;
	char line[1000];

    char * fileName = strdup(words[1]);
	FILE *file = fopen(fileName,"r");  // opens a file for reading
	if (!file){
		printf("Script not found \n");
		return errCode;
	}

    while (fgets(line,999,file))
    {
        errCode = parse(line);// read each line of the file
    }

	fclose(file); // close file
	return errCode;
}

int interpreter(char *words[]) { 


	// execute a single command
	if (!strcmp(words[0], "help")){
		errCode = help();
	}
	else if (!strcmp(words[0], "quit")) {
		errCode = quit();
	}
	else if (!strcmp(words[0], "set"))  {
		errCode = set(words);
	}
	else if (!strcmp(words[0], "print")) {
		errCode = print(words);
	}
	else if (!strcmp(words[0], "run")) {
	
		errCode = run(words);
	}

	else {
        printf("Unknown command \n");
        errCode = 1;// command not found
    }


	return errCode;
}

