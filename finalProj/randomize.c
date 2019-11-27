#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *array, int n);

int main(void){
	int level,input,lower=1;

	printf("Please enter a difficulity\n");
	scanf("%d",&level);
	printf("\n\n");
	if(level==1){
		input=2;
				}
	if(level==2){
		input=8;
				}
	if(level==3){
		input=18;
				}
	int array[input];
	int values[input*2];
	


srand(time(0));
for(int i=0;i<=input-1;i++){
array[i]=(i+1);
}


shuffle(array,input);

for(int i=0;i<=((input*2)-1);i++){
if(i<=input-1){
	values[i]=array[i];
}
if(i>input-1){
	values[i]=array[i-input];
}
}

for(int i=0;i<=((input*2)-1);i++){
printf("%c\n",values[i]+32);
}


return 0;
}

void shuffle(int *array, int input)
{
   int i,j,k;
	for (i = 0; i < input - 1; i++) {
	  j = i + rand() / (RAND_MAX / (input - i) + 1);
	  k = array[j];
	  array[j] = array[i];
	  array[i] = k;
	}
    
}