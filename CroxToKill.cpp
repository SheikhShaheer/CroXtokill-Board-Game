#include <iostream>
using namespace std;

/**
 * Initializing the board with empty values. Here '*' means empty.
 */
char board[9] = {'*','*','*','*','*','*','*','*','*'};

/**
 * Function to draw the game board.
 * 
 * @return void
 */
void draw_board()
{
	system("CLS");
	cout<<"\t\t\t\t\t"<<"\nEach position is marked with number 0-9.\nTo place your coins enter number accordingly"<<endl;
    cout<<"\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t"<<board[0]<<"-------"<<board[1]<<"-------"<<board[2]<<endl;
    cout<<"\t\t\t\t\t"<<"|"<<"\t"<<"|"<<"\t"<<"|"<<endl;
    cout<<"\t\t\t\t\t"<<board[3]<<"-------"<<board[4]<<"-------"<<board[5]<<endl;
    cout<<"\t\t\t\t\t"<<"|"<<"\t"<<"|"<<"\t"<<"|"<<endl;
    cout<<"\t\t\t\t\t"<<board[6]<<"-------"<<board[7]<<"-------"<<board[8]<<endl;
	cout<<"\t\t\t\t\t"<<"\n";
}

/**
 * Function to Check wether Player 1 win or not.
 * 
 * @return int
 */
int player1Won() 
{
	for( int i=0; i<9; i++ ) {
		if( 'X' == board[i] ) {
			return 0;
		}
	}
	return 1;
}

/**
 * Function to Check wether Player 2 win or not.
 * 
 * @return int
 */
int player2Won()
{
	for( int i=0; i<9; i++ ) {
		if( 'O' == board[i] ) {
			return 0;
		}
	}
	return 1;
}

/**
 * Function to Check wether its a draw or not.
 * 
 * @return int
 */
int matchDraw() {
	int emptySpots = 0;
	for( int i=0; i<9; i++ ) {
		if( '*' == board[i] ) {
			emptySpots+=1;
		}
	}
	
	if( 7 == emptySpots ) {
		return 1;
	}
	return 0;
}

/**
 * Function to jump coin over one tile.
 *
 * @param int oldPosition Current Position of the player's coin. 
 * @param int newPosition New Position of the player's coin.
 * @param int choice Determine which player's turn it is... 
 * 
 * @return bool
 */
bool oneJump( int oldPosition, int newPosition, int choice ) 
{
	
	bool success    = true;
	
	if(board[newPosition] == '*')
	{
		board[oldPosition] = '*';
		board[newPosition] = choice;
	}
	else
	{
		success = false;
	}
	
	return success;
}

/**
 * Function to jump coin over two tiles.
 *
 * @param int oldPosition Current Position of the player's coin. 
 * @param int newPosition New Position of the player's coin.
 * @param int choice Determine which player's turn it is... 
 * 
 * @return bool
 */
bool twoJump( int oldPosition, int newPosition, int choice ) 
{

	int midPosition = (oldPosition+newPosition)/2;
	bool success    = true;

	if (board[midPosition] == '*' || board[midPosition] == choice)
	{
		success = false;
	}
	else 
	{
		if (board[newPosition] == '*')
		{
			board[oldPosition] = '*';
			board[midPosition] = '*';
			board[newPosition] = choice;
		}
		else 
		{
			success = false;
		}
	}
	return success;
}

/**
 * Function to move player position.
 *
 * @param int oldPosition Current Position of the player's coin. 
 * @param int newPosition New Position of the player's coin.
 * @param int choice Determine which player's turn it is... 
 * 
 * @return bool
 */
bool playerMove(int oldPosition, int newPosition, int choice)
{
	bool check = true;
	// Position for 0
	if(oldPosition == 0 && board[0] == choice)
	{
		if(newPosition == 1)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if(newPosition == 2)
		{
			check = twoJump( oldPosition, newPosition, choice );
		}
		else if(newPosition == 3)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if(newPosition == 6)
		{
			check = twoJump( oldPosition, newPosition, choice );
		}
		else 
		{
			cout<<"Wrong Move... ";
			check = false;
		}
	}
	// Position for 1
	else if(oldPosition == 1 && board[1] == choice)
	{
		if(newPosition == 0)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if(newPosition == 2)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if(newPosition == 4)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if(newPosition == 7)
		{
			check = twoJump( oldPosition, newPosition, choice );
		}
		else 
		{
			cout<<"Wrong Move... ";
			check = false;
		}
	}
	// Position for 2
	else if(oldPosition == 2  && board[2] == choice)
	{
		if(newPosition == 0)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if (newPosition == 1)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if (newPosition == 5)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if (newPosition == 8)
		{
			check = twoJump( oldPosition, newPosition, choice );
		}
		else 
		{
			cout<<"Wrong Move... ";
			check = false;
		}
	}
	// Position for 3
	else if(oldPosition == 3  && board[3] == choice)
	{
		if(newPosition == 0)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if (newPosition == 4)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if (newPosition == 6)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if (newPosition == 5)
		{
			check = twoJump( oldPosition, newPosition, choice );
		}
		else 
		{
			cout<<"Wrong Move... ";
			check = false;
		}
	}
	// Position for 4
	else if(oldPosition == 4  && board[4] == choice)
	{
		if(newPosition == 1)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if(newPosition == 3)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if (newPosition == 5)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if (newPosition == 7)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else
		{
			cout<<"Wrong Move... ";
			check = false;
		}
	}
	// Position for 5
	else if(oldPosition == 5  && board[5] == choice)
	{
		if(newPosition == 2)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if (newPosition == 8)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if(newPosition == 4)			
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if (newPosition == 3)
		{
			check = twoJump( oldPosition, newPosition, choice );
		}
		else 
		{
			cout<<"Wrong Move... ";
			check = false;
		}
	}
	// Position for 6
	else if(oldPosition == 6  && board[6] == choice)
	{
		if(newPosition == 3)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if (newPosition == 7)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if (newPosition == 0)
		{
			check = twoJump( oldPosition, newPosition, choice );
		}
		else if (newPosition == 8)
		{
			check = twoJump( oldPosition, newPosition, choice );
		}
		else 
		{
			cout<<"Wrong Move... ";
			check = false;
		}
	}
	// Position for 7
	else if(oldPosition == 7  && board[7] == choice)
	{
		if(newPosition == 8)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if(newPosition == 6) 
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if(newPosition == 4)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if (newPosition == 1)
		{
			check = twoJump( oldPosition, newPosition, choice );
		}
		else 
		{
			cout<<"Wrong Move... ";
			check = false;
		}
	}
	// Position for 8
	else if(oldPosition == 8  && board[8] == choice)
	{
		if(newPosition == 5)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if(newPosition == 7)
		{
			check = oneJump( oldPosition, newPosition, choice );
		}
		else if(newPosition == 6)
		{
			check = twoJump( oldPosition, newPosition, choice );
		}
		else if(newPosition == 2)
		{
			check = twoJump( oldPosition, newPosition, choice );
		}
		else 
		{
			cout<<"Wrong Move... ";
			check = false;
		}
	}
	else
	{
		cout<<"You Cannot Move Other Players Coin... ";
		check = false;
	}
	return check;
}

