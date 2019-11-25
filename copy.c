// Steven Inman, Mickey Kerr, Bryan Garcia Rodriguez
// CS135
// Section 1101
// Lab12
// 11/25/2019

#include <stdio.h>

int main(int argc, char *argv[]){

	FILE *input, *output;

	int variable=0;

	if(argc==3){
	input=fopen(argv[1],"r");
	output=fopen(argv[2],"w");
	if(input==NULL){
		printf("Can't open %s\n",argv[1]);
	}
	while(fscanf(input,"%d, ",&variable)!=EOF){
			printf("%d\n", variable);
			fprintf(output,"%d\n",variable);

		
		

	}
	fclose(input);
	fclose(output);

	}
	else{
		printf("Please enter 2 file names\n");
	}






	return 0; 
}