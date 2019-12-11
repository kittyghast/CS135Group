// Steven Inman
// Mickey Kerr
// CS 135
// Project 9
// 12/10/2019


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int easy(int values[4],int grid[2][2],int *score_out);
int medium(int values[16],int grid[4][4],int *score_out);
int hard(int values[36],int grid[6][6],int *score_out);
void shuffle(int *array, int n);
void randomize(int level,int values[4]);
void save_name(int score_input);
void display_scores(void);


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
									int score_out;
									int save; 
									
									randomize(difficulty,values);
									save=easy(values,grid,&score_out);
									if(save==1){
										save_name(score_out);
									}
													}
								else if(difficulty==2){
									int values[16];
									int grid[4][4];
									int score_out;
									int save; 
									randomize(difficulty,values);
									save=medium(values,grid,&score_out);
									if(save==1){
										save_name(score_out);
												  }
												}
								else if(difficulty==3){
									int values[36];
									int grid[6][6];
									int score_out;
									int save; 
									randomize(difficulty,values);
									save=hard(values,grid,&score_out);
									if(save==1){
										save_name(score_out);
												  }
												}
								else if(difficulty != 1 || difficulty != 2 || difficulty != 3){
									printf("ERROR: INVALID OPTION\nRETURNING TO TITLE SCREEN...\n");
								}
							break;
						        }
						case 2:{
							printf("**HIGH SCORES**\n");
								display_scores();
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
int easy(int values[4],int grid[2][2],int *score_out){
	//choice1x + 1y are first choice, choice2x + 2y
	int choice1x,choice1y,choice2x,choice2y;
	int k=0;
	int holder=0;
	int score=4;
	int save_state;
	int check[2][2] = {{0, 0}, {0, 0}};

	//table population
	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
			grid[i][j]=values[k];
			k++;
		}
	}

	//game start

