#include<iostream>
#include <ctime>
using namespace std;
void board(char *arr) {
    int k = 0;
    cout << "+---+---+---+" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "|";
        for (int j = 0; j < 3; j++) {
            cout << " " << arr[k++] << " |";
        }
        cout << endl;
        cout << "+---+---+---+" << endl;
    }
}
int check(char *arr, int mode){
	int flag=-1;
	int no_result=1;  
		if(arr[0]==arr[1]&&arr[1]==arr[2]){
			if(arr[0]=='x')
			flag=1;
			else flag=2;
		}
	    else if(arr[3]==arr[4]&&arr[4]==arr[5]){
			if(arr[3]=='x')
			flag=1;
			else flag=2;
		}
		else if(arr[6]==arr[7]&&arr[7]==arr[8]){
			if(arr[6]=='x')
			flag=1;
			else flag=2;
		}
		else if(arr[0]==arr[3]&&arr[3]==arr[6]){
			if(arr[0]=='x')
			flag=1;
			else flag=2;
		}
		else if(arr[1]==arr[4]&&arr[4]==arr[7]){
			if(arr[1]=='x')
			flag=1;
			else flag=2;
		}
		else if(arr[2]==arr[5]&&arr[5]==arr[8]){
			if(arr[2]=='x')
			flag=1;
			else flag=2;
		}
		else if(arr[0]==arr[4]&&arr[4]==arr[8]){
			if(arr[0]=='x')
			flag=1;
			else flag=2;
		}
		else if(arr[2]==arr[4]&&arr[4]==arr[6]){
			if(arr[2]=='x')
			flag=1;
			else flag=2;
		}		
	if(flag==1){
		if( mode == 1)
		cout<<"Player1 won the match!\n";
		else
		cout<<"You won the match!\n";
		no_result=0;
	}
	else if(flag==2){
	    if( mode == 2)
		cout<<"You loss the match!\n";
		else
		cout<<"Player2 won the match!\n";
	    no_result=0;
    }
	return no_result;	
}
void updateBoard(char *arr) {
    
    int k = 0;
    cout << "\033[H"; // Move cursor to the top-left corner
    cout << "+---+---+---+" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "|";
        for (int j = 0; j < 3; j++) {
            if (arr[k] == 'x') {
                cout << " \033[31m" << arr[k++] << "\033[0m |"; // Red for Player1
            } 
			else if (arr[k] == 'o') {
                cout << " \033[32m" << arr[k++] << "\033[0m |"; // Green for Player2/Computer
            } 
			else {
                cout << " " << arr[k++] << " |";
            }
        }
        cout << endl;
        cout << "+---+---+---+" << endl;
    }
}
bool isValidMove(char *arr, int position) {
    return arr[position - 1] != 'x' && arr[position - 1] != 'o';
}

int main(){
	char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int mode,position;
    cout<<"Choose the Game mode!"<<endl;
    cout<<"1. Player vs Player."<<endl<<"2.Player vs Computer."<<endl;
    cin>>mode;
    for (int i = 0; i < 4; ++i) {
        cout << "\033[A\033[2K"; // Move cursor up and clear the line
    }
    	
    board(arr);  // Initial board display
    if( mode == 1){
    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            cout << "\033[31mPlayer1 Turn (X): Enter position (1-9): \033[0m";
        } 
		else {
            cout << "\033[32mPlayer2 Turn (O): Enter position (1-9): \033[0m";
        }
        cin >> position;
        while (!isValidMove(arr, position)) {
            cout << "Wrong move! Position already taken. Try again: ";
            cin >> position;
        }
        cout << "\033[A\033[2K"; //move cursor online up and clear entire line
        if (i % 2 == 0) {
            arr[position - 1] = 'x';
        } else {
            arr[position - 1] = 'o';
        }
        updateBoard(arr);  // Update the board in place
        if (check(arr,1) == 0) {
            return 0;
        }
    }
    cout << "Match is Draw!\n";
    }
    else if(mode==2){
    	srand(time(0)); // Initialize random seed once
        for (int i = 0; i < 9; i++) {
            if (i % 2 == 0) {
                cout << "\033[31mPlayer Turn (X): Enter position (1-9): \033[0m";
                cin >> position;
                while (!isValidMove(arr, position)) {
                    cout << "Wrong move! Position already taken. Try again: ";
                    cin >> position;
                }
                cout << "\033[A\033[2K"; //move cursor online up and clear entire line
                arr[position - 1] = 'x';
            } 
			else {
                cout << "\033[32mComputer Turn (O): \033[0m";
                position = 1 + rand() % 9;
                while (!isValidMove(arr, position)) {
                    position = 1 + rand() % 9;
                }
                cout << position << endl;
                arr[position - 1] = 'o';
            }
            updateBoard(arr);  // Update the board in place
            if (check(arr,2) == 0) {
                return 0;
            }
        }
        cout << "Match is Draw!\n";
	}
    return 0;
}

