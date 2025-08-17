#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

void showBoard() {
    cout << "\n";
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool win(char p) {
    // rows & columns
    for(int i=0;i<3;i++)
        if(board[i][0]==p && board[i][1]==p && board[i][2]==p) return true;
    for(int j=0;j<3;j++)
        if(board[0][j]==p && board[1][j]==p && board[2][j]==p) return true;
    // diagonals
    if(board[0][0]==p && board[1][1]==p && board[2][2]==p) return true;
    if(board[0][2]==p && board[1][1]==p && board[2][0]==p) return true;
    return false;
}

bool validMove(int r,int c) {
    return board[r][c] != 'X' && board[r][c] != 'O';
}

int main() {
    srand(time(0));
    char human = 'X', comp = 'O';
    int move, r, c, moves = 0;

    while(moves < 9) {
        // human turn
        showBoard();
        cout << "Your turn (1-9): ";
        cin >> move;
        r = (move-1)/3; c = (move-1)%3;
        if(move<1 || move>9 || !validMove(r,c)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }
        board[r][c] = human;
        moves++;
        if(win(human)) {
            showBoard();
            cout << "You win!\n";
            return 0;
        }
        if(moves >= 9) break;

        // computer turn (random move)
        do {
            move = rand()%9 + 1;
            r = (move-1)/3; c = (move-1)%3;
        } while(!validMove(r,c));
        board[r][c] = comp;
        cout << "Computer chose " << move << "\n";
        moves++;
        if(win(comp)) {
            showBoard();
            cout << "Computer wins!\n";
            return 0;
        }
    }

    showBoard();
    cout << "It's a draw!\n";
    return 0;
}
