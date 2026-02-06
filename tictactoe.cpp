#include <iostream>
using namespace std;

void how2Play() {
    cout << "how to play\n"
        "1- each player gets his turn\n"
        "2-press r to restart and q to quit\n"
        "3-input the number where you want to make you're play as shown below\n"
        " 1 | 2 | 3 \n"
        "---+---+---\n"
        " 4 | 5 | 6 \n"
        "---+---+---\n"
        " 7 | 8 | 9 \n"
        "\n\n\n"
        ;
}
string  colors(char a) {
    if (a == 'X') {
        return  "\033[31mX\033[0m";
    }
    else if (a == 'O') {
        return  "\033[32mO\033[0m";
    }
    else return " ";
}
void grid(char* t) {
    cout << " " << colors(t[0]) << " | " << colors(t[1]) << " | " << colors(t[2]) << "\n"
        "---+---+---\n " <<
        colors(t[3]) << " | " << colors(t[4]) << " | " << colors(t[5]) << "\n"
        "---+---+---\n " <<
        colors(t[6]) << " | " << colors(t[7]) << " | " << colors(t[8]) << "\n"
        ;
}
bool checkWin(char* t) {
    for (int i{ 0 };i < 9; i += 3) {
        if (t[i] == t[i + 1] && t[i] == t[i + 2] && t[i] != ' ') {
            return true;
        }
    }
    for (int i{ 0 };i < 3;i++) {
        if (t[i] == t[i + 3] && t[i] == t[i + 6] && t[i] != ' ') {
            return true;
        }
    }
    if (t[0] == t[4] && t[0] == t[8] && t[0] != ' ' || t[2] == t[4] && t[2] == t[6] && t[2] != ' ') {
        return true;
    }
    return false;
}
bool checkDraw(char* t) {
    for (int i{ 0 };i < 9;i++) {
        if (t[i] !='X' && t[i] !='O') {
            return false;
        }
    }
    return true;
}
void reset(char* t) {
    cout << "\033[2J\033[H";
    how2Play();
    grid(t);
}
void modifyElements(char* t) {
    static int x = 0;
    char c;
    (x % 2 == 0) ? c = 'O' : c = 'X';
    int nbElement;
    cout << "its " << c << "'s turn \n";
    cin >> nbElement;
    if (t[nbElement-1] == ' ') {
        t[nbElement-1] = c;
        x++;
    }
    reset(t);
    if (checkWin(t)){ cout <<c<<" won game over\n";}
    else if (checkDraw(t)) { cout << "draw\n"; }
    else{
        modifyElements(t);
    };
}
int main()
{
    char tab[9] = { ' ', ' ', ' ',
                    ' ',' ',' ',
                    ' ',' ',' ' };

    how2Play();
    grid(tab);
    modifyElements(tab);
}

