#include <stdio.h>
#include <stdlib.h>
//Definitions
const int GENERATION_COUNT = 50;
const int ARRAY_LENGTH = 100;
#define null_char '_'
#define full_char '#'
//Function signatures
void print_state(int state_to_print[]) //takes an array and outputs '#' if the value is 1 and outputs '_' if the value is 0. Outputs only one state.
{
	int indice;
	for(indice=0;indice<ARRAY_LENGTH;indice++)
	{
		if(state_to_print[indice]==0)
		{
			printf("%c ",null_char); //prints '_'
		}
		else
		{
			printf("%c ",full_char); //prints '#'	
		
		}
	}
	printf("\n"); //new line

}
int rule_30_look_up(int current_state[],int next_state[],int indice) //looks up and finds next state's indice. RULE 30 
{
		if(current_state[indice-1]==0 && current_state[indice]==0 && current_state[indice+1]==0) // 000 -> 0
		{
			next_state[indice]=0;
		}
		else if(current_state[indice-1]==0 && current_state[indice]==0 && current_state[indice+1]==1) // 001 -> 1
		{
			next_state[indice]=1;
		}
		else if(current_state[indice-1]==0 && current_state[indice]==1 && current_state[indice+1]==0) // 010 -> 1
		{
			next_state[indice]=1;
		}
		else if(current_state[indice-1]==0 && current_state[indice]==1 && current_state[indice+1]==1) // 011 -> 1
		{
			next_state[indice]=1;
		}
		else if(current_state[indice-1]==1 && current_state[indice]==0 && current_state[indice+1]==0) // 100 -> 1
		{
			next_state[indice]=1;
		}
		else if(current_state[indice-1]==1 && current_state[indice]==0 && current_state[indice+1]==1) // 101 -> 0
		{
			next_state[indice]=0;
		}
		else if(current_state[indice-1]==1 && current_state[indice]==1 && current_state[indice+1]==0) // 110 -> 0
		{
			next_state[indice]=0;
		}
		else if(current_state[indice-1]==1 && current_state[indice]==1 && current_state[indice+1]==1) 
		{
			next_state[indice]=0;
		}
}
void calculate_next_state(int current_state[], int next_state[],int indice)
{
	
	rule_30_look_up(current_state,next_state,indice);
	next_state[0]=0;
	next_state[99]=0;
	
	
}	
void swap_arrays(int current_state[], int next_state[])
{
	int i;
	for(i=0;i<ARRAY_LENGTH;i++)
	{
		current_state[i]=next_state[i];
	}
}	
int main()
{
	int indice,gen_count; 
	int middle_point = (ARRAY_LENGTH/2)-1; 
	int current_state[ARRAY_LENGTH], next_state[ARRAY_LENGTH]; 
	for(indice=0;indice<ARRAY_LENGTH;indice++)
	{
		if(indice==middle_point)
			current_state[indice]=1; 
		else	
	 		current_state[indice]=0; 
	}
	print_state(current_state); 
	
	for(gen_count=0;gen_count<GENERATION_COUNT;gen_count++)
	{
		for(indice=0;indice<ARRAY_LENGTH;indice++)
		{
			calculate_next_state(current_state,next_state,indice);
		}
		print_state(next_state);
		swap_arrays(current_state,next_state); 
	}
	return 0;	
}

