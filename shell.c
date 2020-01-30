#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "shellmemory.h"
#include "interpreter.h"

int parse(char* input) {
	char tmp[200];
	char * words[100] ;
	int a, b;

	for(int i = 0;i< 100; i++){
		words[i] = (char*) calloc(1, sizeof(char*));
	}

	int w = 0;
	for(a = 0; input[a] == ' '&& a <1000; a++);

	while(input[a] != '\0' && a<1000 && input[a]!= '\n'){
		for (b = 0; input[a]!= '\0' && (input[a] != ' ') && input[a]!= '\n' && a < 1000; a++, b++){
			tmp[b] = input[a];
		}
		tmp[b] = '\0';
		words[w] = strdup(tmp);

		if(input[a]== '\0' || input[a]== '\n')
		 break;

		a++; w++;
	}
	return interpreter(words);
}

int main(){
	char prompt[100] = {'$','\0'};  // prompts can be modified
	char userInput[1000]; //store user input in an array
	printf("Welcome to the Hao Shu shell!\n");
	printf("Version 1.0 Created January 2020\n");
	int errorCode=0; 
	while(1){
		
		printf("%s",prompt);
		fgets(userInput, 999, stdin);// limit input to array size

		int len = strlen(userInput);
		userInput[len-1] = '\0' ;

		errorCode = parse(userInput);
		if(errorCode == -1){//quit
			printf("Bye!\n");
			exit(0);
		}

		userInput[0]='\0';
	}
}