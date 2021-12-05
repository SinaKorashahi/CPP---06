#include <iostream>
#include<Windows.h>
#include<ctime>
#include<random>
#include<chrono>
using std::cin;
using std::cout;
using namespace std::chrono;

HANDLE I = GetStdHandle(STD_OUTPUT_HANDLE);
char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };
void onePlayer();
void twoPlayer();
unsigned int checkwin();
void board();

unsigned int main()
{
    unsigned int select;
    cout << "1. one player\n2. co-op\nSelect your choice:";
    cin >> select;
    auto start = high_resolution_clock::now();
    if (select == 1)
        onePlayer();
    else if (select == 2)
        twoPlayer();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "Time: " << duration.count() << " Second\n";
    return 0;
}
unsigned int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
          && square[4] != '4' && square[5] != '5' && square[6] != '6'
          && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}
void board()
{
    system("cls");
    cout << "Player 1 (";
    SetConsoleTextAttribute(I, 0x3);
    cout << 'X';
    SetConsoleTextAttribute(I, 0x7);
    cout << ")";
    cout << "- Player 2 (";
    SetConsoleTextAttribute(I, 0x4);
    cout << 'O';
    SetConsoleTextAttribute(I, 0x7);
    cout << ")\n";
    cout << "     |     |     \n  ";
    if (square[1] == 'X')
    {
        SetConsoleTextAttribute(I, 0x3);
        cout << square[1];
        SetConsoleTextAttribute(I, 0x7);
    }
    else if (square[1] == 'O')
    {
        SetConsoleTextAttribute(I, 0x4);
        cout << square[1];
        SetConsoleTextAttribute(I, 0x7);
    }
    else
        cout << square[1];
    cout << "  |  ";
    if (square[2] == 'X')
    {
        SetConsoleTextAttribute(I, 0x3);
        cout << square[2];
        SetConsoleTextAttribute(I, 0x7);
    }
    else if (square[2] == 'O')
    {
        SetConsoleTextAttribute(I, 0x4);
        cout << square[2];
        SetConsoleTextAttribute(I, 0x7);
    }
    else
        cout << square[2];
    cout << "  |  ";
    if (square[3] == 'X')
    {
        SetConsoleTextAttribute(I, 0x3);
        cout << square[3];
        SetConsoleTextAttribute(I, 0x7);
    }
    else if (square[3] == 'O')
    {
        SetConsoleTextAttribute(I, 0x4);
        cout << square[3];
        SetConsoleTextAttribute(I, 0x7);
    }
    else
        cout << square[3];
    cout << "\n_____|_____|_____\n     |     |     \n  ";
    if (square[4] == 'X')
    {
        SetConsoleTextAttribute(I, 0x3);
        cout << square[4];
        SetConsoleTextAttribute(I, 0x7);
    }
    else if (square[4] == 'O')
    {
        SetConsoleTextAttribute(I, 0x4);
        cout << square[4];
        SetConsoleTextAttribute(I, 0x7);
    }
    else
        cout << square[4];
    cout << "  |  ";
    if (square[5] == 'X')
    {
        SetConsoleTextAttribute(I, 0x3);
        cout << square[5];
        SetConsoleTextAttribute(I, 0x7);
    }
    else if (square[5] == 'O')
    {
        SetConsoleTextAttribute(I, 0x4);
        cout << square[5];
        SetConsoleTextAttribute(I, 0x7);
    }
    else
        cout << square[5];
    cout << "  |  ";
    if (square[6] == 'X')
    {
        SetConsoleTextAttribute(I, 0x3);
        cout << square[6];
        SetConsoleTextAttribute(I, 0x7);
    }
    else if (square[6] == 'O')
    {
        SetConsoleTextAttribute(I, 0x4);
        cout << square[6];
        SetConsoleTextAttribute(I, 0x7);
    }
    else
        cout << square[6];
    cout << "\n_____|_____|_____\n     |     |     \n  ";
    if (square[7] == 'X')
    {
        SetConsoleTextAttribute(I, 0x3);
        cout << square[7];
        SetConsoleTextAttribute(I, 0x7);
    }
    else if (square[7] == 'O')
    {
        SetConsoleTextAttribute(I, 0x4);
        cout << square[7];
        SetConsoleTextAttribute(I, 0x7);
    }
    else
        cout << square[7];
    cout << "  |  ";
    if (square[8] == 'X')
    {
        SetConsoleTextAttribute(I, 0x3);
        cout << square[8];
        SetConsoleTextAttribute(I, 0x7);
    }
    else if (square[8] == 'O')
    {
        SetConsoleTextAttribute(I, 0x4);
        cout << square[8];
        SetConsoleTextAttribute(I, 0x7);
    }
    else
        cout << square[8];
    cout << "  |  ";
    if (square[9] == 'X')
    {
        SetConsoleTextAttribute(I, 0x3);
        cout << square[9];
        SetConsoleTextAttribute(I, 0x7);
    }
    else if (square[9] == 'O')
    {
        SetConsoleTextAttribute(I, 0x4);
        cout << square[9];
        SetConsoleTextAttribute(I, 0x7);
    }
    else
        cout << square[9];
    cout << "\n     |     |     \n\n";
 }
void onePlayer()
{
    unsigned int player = 1, choice;
    int i;
    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number:  ";
        if (player == 1)
            cin >> choice;
        else if (player == 2)
        {
            srand(time(0));
            choice = rand() % 10;
        }

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            if (player == 1)
                cout << "Invalid move";
            --player;
            cin.ignore();
            cin.get();
        }
        i = checkwin();
        ++player;
    } while (i == -1);
    board();
    if (i == 1)

        cout << "==>\aPlayer " << --player << " win ";
    else
        cout << "==>\aGame draw";
    cin.ignore();
    cin.get();
}
void twoPlayer()
{
    unsigned int player = 1, choice;
    int i;
    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else
        {
            cout << "Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i = checkwin();
        player++;
    } while (i == -1);
    board();
    if (i == 1)
        cout << "==>\aPlayer " << --player << " win ";
    else
        cout << "==>\aGame draw";
    cin.ignore();
    cin.get();
}