printf("\n[ ][ ]\n[ ][ ]\n");
	while(holder < 4){ /*Improved Logic*/
		//resets win state
		holder = 0;
		
		//First choice
		printf("Enter your coordinates from 1 to 2\n");
		scanf("%d %d",&choice1x,&choice1y);
			if(choice1x>2 || choice1y>2 || choice1x<1 || choice1y<1){
			do{printf("Please enter valid coordinates between 1 and 2\n");
				scanf("%d %d",&choice1x,&choice1y);
			}
			while(choice1x>3 || choice1y>3 || choice1x<1 || choice1y<1);
			}

		
		choice1x--; /*Added this bit to clean up code so we don't have to put in choice#x-1 every other step*/
		choice1y--;
		
		//Second choice
		printf("Enter your coordinates from 1 to 2\n");
		scanf("%d %d",&choice2x,&choice2y);
		if(choice2x>2 || choice2y>2 || choice2x<1 || choice2y<1){
			do{printf("Please enter valid coordinates between 1 and 2\n");
				scanf("%d %d",&choice2x,&choice2y);
			}
			while(choice2x>3 || choice2y>3 || choice2x<1 || choice2y<1);
			}

		choice2x--;
		choice2y--;
		
		//New page
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

		//Logic for game display
			for(int i=0;i<=1;i++){
				for(int j=0;j<=1;j++){
					
					if(i==(choice1x)&&j==(choice1y)){
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
		printf("\n");
		//Logic for game display
		

		//match logic
		if(grid[choice1x][choice1y]==grid[choice2x][choice2y]){
			check[choice1x][choice1y] = 1;
			check[choice2x][choice2y] = 1;
			printf("MATCHED!\n");
		}
		else{
			printf("\n");
			score--;
		}

		for(int i=0;i<=1;i++){
				for(int j=0;j<=1;j++){
					if(check[i][j] == 1){
						printf("[%c]", grid[i][j]);
										}
					else{
						printf("[ ]");
					}
				}
				printf("\n");
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
if(score<=0){
    	score=0;
    }
printf("%d points!",score);
*score_out=score;

printf("\nSave score? 1 - yes: ");
scanf("%d",&save_state);
if(save_state==1){
	return 1;
}	
else{
	return 0;}
	
}

//Medium 
int medium(int values[16],int grid[4][4],int *score_out){
    
    //initilize vars
	int choice1x,choice1y,choice2x,choice2y;
	int k=0;
	int holder=0;
	int score=16;
	int save_state;
	int check[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	
	//table popolation
	for(int i=0;i<=3;i++){
		for(int j=0;j<=3;j++){
		grid[i][j]=values[k];
			k++;
	    }
    }
     
    //game start
	printf("\n[ ][ ][ ][ ]\n[ ][ ][ ][ ]\n[ ][ ][ ][ ]\n[ ][ ][ ][ ]\n");
	
	
    while(holder < 16){
	    //reset win state
	    holder = 0;
	    //first choice
	    printf("Enter your coordinates from 1 to 4\n");
		scanf("%d %d",&choice1x,&choice1y);
			if(choice1x>4 || choice1y>4 || choice1x<1 || choice1y<1){
			do{printf("Please enter valid coordinates between 1 and 4\n");
				scanf("%d %d",&choice1x,&choice1y);
			}
			while(choice1x>5 || choice1y>5 || choice1x<1 || choice1y<1);
			}

		
		choice1x--; /*Added this bit to clean up code so we don't have to put in choice#x-1 every other step*/
		choice1y--;
		
		//Second choice
		printf("Enter your coordinates from 1 to 4\n");
		scanf("%d %d",&choice2x,&choice2y);
		if(choice2x>4 || choice2y>4 || choice2x<1 || choice2y<1){
			do{printf("Please enter valid coordinates between 1 and 4\n");
				scanf("%d %d",&choice2x,&choice2y);
			}
			while(choice2x>5 || choice2y>5 || choice2x<1 || choice2y<1);
			}

		choice2x--;
		choice2y--;
	    
	    //New page
	    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    
	    //logic fro game display
	    for(int i=0;i<=3;i++){
				for(int j=0;j<=3;j++){
					
					if(i==(choice1x)&&j==(choice1y)){
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
		printf("\n");
		//Logic for game display
		

		//match logic
		if(grid[choice1x][choice1y]==grid[choice2x][choice2y]){
			check[choice1x][choice1y] = 1;
			check[choice2x][choice2y] = 1;
			printf("MATCHED!\n");
		}
		else{
			printf("\n");
			score--;
		}

		for(int i=0;i<=3;i++){
				for(int j=0;j<=3;j++){
					if(check[i][j] == 1){
						printf("[%c]", grid[i][j]);
										}
					else{
						printf("[ ]");
					}
				}
				printf("\n");
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
    if(score<=0){
    	score=0;
    }
   printf("%d points!",score);
*score_out=score;

printf("\nSave score? 1 - yes: ");
scanf("%d",&save_state);
if(save_state==1){
	return 1;
}	
else{
	return 0;}
	
}

//hard mode
int hard(int values[36],int grid[6][6],int *score_out){

    //declare
	int choice1x,choice1y,choice2x,choice2y;
	int k=0;
	int holder=0;
	int score=36;
	int save_state;
	int check[6][6] = {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
	
	//populate
	for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
			    grid[i][j]=values[k];
				k++;
			    
	        }
    }
    
    //game start
	printf("\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ][ ]\n");
	
	
	while(holder<36){
	    //reset win state
	    holder = 0;
	    //first choice
	    printf("Enter your coordinates from 1 to 6\n");
		scanf("%d %d",&choice1x,&choice1y);
			if(choice1x>6 || choice1y>6 || choice1x<1 || choice1y<1){
			do{printf("Please enter valid coordinates between 1 and 6\n");
				scanf("%d %d",&choice1x,&choice1y);
			}
			while(choice1x>6 || choice1y>6 || choice1x<1 || choice1y<1);
			}

		
		choice1x--; /*Added this bit to clean up code so we don't have to put in choice#x-1 every other step*/
		choice1y--;
		
		//Second choice
		printf("Enter your coordinates from 1 to 6\n");
		scanf("%d %d",&choice2x,&choice2y);
		if(choice2x>6 || choice2y>6 || choice2x<1 || choice2y<1){
			do{printf("Please enter valid coordinates between 1 and 6\n");
				scanf("%d %d",&choice2x,&choice2y);
			}
			while(choice2x>6 || choice2y>6 || choice2x<1 || choice2y<1);
			}

		choice2x--;
		choice2y--;
	    
	    //New page
	    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    
	    //game display logic
	   

		for(int i=0;i<=5;i++){
				for(int j=0;j<=5;j++){
					
					if(i==(choice1x)&&j==(choice1y)){
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
		printf("\n");
		//Logic for game display
		

		//match logic
		if(grid[choice1x][choice1y]==grid[choice2x][choice2y]){
			check[choice1x][choice1y] = 1;
			check[choice2x][choice2y] = 1;
			printf("MATCHED!\n");
		}
		else{
			printf("\n");
			score--;
		}

		for(int i=0;i<=5;i++){
				for(int j=0;j<=5;j++){
					if(check[i][j] == 1){
						printf("[%c]", grid[i][j]);
										}
					else{
						printf("[ ]");
					}
				}
				printf("\n");
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
    if(score<=0){
    	score=0;
    }
   printf("%d points!",score);
*score_out=score;

printf("\nSave score? 1 - yes: ");
scanf("%d",&save_state);
if(save_state==1){
	return 1;
}	
else{
	return 0;}
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
//printf("%c\n",values[i]);
}
return ;
}


void save_name(int score_input){
	char *name_input;
	name_input=malloc(100);


	FILE *file,*output,*rewrite;
	
	output=fopen("scores.txt","a");
	file=fopen("scores.txt","r");

	printf("Enter your name: ");
	scanf("%s",name_input);

	fprintf(output,"%d %s\n",score_input,name_input);

	fclose(output);
	char *string;
	string=malloc(100);
	char array[11][30];
	int scores[11];
	int score=0;
	int counter=0;
	int holder;
	char c_holder[30];
	for(int i=0;i<=11;i++){
	fscanf(file,"%d",&score);
	fscanf(file,"%s",string);
	if(feof(file))
		break;
	counter++;
	strcpy(array[i],string);
	scores[i]=score;
	}
	//printf("Counter is %d\n",counter);
	fclose(file);
	int indicator=0;
	if(counter<=11){
		for(int i=0;i<counter-1;i++){
			for(int j=i+1;j<counter;j++){
				if(scores[j]>scores[i]){
					indicator=1;
					holder=scores[j];
					scores[j]=scores[i];
					scores[i]=holder;
					strcpy(c_holder,array[j]);
					strcpy(array[j],array[i]);
					strcpy(array[i],c_holder);
				}

				}
			}

		}
		if(counter>=11 && indicator==0){
			counter=10;
			scores[9]=score;
			strcpy(array[9],string);}

	rewrite=fopen("scores.txt","w");
	for(int i=0;i<=counter-1;i++){

		fprintf(rewrite,"%d %s\n",scores[i],array[i]);
		//printf("%d %s\n",scores[i],array[i]);
		}
fclose(rewrite);
	return;
	}
void display_scores(){

	FILE *file;

	file=fopen("scores.txt","r");
	char *string;
	string=malloc(100);
	int score=0;
	for(int i=0;i<=9;i++){
	fscanf(file,"%d",&score);
	fscanf(file,"%s",string);
	if(feof(file))
		break;
	printf("%d %s\n",score,string);
	
							}
	fclose(file);


	return;
}