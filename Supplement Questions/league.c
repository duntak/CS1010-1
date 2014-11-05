// CS1010 AY2011/2 Semester 2 
// Mock PE2 Ex2: league.c
//
// This program reads in a seasonal result table
// and print out corresponding league table. 
// After that, comparsion will be carried out between two
// input teams to find out which one is a better team.
//
// Loh Wan Xin A0085925U 

#include <stdio.h>
#include <string.h>

#define NUM 10            // 10 teams in a season

/* function prototypes */
// read the game result board
void read_board(char board[NUM][NUM]);
// calculate score for each team
void calculate_score(char board[NUM][NUM], int score[]);
// print teams in descending order of scores
void print_league_table(char team[NUM][15], int score[]);
// check which team is better, i? j?
int compare_team(char board[NUM][NUM], int score[], int i, int j);

/******************************
 * main() function
 *
 * Completed!
 ******************************/
int main(void)
{
	int i;                // counter
	char board[NUM][NUM]; // result board for NUM*(NUM-1) rounds
	int score[NUM] = {0};
	int teamA, teamB;     // two teams to compare
	int indicator;        // which team is better?
	// 1 for teamA, -1 for teamB, 0 for equal

	// 10 teams in the premier league
	char team[NUM][15] = {"West Ham", "Birmingham", "Sunderland", 
		"Liverpool", "Arsenal", "Aston Villa", 
		"Man Utd", "Everton", "Chelsea", "Man City"};

	read_board(board);                  // read game result board
	calculate_score(board, score);      // calculate score for each team
	print_league_table(team, score);    // sort in descending order

	do 
	{
		printf("\nEnter index of two teams to compare: ");
		scanf("%d %d", &teamA, &teamB);
		indicator = compare_team(board, score, teamA, teamB);

		if(indicator == 0)
			printf("%s is as competent as %s.\n", team[teamA], team[teamB]);
		else if (indicator > 0)
			printf("%s is better than %s.\n", team[teamA], team[teamB]);
		else
			printf("%s is better than %s.\n", team[teamB], team[teamA]);
	} while (++i < 4);

	return 0;
}

/*******************************************
 * read_board()
 * read seasonal game results  and stores
 * them into the two dimensional array *
 *
 * TO BE COMPLETED BY YOU
 *******************************************/
void read_board(char board[NUM][NUM])
{
	int i, j;
	
	printf("Enter result board: ");
	for(i=0;i<NUM;i++)
		for(j=0;j<NUM;j++)
		scanf(" %c",&board[i][j]);

}


/********************************************
 * print_board()
 * print out game result board just read in
 *
 * You are NOT to modify this function a bit!
 ********************************************/
void print_board(char board[NUM][NUM])
{
	int i, j; // counters for loop

	for (i=0; i<NUM; i++)
	{
		for (j=0; j<NUM; j++)
			printf("%c ", board[i][j]);      
		printf("\n");
	}
	return;
}


/*******************************************
 * calculate_score()
 * calculates the scores of every team 
 * based on the seasonal game results board
 *
 * To be completed by you
 *******************************************/
void calculate_score(char board[NUM][NUM], int score[])
{
	int i,j, team;

	for (team=0;team<NUM;team++)
			for(j=0;j<NUM;j++)
				switch(board[team][j]){
					case 'W': score[team]+=3; break;
					case 'D': score[team]++; break;
				}

	for (team=0;team<NUM;team++)
			for(i=0;i<NUM;i++)
				switch(board[i][team]){
					case 'L': score[team]+=3; break;
					case 'D': score[team]++; break;
				}
}


/*******************************************
 * compare_team()
 * check which team is better
 *
 * TO BE COMPLETED BY YOU
 *******************************************/
int compare_team(char board[NUM][NUM], int score[], int i, int j)
{
	int n,
		numWinA = 0, numWinB = 0;

	if (score[i]>score[j])
		return 1;
	else if (score[i]<score[j])
		return -1;
	else{
		if(board[i][j]=='W' || board[j][i]== 'L')
			return 1;
		else if(board[i][j]=='L' || board[j][i]=='W')
			return -1;
		
		for(n=0;n<NUM;n++)
		{
			if(board[i][n]=='W')
				numWinA++;
			if(board[n][i]=='L')
				numWinA++;
		}
		for(n=0;n<NUM;n++)
		{
			if(board[j][n]=='W')
				numWinB++;
			if(board[n][j]=='L')
				numWinB++;
		}
		
		if (numWinA>numWinB)
			return 1;
		else if (numWinA<numWinB)
			return -1;
		else 
			return 0;
	}
}


/********************************************
 * print_league_table()
 * print league table in descending score
 * order of teams.
 *
 * You are NOT to modify this function a bit!
 ********************************************/
void print_league_table(char team[NUM][15], int score[])
{
	int i, j, max, swap;     // max hold maximum score
	char hold[15];
	int temp_score[NUM];     // mirrors
	char temp_team[NUM][15];

	memcpy(temp_score, score, sizeof(int)*NUM);
	memcpy(temp_team, team, sizeof(char)*NUM*15);

	for (i=0; i<NUM-1; i++)
	{
		max = i;
		for (j=i+1; j<NUM; j++)
		{
			if (temp_score[j] > temp_score[max])
				max = j;
		}
		swap = temp_score[i];
		temp_score[i] = temp_score[max];
		temp_score[max] = swap;
		strcpy(hold, temp_team[i]);
		strcpy(temp_team[i], temp_team[max]);
		strcpy(temp_team[max], hold);
	}

	// print league table
	printf("\n    Team         Points\n");
	printf("   ======       ========\n");
	for (i=0; i<NUM; i++)
		printf("  %-15s  %2d\n", temp_team[i], temp_score[i]);
}

