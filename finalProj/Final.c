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
								else if(difficulty==2){
									int values[16];
									int grid[4][4];
									randomize(difficulty,values);
									medium(values,grid);
												  }
								else if(difficulty==3){
									int values[36];
									int grid[6][6];
									randomize(difficulty,values);
									hard(values,grid);
												  }
								else if(difficulty != 1 || difficulty != 2 || difficulty != 3){
									printf("ERROR: INVALID OPTION\nRETURNING TO TITLE SCREEN...\n");
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


//easy mode
void easy(int values[4],int grid[2][2]){
	//choice1x + 1y are first choice, choice2x + 2y
	int choice1x,choice1y,choice2x,choice2y;
	int k=0;
	int holder=0;
	int score=4;
	int check[2][2] = {{0, 0}, {0, 0}};

	//table population
	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
			grid[i][j]=values[k];
			k++;
		}
	}

	//game start
	printf("[ ][ ]\n[ ][ ]\n");

	while(holder < 4){ /*Improved Logic*/
		//resets win state
		holder = 0;
		//First choice
		printf("Enter your coordinates from 1 to 2\n");
		scanf("%d %d",&choice1x,&choice1y);
		choice1x--; /*Added this bit to clean up code so we don't have to put in choice#x-1 every other step*/
		choice1y--;
		
		//Second choice
		printf("Enter your coordinates from 1 to 2\n");
		scanf("%d %d",&choice2x,&choice2y);
		choice2x--;
		choice2y--;
		
		//New page
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

		//Logic for game display
		for(int i=0;i<=1;i++){
				for(int j=0;j<=1;j++){
					if(check[i][j] == 1){
						printf("[%c]", grid[i][j]);
					}
					else if(i==(choice1x)&&j==(choice1y)){
						printf("[%c]",grid[i][j]);
					}
					else if(i==(choice2x)&&j==(choice2y)){
						printf("[%c]",grid[i][j]);
					}
					else{
						printf("[ ]");
					}
				}
				printf("\n");
		}

		//match logic
		if(grid[choice1x][choice1y]==grid[choice2x][choice2y]){
			check[choice1x][choice1y] = 1;
			check[choice2x][choice2y] = 1;
			printf("match\n");
		}
		else{
			printf("No match\n");
			score--;
		}
		//wincheck
                for(int i=0; i<2; i++){
                        for(int j=0; j<2; j++){
                                if(check[i][j] == 1){
                                        holder++;
                                }

			}
		}
}
printf("Score is %d\n",score);

	return;
}


//Medium 
void medium(int values[16],int grid[4][4]){
    
    //initilize vars
	int choice1x,choice1y,choice2x,choice2y;
	int k=0;
	int holder=0;
	int score=16;
	int check[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	
	//table popolation
	for(int i=0;i<=3;i++){
		for(int j=0;j<=3;j++){
		grid[i][j]=values[k];
			k++;
	    }
    }
     
    //game start
	printf("[ ][ ][ ][ ]\n[ ][ ][ ][ ]\n[ ][ ][ ][ ]\n[ ][ ][ ][ ]\n");
	
	
    while(holder < 16){
	    //reset win state
	    holder = 0;
	    //first choice
	    printf("Enter your coordinates from 1 to 4\n");
	    scanf("%d %d",&choice1x,&choice1y);
        choice1x--;
        choice1y--;
        //second choice
	    printf("Enter your coordinates from 1 to 4\n");
	    scanf("%d %d",&choice2x,&choice2y);
	    choice2x--;
	    choice2y--;
	    
	    //New page
	    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    
	    //logic fro game display
	    for (int i=0;i<4;i++){
	        for (int j=0;j<4;j++){
	            if(check[i][j] == 1){
					printf("[%c]", grid[i][j]);
				}
					else if(i==(choice1x)&&j==(choice1y)){
						printf("[%c]",grid[i][j]);
				}
					else if(i==(choice2x)&&j==(choice2y)){
						printf("[%c]",grid[i][j]);
				}
					else{
						printf("[ ]");
				}
			}
				printf("\n");
		}
		
		//match logic
		if(grid[choice1x][choice1y]==grid[choice2x][choice2y]){
			check[choice1x][choice1y] = 1;
			check[choice2x][choice2y] = 1;
			printf("Match\n");
		}
		else{
			printf("No match\n");
			score--;
		}

        //wincheck
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(check[i][j] == 1){
                    holder++;
                }
            }
        }
    }
    
    printf("Score is %d\n", score);
    
	return;
}

//hard mode
void hard(int values[36],int grid[6][6]){

    //declare
	int choice1x,choice1y,choice2x,choice2y;
	int k=0;
	int holder=0;
	int score=36;
	int check[6][6] = {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
	
	//populate
	for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
			    grid[i][j]=values[k];
				k++;
			    printf("Grid[%d][%d]=%c\n",i,j,grid[i][j]);
	        }
    }
    
    //game start
	printf("[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n");
	
	
	while(holder<36){
	    //reset win state
	    holder = 0;
	    //first choice
	    printf("Enter your coordinates from 1 to 6\n");    
	    scanf("%d %d",&choice1x,&choice1y);
	    choice1x--;
	    choice1y--;
	    //second choice
	    printf("Enter your coordinates from 1 to 6\n");
	    scanf("%d %d",&choice2x,&choice2y);
	    choice2x--;
	    choice2y--;
	    
	    //New page
	    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    
	    //game display logic
	    for (int i=0;i<6;i++){
	        for (int j=0;j<6;j++){
	            if(check[i][j] == 1){
					printf("[%c]", grid[i][j]);
				}
					else if(i==(choice1x)&&j==(choice1y)){
						printf("[%c]",grid[i][j]);
				}
					else if(i==(choice2x)&&j==(choice2y)){
						printf("[%c]",grid[i][j]);
				}
					else{
						printf("[ ]");
				}
			}
				printf("\n");
		}	    
	    
	    //match logic
	  

		    if(grid[choice1x][choice1y]==grid[choice2x][choice2y]){
		    	check[choice1x][choice1y] = 1;
		    	check[choice2x][choice2y] = 1;
		    	printf("Match\n");
		    }
		    else{
		    	printf("No match\n");
		    	score--;
		    }
		    
		//wincheck
		for(int i=0; i<6; i++){
            for(int j=0; j<6; j++){
                if(check[i][j] == 1){
                    holder++;
                }
            }
        }
    }
    printf("Score id %d\n",score);
        
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
