#include <stdio.h>


int main(void){

	int score;
	char name[100];
	FILE *output;
	output=fopen("scores.txt","a+");

	printf("Enter a score and a name\n");
	scanf("%d",&score);
	scanf("%s",name);

	printf("Score is %d and name is %s\n",score,name);
	fprintf(output,"%d\t%s\n",score,name);


	return 0;
}