//Final Project
//


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void easy(void);
void medium(void);
void hard(void);


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
									easy();
												 }
								if(difficulty==2){
									medium();
												  }
								if(difficulty==3){
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