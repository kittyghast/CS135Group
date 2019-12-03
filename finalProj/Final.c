//Final Project
//


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void easy(int values[4],int grid[2][2]);
void medium(int values[16],int grid[4][4]);
void hard(int values[36],int grid[6][6]);
void shuffle(int *array, int n);
void randomize(int level,int values[4]);


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
							printf("Enter difficulty (1, 2, or 3): ");
							scanf("%d",&difficulty);
								if(difficulty==1){
									int values[4];
									int grid[2][2];
									randomize(difficulty,values);
									easy(values,grid);

												 }
								if(difficulty==2){
									int values[16];
									int grid[4][4];
									randomize(difficulty,values);
									medium(values,grid);
												  }
								if(difficulty==3){
									int values[36];
									int grid[6][6];
									randomize(difficulty,values);
									hard(values,grid);
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

void easy(int values[4],int grid[2][2]){
	int choice1x,choice1y,choice2x,choice2y;
	int k=0;
	int holder=0;
	int score=4;

	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
		grid[i][j]=values[k];
			k++;
	}
}
	printf("[ ][ ]\n[ ][ ]\n");
	while(holder<2){
	printf("Enter your coordinates from 1 to 2\n");
	scanf("%d %d",&choice1x,&choice1y);
	printf("Enter your coordinates from 1 to 2\n");
	scanf("%d %d",&choice2x,&choice2y);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	for(int i=0;i<=1;i++){
				for(int j=0;j<=1;j++){
					if(i==(choice1x-1)&&j==(choice1y-1)){
						printf("[%c]",grid[i][j]);
						}
					else if(i==(choice2x-1)&&j==(choice2y-1)){
						printf("[%c]",grid[i][j]);
						}
					else{
						printf("[ ]");
					}
					}
					printf("\n");
	}
		if(grid[choice1x-1][choice1y-1]==grid[choice2x-1][choice2y-1]){
			holder++;
			
	printf("match\n");
		}
		else{
	printf("No match\n");
	score--;
}

}
printf("Score is %d\n",score);

	return;
}

void medium(int values[16],int grid[4][4]){
	int choice1x,choice1y,choice2x,choice2y;
	int k=0;
	for(int i=0;i<=3;i++){
		for(int j=0;j<=3;j++){
		grid[i][j]=values[k];
			k++;
	}
}
	printf("[ ][ ][ ][ ]\n[ ][ ][ ][ ]\n[ ][ ][ ][ ]\n[ ][ ][ ][ ]\nEnter your coordinates from 1 to 4\n");
	scanf("%d %d",&choice1x,&choice1y);
	printf("Enter your coordinates from 1 to 4\n");
	scanf("%d %d",&choice2x,&choice2y);
		if(grid[choice1x-1][choice1y-1]==grid[choice2x-1][choice2y-1]){
			printf("Match");
		}
		else{
			printf("No match");
		}

	return;
}

void hard(int values[36],int grid[6][6]){
	int choice1x,choice1y,choice2x,choice2y;
	int k=0;
	for(int i=0;i<=5;i++){
			for(int j=0;j<=5;j++){
			grid[i][j]=values[k];
				k++;
			printf("Grid[%d][%d]=%c\n",i,j,grid[i][j]);
	}
}
	printf("[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\nEnter your coordinates from 1 to 6\n");
	scanf("%d %d",&choice1x,&choice1y);
	printf("Enter your coordinates from 1 to 6\n");
	scanf("%d %d",&choice2x,&choice2y);
		if(grid[choice1x-1][choice1y-1]==grid[choice2x-1][choice2y-1]){
			printf("Match");
		}
		else{
			printf("No match");
		}
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

void randomize(int level,int values[4]){
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
	
	


srand(time(0));
for(int i=0;i<=input-1;i++){
array[i]=(i+1);
}


shuffle(array,input);

for(int i=0;i<=((input*2)-1);i++){
if(i<=input-1){
	values[i]=array[i]+32;
}
if(i>input-1){
	values[i]=array[i-input]+32;
}
}



shuffle(values,(input*2));

for(int i=0;i<=((input*2)-1);i++){
printf("%c\n",values[i]);
}



return ;
}