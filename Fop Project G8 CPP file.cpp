#include <iostream>
#include <stdlib.h>
using namespace std;

//Using Global Variables to use same variables in all functions.
char model[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//2D array using char to hold values like X and Y.
int row,column;
int choice;
char turn = 'X';
bool first = true;
bool turndone = false;
bool draw = false;

void display_game(){
    //Game Board layout which displays the 2D array.
    cout<<"\t\t\tT I C -- T A C -- T O E -- G A M E\t\t\t";
    cout<<"\n\t\t\t\tPLAYER vs Computer\n\t\t\t";
		    cout<<"PLAYER - [X]\t CPU - [O]\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<model[0][0]<<"  |  "<<model[0][1]<<"  |  "<<model[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<model[1][0]<<"  |  "<<model[1][1]<<"  |  "<<model[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<model[2][0]<<"  |  "<<model[2][1]<<"  |  "<<model[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}

void player_turn(){
    //user inputs value showing where to input your choice in a 3X3 grid.
	cout<<"It is your turn . Please enter your choice"<<endl;
	cin>> choice;
	//using switch operator to input specific value
	switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }
    //Checking if the selected choice isn't already filled either by cpu or player.
    if(model[row][column] != 'X' && model[row][column] != 'O'){
        //inputs X there.
        model[row][column] = 'X';
        //gives turn to CPU
        turn = 'O';
    }
    else {
        cout<<"Box already filled\n Please choose another\n";
        player_turn();//recursive function.
    }
    display_game();//displays refreshed game board after each move.
}

void system_turn()
{
	turndone = false;
	//The First move is a special case. as choice can be made anywhere hence using rand operator.
	if(first == true)
	{
		int r = 1+ (rand()%2);
		for(int i=0; i<3; i++)
    	for(int j=0; j<3; j++)
    	{//Finding X placed by player on the grid to place an O around it at random.
    		if(model[i][j]=='X'){
    		if(j==2)
    		model[i][j-1]='O';
    		else
    		{if(r==1)
    		model[i+1][j]='O';
    		else if(r==2)
    		model[i][j+1]='O';}
    		    
    		}
    	first = false;
    	//first move has ended.
		}
	}//If turn isnt first, CPU plays normally, Trying to win or stop player from winning.
	else {
		for(int i=0; i<3; i++)
		{//For loop cycles through every possible itteration of the grid where 3 adjacent O can be make and checks if O can win by placing three adjacent Os.
		    if(model[i][0]=='O' && model[i][1] =='O' && model[i][2] != 'X' && model[i][2]!='O')
			{
				model[i][2] = 'O';
				turndone = true;
				break;
			}
			else if(model[i][0] =='O' && model[i][2]=='O' && model[i][1] != 'X' && model[i][1] !='O' )
			{
				model[i][1] = 'O';
				turndone = true;
				break;
			}
			else if( model[i][1] =='O' && model[i][2]=='O' && model[i][0] !='X' && model[i][0] !='O' )
			{
				model[i][0] ='O';
				turndone = true;
				break;
			}
			else if(model[0][i] =='O' && model[1][i] == 'O'&& model[2][i] !='X' && model[2][i] !='O')
			{
				model[2][i] = 'O';
				turndone = true;
				break;
			}
			else if(model[0][i] =='O' && model[2][i]=='O' && model[1][i] != 'X' && model[1][i] !='O' )
			{
				model[1][i] = 'O';
				turndone = true;
				break;
			}
			else if( model[1][i] =='O' && model[2][i]=='O' && model[0][i] !='X' && model[0][i] !='O' )
			{
				model[0][i] ='O';
				turndone = true;
				break;
			}//Now its going to check all possible diagonal places for winning oppurtunities.
			else if( model[0][0] =='O' && model[1][1]=='O' && model[2][2] !='X' && model[2][2] !='O' )
			{
				model[2][2] ='O';
				turndone = true;
				break;
			}
			else if( model[0][0] =='O' && model[2][2]=='O' && model[1][1] !='X' && model[1][1] !='O' )
			{
				model[1][1] ='O';
				turndone = true;
				break;
			}
			else if( model[2][2] =='O' && model[1][1]=='O' && model[0][0] !='X' && model[0][0] !='O' )
			{
				model[0][0] = 'O';
				turndone = true;
				break;
				
			}
			else if( model[0][2] =='O' && model[1][1]=='O' && model[2][0] !='X' && model[2][0] !='O' )
			{
				model[2][0] ='O';
				turndone = true;
				break;
			}
			else if( model[2][0] =='O' && model[1][1]=='O' && model[0][2] !='X' && model[0][2] !='O' )
			{
				model[0][2] ='O';
				turndone = true;
				break;
			}
			else if( model[0][2] =='O' && model[2][0]=='O' && model[1][1] !='X' && model[1][1] !='O' )
			{
				model[1][1] ='O';
				turndone = true;
				break;
			}
		}
				
		if(turndone == false)//If CPU cant find any winning opportunities,
		{//CPU will try to stop X from winning by putting O in it's way.
			for(int i=0; i<3; i++)
		{//It again goes through each possible row and column to find and stop 3 X's.
			if(model[i][0]=='X' && model[i][1] =='X' && model[i][2] != 'X' && model[i][2]!='O')
			{
				model[i][2] = 'O';
				turndone = true;
				break;
			}
			else if(model[i][0] =='X' && model[i][2]=='X' && model[i][1] != 'X' && model[i][1] !='O' )
			{
				model[i][1] = 'O';
				turndone = true;
				break;
			}
			else if( model[i][1] =='X' && model[i][2]=='X' && model[i][0] !='X' && model[i][0] !='O' )
			{
				model[i][0] ='O';
				turndone = true;
				break;
			}
			else if(model[0][i] =='X' && model[1][i] == 'X'&& model[2][i] !='X' && model[2][i] !='O')
			{
				model[2][i] = 'O';
				turndone = true;
				break;
			}
			else if(model[0][i] =='X' && model[2][i]=='X' && model[1][i] != 'X' && model[1][i] !='O' )
			{
				model[1][i] = 'O';
				turndone = true;
				break;
			}
			else if( model[1][i] =='X' && model[2][i]=='X' && model[0][i] !='X' && model[0][i] !='O' )
			{
				model[0][i] ='O';
				turndone = true;
				break;
			}//Checking the diagonals for winning possibilities
			else if( model[0][0] =='X' && model[1][1]=='X' && model[2][2] !='X' && model[2][2] !='O' )
			{
				model[2][2] ='O';
				turndone = true;
				break;
			}
			else if( model[0][0] =='X' && model[2][2]=='X' && model[1][1] !='X' && model[1][1] !='O' )
			{
				model[1][1] ='O';
				turndone = true;
				break;
			}
			else if( model[2][2] =='X' && model[1][1]=='X' && model[0][0] !='X' && model[0][0] !='O' )
			{
				model[0][0] = 'O';
				turndone = true;
				break;
				
			}
			else if( model[0][2] =='X' && model[1][1]=='X' && model[2][0] !='X' && model[2][0] !='O' )
			{
				model[2][0] ='O';
				turndone = true;
				break;
			}
			else if( model[2][0] =='X' && model[1][1]=='X' && model[0][2] !='X' && model[0][2] !='O' )
			{
				model[0][2] ='O';
				turndone = true;
				break;
			}
			else if( model[0][2] =='X' && model[2][0]=='X' && model[1][1] !='X' && model[1][1] !='O' )
			{
				model[1][1] ='O';
				turndone = true;
				break;
			}}

		}
		if(turndone== false)
		{
		for(int i=0; i<3; i++)
		{
			if(turndone==true)
			break;
		for(int j=0; j<3; j++)
		{
		 if(model[i][j] != 'X' && model[i][j] != 'O')
		 {
		 model[i][j]= 'O';
		 turndone = true;
	}
	if(turndone==true)
	break;
	}
	}
    }
    }
		turn = 'X';	}
bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(model[i][0] == model[i][1] && model[i][0] == model[i][2] || model[0][i] == model[1][i] && model[0][i] == model[2][i])
    return false;

    //checking the win for both diagonal

    if(model[0][0] == model[1][1] && model[0][0] == model[2][2] || model[0][2] == model[1][1] && model[0][2] == model[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(model[i][j] != 'X' && model[i][j] != 'O')
    return true;

    //Checking the if game already draw
    draw = true;
    return false; 
}


int main() {
	bool win = true;
    display_game();//Displays game board.
    //In game
    while(gameover()){//checks if game is in continue mode or not.
        system("cls"); 
       system("Color 03");//Added colors just to make the game more fun...
        display_game();//Displays the Game board using Function
        player_turn();// Gives the First turn to the PLayer
       win = gameover();//Checks if 
       if(win==false)//False if win or draw..then it will break loop. And provide result.
       break;
        system_turn();//Gives the turn to CPU
        gameover();
    }
    system("cls");//Color system
    display_game();//Displays Final Game board.
    if(turn == 'X' && draw == false){//if last move was made by CPU and the game ended and it isnt Draw.
        cout<<"\n\n\t\t CPU has won the game\n\t\t BOOHOO You lost\n";//CPU won
			system("Color 04");
    }
    else if(turn == 'O' && draw == false){//If last move was by Player and the game ended and isnt draw
        cout<<"\n\n\t\tCongratulations! You have won the game\n";//Player Won.
            system("Color 0A");
    }
    else
    cout<<"\n\n\t\tGAME DRAW!!!Bummer...\n\n";//It's a draw
	return 0;
}