/**
 * Function to handle the positioning of players.
 * @param int choice Determine which player's turn it is... 
 * 
 * @return void
 */
void playersPositioning ( int choice = 2 ) 
{
	int move = 0;
	int playerFirst  = 0;
	
	//	Drawing the board...
	draw_board();
		
	if( 1 == choice ) {
		checkMove:cout<<endl<<"Player 1 Move: ";
		cin>>move;
		
		if( 0 <= move && 8 >=move && '*' == board[move] ) {
			board[move] = 'O';
			draw_board();
		}
		else{
			cout<<"Wrong Move..."<<endl;
			goto checkMove;
		}
		playerFirst = 1;
	}

	for( int i=0; i<4; i++ ) {
	
		player2:cout<<endl<<"Player 2 Move:";
        cin>>move;
        if( 0 <= move && 8 >=move && '*' == board[move] ) {
			board[move] = 'X';
			draw_board();
	    }
	    else
	    {
	        cout<<endl<<"Wrong Move...";
	        goto player2;
	    }
	    
		if( 1 == playerFirst && 3 == i ) {
			break;
		}	

		player1:  cout<<endl<<"Player 1 Move:";
        cin>>move;
        if( 0 <= move && 8 >=move && 'O' != board[move] ) {
			board[move] = 'O';
			draw_board();
	    }
	    else
	    {
	        cout<<endl<<"Wrong Move...";
	        goto player1;
	    }
	    
	}	
}

/**
 * Function to strart the game.
 * @param int choice Determine which player's turn it is... 
 * 
 * @return void
 */
void playGame( int choice = 2 ) {
	int oldPosition;
	int newPosition;

	cout<< "All Positions Set!! Now you can play..." <<endl;
	while( true ) {
		
		if( 1 == choice ) {
			player1Turn:cout<<"Player 1 Turn...\n"<<endl;
			cout<<"Which coin you want to move: ";
			cin>>oldPosition;
	
			cout<<"Where do you want to move: ";
			cin>>newPosition;

			if( playerMove( oldPosition, newPosition, 'O' ) ) {
				draw_board();
			}
			else{
				cout<<"Wrong Move..."<<endl;
				goto player1Turn;
			}
		}
		
		player2turn:cout<<"Player 2 Turn...\n"<<endl;
		cout<<"Which coin you want to move: ";
		cin>>oldPosition;

		cout<<"Where do you want to move: ";
		cin>>newPosition;

		if( playerMove( oldPosition, newPosition, 'X' ) ) {
			draw_board();
		}
		else{
			cout<<"Wrong Move..."<<endl;
			goto player2turn;
		}
		choice = 1;

		if( player1Won() ) {
			cout<<"\n\n\n********** PLAYER 1 WON !!!!!! ********** \n\n\n";
			break;
		}
		else if( player2Won() ) {
			cout<<"\n\n\n********** PLAYER 2 WON !!!!!! ********** \n\n\n";
			break;
		}
		else if( matchDraw() ) {
			cout<<"\n\n\n********** Match Drawn !!!!!! ********** \n\n\n";
			break;
		}

	}
}

/**
 * Function to initialize the game.
 * 
 * @return int
 */
int main () {
	
	int choice = 0;
	 
	cout<<"Player 1 -> O     Player 2 -> X"<< endl;
	
	//	Asking about who start first...
	cout<<"\nFor choice  Press '1' "<<endl;
	cout<<"For computer  Press '2 "<<endl;
	cout<<"\nWho start first? ";
	cin>>choice;
	
	// Ask the players to palce there coins...
	playersPositioning(choice);

	// Play the game...
	playGame(choice);
	
	return 0;
}

