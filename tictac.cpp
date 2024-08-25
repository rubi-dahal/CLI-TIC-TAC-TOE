#include <iostream>
#include <ctime> // For time function
#include <random> // For random number generation

//colors
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */

// Namespace
using namespace std;

// Function prototypes
void clearScreen(); // Function to clear the screen
void showBoard(); // Function to display the board
void player_x(); // Function to get the move of the player X
void player_o(); // Function to get the move of the player O
void computer(); // Function to generate the move of the computer
char checkWin(); // Function to check if a player has won
int countBoard(char symbol); // Function to count the number of moves of a player
void computer_vs_player(); // Function to play the game between the computer and the player
void player_vs_player(); // Function to play the game between two players
void clearInputBuffer(); // Function to clear the input buffer
void printColoredXorO(char c);

// Board array to store the moves of the players
char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
int main()
{
    // Display the welcome message
    cout << GREEN << "WELCOME TO THE GAME OF TIC TAC TOE" << RESET << endl;
    cout << "The game is starting now." << endl;
    cout << "Choose the mode of the game you want to play." << endl;
    cout << "1. " << CYAN << "COMPUTER VS PLAYER" << RESET << endl;
    cout << "2. " << CYAN << "PLAYER VS PLAYER" << RESET << endl;
    cout << "ENTER YOUR CHOICE: ";

    // Get the choice of the user
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            computer_vs_player();
            break;
        case 2:
            player_vs_player();
            break;
        default:
            cout << RED << "INVALID CHOICE" << RESET << endl;
    }

    return 0;
}

// Computer function to generate the move of the computer
void computer(){
    srand( time(0));
    int choice;
    // Generate a random number between 0 and 8 and check if the move is valid
    do{
        // Generate a random number between 0 and 8
        choice=rand()%9;
    }while(board[choice]!=' ');
    board[choice]='O';
}


// Function to get the move of the player O
void player_o(){
    int choice;
    cout<<"Enter your move: ";
    cin>>choice;
    choice--;
    // Check if the move is valid
    if(board[choice]==' '){
        board[choice]='O';
    }
    else{
        cout<<"Invalid move"<<endl;
        player_o();
    }
}

// Function to get the move of the player X
void player_x(){
    int choice;
    cout<<"Enter your move: ";
    cout<<GREEN;
    cin>>choice;
    cout<<RESET;
    choice--;
    // Check if the move is valid
    if(board[choice]==' '){
        board[choice]='X';
    }
    else{
        cout <<RED<<"Invalid move"<<endl<<RESET;
        player_x();
    }
}

// Function to display the board
void showBoard(){
    
    cout << "      |      |      " << endl;
    cout << "  "; printColoredXorO(board[0]); cout << RESET << "   |  "; printColoredXorO(board[1]); cout<< "   |  "; printColoredXorO(board[2]); cout<< endl;
    cout << "______|______|______" << endl;
    cout << "      |      |      " << endl;
    cout << "  "; printColoredXorO(board[3]); cout << RESET << "   |  "; printColoredXorO(board[4]); cout<< "   |  "; printColoredXorO(board[5]); cout << endl;
    cout << "______|______|______" << endl;
    cout << "      |      |      " << endl;
    cout << "  "; printColoredXorO(board[6]); cout << RESET << "   |  "; printColoredXorO(board[7]); cout<< "   |  "; printColoredXorO(board[8]); cout << endl;
    cout << "      |      |      " << endl;
}
// Function to check if a player has won
char checkWin(){
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
        return board[0];
    else if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        return board[3];
    else if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        return board[6];
    else if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
        return board[0];
    else if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        return board[1];
    else if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
        return board[2];
    else if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
        return board[0];
    else if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        return board[2];
    else
        return ' ';
}

// Function to count the number of moves of a player
int countBoard(char symbol){
    int count=0;
    for(int i=0;i<9;i++){
        if(board[i]==symbol){
            count++;
        }
    }
    return count;
}

// Function to play the game between the computer and the player
void computer_vs_player(){
    string player;
    clearInputBuffer();
    cout << "ENTER YOUR NAME: ";
    cout<<GREEN;
    getline(cin, player);
    cout<<RESET;

    while (true) {
        clearScreen();
        showBoard();

        if (countBoard('X') == countBoard('O')) {
            player_x();
        }
        else {
            computer();
        }

        char winner = checkWin();
        if (winner == 'X') {
            clearScreen();
            showBoard();
            cout << GREEN << player << " WINS" << RESET << endl;
            break;
        }
        else if (winner == 'O') {
            clearScreen();
            showBoard();
            cout << RED << "Computer WINS" << RESET << endl;
            break;
        }
        else if (countBoard('X') + countBoard('O') == 9) {
            clearScreen();
            showBoard();
            cout << YELLOW << "IT'S A DRAW" << RESET << endl;
            break;
        }
    }
}

// Function to play the game between two players
void player_vs_player(){
    string player1,player2;
    // Clear the input buffer to avoid any errors in input
    clearInputBuffer();
    cout << "ENTER THE NAME OF PLAYER 1: ";
    cout<<GREEN;
    getline(cin,player1);
    cout<<RESET;
    cout << "ENTER THE NAME OF PLAYER 2: ";
    cout<<CYAN;
    getline(cin,player2);
    cout<<RESET;
    while(true) {
        clearScreen();
        showBoard();
        if(countBoard('X') == countBoard('O')){
            cout << GREEN << "Player 1's Turn" << RESET << endl;
            player_x();
        }
        else{
            cout << CYAN << "Player 2's Turn" << RESET << endl;
            player_o();
        }
        char winner = checkWin();
        if(winner=='X'){
            clearScreen();
            showBoard();
            cout << GREEN << "Player 1 WINS" << RESET << endl;
            break;
        }
        else if(winner=='O'){
            clearScreen();
            showBoard();
            cout << CYAN << "Player 2 WINS" << RESET << endl;
            break;
        }
        else if(countBoard('X')+countBoard('O')==9){
            clearScreen();
            showBoard();
            cout << YELLOW << "IT'S A DRAW!" << RESET << endl;
            break;
        }
    }
}

void clearInputBuffer(){
    // Clear the input buffer get rid /n character from the buffer
   while(cin.get()!='\n'){
    continue;
}
}

void clearScreen(){
    // Clear the screen
    system("cls");
}

void printColoredXorO(char c){
    if(c=='X'){
        cout<<GREEN<<c<<RESET;
    }
    else if(c=='O'){
        cout<<CYAN<<c<<RESET;
    }
    else{
        cout<<c;
    }
}