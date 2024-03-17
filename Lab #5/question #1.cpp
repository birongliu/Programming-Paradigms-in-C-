
//
//  main.cpp
//  The Game of Rock, Paper, and Scissors
//
//  Created by Bi Rong Liu on 3/17/24.
//

#include <iostream>
#include "string"
using namespace std;

enum ChoiceType { NONE, ROCK, PAPER, SCISSORS };

void displayRules();
bool validSelection(char selection);
string convertEnum(ChoiceType choice);
ChoiceType retrievePlay(char selection);
void prompt();
void displayGameResult(ChoiceType player1Choice, ChoiceType player2Choice);
void displayResults(int player1Score, int player2Score, int gamePlayed);
ChoiceType winningObject(ChoiceType player1, ChoiceType player2);

int main(int argc, const char * argv[]) {
    int gameCount = 0;
    int player1WinCount = 0;
    int player2WinCount = 0;
    char player1Response;
    char player2Response;
    char player1selection;
    char player2selection;
    ChoiceType player1;
    ChoiceType player2;

    displayRules();
    cout << "(Player 1) Do you want to play the game? (Y|N)";
    cin >> player1Response;
    if(player1Response != 'Y') {
        displayResults(player1WinCount, player2WinCount, gameCount);
        return 0;
    }
    cout << "(Player 2) Do you want to play the game? (Y|N)";
    cin >> player2Response;
    if(player2Response != 'Y') {
        displayResults(player1WinCount, player2WinCount, gameCount);
        return 0;
    }
    
    while(player1Response == 'Y' && player2Response == 'Y') {
        cout << "(Player 1) Which options you pick (rock=(R|r) scissors=(S|s) papers=(P|p))" << endl;
        cin >> player1selection;
        cout << "(Player 2) Which options you pick (rock=(R|r) scissors=(S|s) papers=(P|p))" << endl;
        cin >> player2selection;
        if(validSelection(player1selection) && validSelection(player2selection)) {
            gameCount+=1;
            player1 = retrievePlay(player1selection);
            player2 = retrievePlay(player2selection);
            ChoiceType win = winningObject(player1, player2);
            if(win != NONE) {
                win == player1 ? player1WinCount++ : player2WinCount++;
            }
            displayGameResult(player1, player2);
            cout << "(Player 1) Do you want to play the game again? (Y|N)";
            cin >> player1Response;
            if(player1Response == 'N') break;
            cout << "(Player 2) Do you want to play the game again? (Y|N)";
            cin >> player2Response;
        }
    }
    displayResults(player1WinCount, player2WinCount, gameCount);
    return 0;
}

void displayGameResult(ChoiceType player1Choice, ChoiceType player2Choice) {
    ChoiceType winObject = winningObject(player1Choice, player2Choice);
    if(player1Choice == player2Choice) {
        cout << "Player #1 Choice: " << convertEnum(player1Choice) << endl;
        cout << "Player #2 Choice: " << convertEnum(player2Choice) << endl;
        cout << "Result: Game is Draw" << endl;
        return;
    }
    string winner = winObject == player1Choice ? "player1" : "player2";
    cout << "Player #1 Choice: " << convertEnum(player1Choice) << endl;
    cout << "Player #2 Choice: " << convertEnum(player2Choice) << endl;
    cout << "Result: " << winner << " is the winner" << endl;
}

void displayResults(int player1Score, int player2Score, int gamePlayed) {
    cout << "Total game played: " << gamePlayed << endl;
    cout << "Player #1 Score: " << player1Score << endl;
    cout << "Player #2 Score: " << player2Score << endl;
};

ChoiceType winningObject(ChoiceType player1, ChoiceType player2) {
    if((player1 == ROCK && player2 == SCISSORS) || (player1 == PAPER && player2 == ROCK) || (player1 == SCISSORS && player2 == PAPER)) return player1;
    return player2;
}

string convertEnum(ChoiceType choice) {
    switch (choice) {
        case ROCK: return "rock";
        case PAPER: return "paper";
        case SCISSORS: return "scissors";
        case NONE: return "none";
        default: return "";
    }
}

ChoiceType retrievePlay(char selection) {
    switch (selection) {
        case 'S': return SCISSORS;
        case 's': return SCISSORS;
        case 'r': return ROCK;
        case 'R': return ROCK;
        case 'P': return PAPER;
        case 'p': return PAPER;
        default: return NONE;
    }
}

bool validSelection(char selection) {
    if(selection == 's' || selection == 'S') return true;
    if(selection == 'r' || selection == 'R') return true;
    if(selection == 'P' || selection == 'p') return true;
    return false;
}

void displayRules() {
    cout << "*********************************************************" << endl;
    cout << "*    Welcome to the game of Rock, Paper and Scissors    *" << endl;
    cout << "*********************************************************" << endl;
    cout << "Descriptions: Rock, Paper, Scissors is a two players game" << endl;
    cout << "each player select one object of rock, paper or scissor\n" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "                Rules for Winning the Game               " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "1. If both players selected the same object, it is a tie " << endl;
    cout << "2. Rock breaks Scissors: So player who selects Rock wins." << endl;
    cout << "3. Paper covers Rock: So player who selects Paper wins.  " << endl;
    cout << "4. Scissors cuts Paper: So player who selects Scissors wins.\n" << endl;
}
