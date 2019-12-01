//Final Project
//


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void easy(void);
void medium(void);
void hard(void);
void shuffle(int *array, int n);
void randomize(int level);


int main(void){
	int choice,difficulty;
	FILE *scores;
	scores=fopen("scores.txt","r");
	if(scores==NULL){
		printf("Can't open %s\n","scores.txt");
	}
	else
	{
	do{
	printf("***MEMORY!***\n1 - Play Game\n2 - Check Scores\n0 - EXIT\n");
	scanf("%d",&choice);
		switch(choice){
						case 1:{
							printf("Enter difficulty (1, 2, or 3):");
							scanf("%d",&difficulty);
								if(difficulty==1){
									randomize(difficulty);
									easy();

												 }
								if(difficulty==2){
									randomize(difficulty);
									medium();
												  }
								if(difficulty==3){
									randomize(difficulty);
									hard();
												  }
							break;
						        }
						case 2:{
							printf("**HIGH SCORES**\n");
							break;
								}
						case 0:{
							break;
							    }
						default:{
							printf("Please enter a valid selection\n");
							break;
						         }

					   }
	  }
	  while(choice!=0);
}

	return 0;
}

void easy(void){
	printf("[ ][ ]\n[ ][ ]\nEnter your coordinates from 1 to 2\n");
	//scanf("%d %d");
	printf("Enter your coordinates from 1 to 2\n");
	//scanf("%d %d");
	return;
}

void medium(void){
	printf("[ ][ ][ ][ ]\n[ ][ ][ ][ ]\n[ ][ ][ ][ ]\n[ ][ ][ ][ ]\nEnter your coordinates from 1 to 4\n");
	//scanf("%d %d");
	printf("Enter your coordinates from 1 to 4\n");
	//scanf("%d %d");
	return;
}

void hard(void){
	printf("[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\nEnter your coordinates from 1 to 6\n");
	//scanf("%d %d");
	printf("Enter your coordinates from 1 to 6\n");
	//scanf("%d %d");
	return;
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

void randomize(int level){
	int input,lower=1;
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


return ;
}