#include <iostream>
#include <string>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
bool tie = false;
string n1, n2;
char token = 'X';

void displayBoard() {
    cout << "  |   |  \n";
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << " \n";
    cout << "___|___|___\n";
    cout << "  |   |  \n";
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << " \n";
    cout << "___|___|___\n";
    cout << "  |   |  \n";
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << " \n";
    cout << "  |   |  \n";
}

void functionOne() { 
    cout << "Enter the name of the first player: ";
    getline(cin, n1);
    cout << "Enter the name of the second player: ";
    getline(cin, n2);

    cout << n1 << " is player 1 and will play first.\n";
    cout << n2 << " is player 2 and will play second.\n";

    displayBoard();
}

void functionTwo() {
    int digit;
    if (token == 'X') {
        cout << n1 << ", please enter your move: ";
    } else {
        cout << n2 << ", please enter your move: ";
    }
    cin >> digit;

    switch(digit) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default: 
            cout << "Invalid move! Please try again.\n";
            functionTwo();
            return;
    }

    if (space[row][column] != 'X' && space[row][column] != 'O') {
        space[row][column] = token;
        token = (token == 'X') ? 'O' : 'X';
    } else {
        cout << "There is no empty space, try again.\n";
        functionTwo();
    }
    displayBoard();
}

bool functionThree() {
    for (int i = 0; i < 3; ++i) {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2])
            return true;
        if (space[0][i] == space[1][i] && space[0][i] == space[2][i])
            return true;
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2])
        return true;
    if (space[0][2] == space[1][1] && space[1][1] == space[2][0])
        return true;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (space[i][j] != 'X' && space[i][j] != 'O') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main() {
    functionOne();
    while (!functionThree()) {
        functionTwo();
    }

    if (token == 'X' && !tie) {
        cout << n2 << " wins!\n";
    } else if (token == 'O' && !tie) {
        cout << n1 << " wins!\n";
    } else {
        cout << "It's a draw!\n";
    }

    return 0;
}
