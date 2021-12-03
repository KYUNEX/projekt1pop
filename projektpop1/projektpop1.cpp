#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Funkcja rysuje planszę gry w kółko i krzyżyk
//---------------------------------------------
void plansza(char t[])
{
    for (int i = 1; i <= 36; i++)
    {
        cout << " " << t[i] << " ";
        if (i % 6)
            cout << "|";
        else if (i != 36)
            cout << "\n---+---+---+---+---+---\n";
        else cout << endl;
    }
}

// Funkcja zwraca true, jeśli nastąpiła
// wygrana danego zawodnika
//-------------------------------------
bool wygrana(char t[], char g)
{
    bool sprawdz;
    sprawdz = false;

    for (int i = 1; i <= 31; i += 6) {
        sprawdz |= ((t[i] == g) && (t[i + 1] == g) && (t[i + 2] == g) && (t[i + 3] == g) && (t[i + 4] == g));
    }
    for (int i = 2; i <= 32; i += 6) {
        sprawdz |= ((t[i] == g) && (t[i + 1] == g) && (t[i + 2] == g) && (t[i + 3] == g) && (t[i + 4] == g));
    }
    for (int i = 1; i <= 6; i += 1) {
        sprawdz |= ((t[i] == g) && (t[i + 6] == g) && (t[i + 12] == g) && (t[i + 18] == g) && (t[i + 24] == g));
    }
    for (int i = 7; i <= 12; i += 1) {
        sprawdz |= ((t[i] == g) && (t[i + 6] == g) && (t[i + 12] == g) && (t[i + 18] == g) && (t[i + 24] == g));
    }
    for (int i = 1; i <= 36; i += 1) {
        sprawdz |= ((t[1] == g) && (t[8] == g) && (t[15] == g) && (t[22] == g) && (t[29] == g));
        sprawdz |= ((t[8] == g) && (t[15] == g) && (t[22] == g) && (t[29] == g) && (t[36] == g));
        sprawdz |= ((t[2] == g) && (t[9] == g) && (t[16] == g) && (t[23] == g) && (t[30] == g));
        sprawdz |= ((t[7] == g) && (t[14] == g) && (t[21] == g) && (t[28] == g) && (t[35] == g));

    }

    if (sprawdz)
    {
        plansza(t);
        cout << "\nGRACZ " << g << " WYGRYWA!!!\n\n";
        return true;
    }
    return false;
}

// Funkcja zwraca true, jeśli na planszy nie ma już
// żadnego wolnego pola na ruch.
//-------------------------------------------------
bool remis(char t[])
{
    for (int i = 1; i <= 36; i++)
        if (t[i] == ' ') return false;
    plansza(t);
    cout << "\nREMIS !!!\n\n";
    return true;
}

// Funkcja umożliwia ruch gracza
// Po ruchu następuje zamiana gracza
//------------------------------------

void ruch(char t[], char& symbol, char nick1[], char nick2[], bool nastepny)
{
    int runda = 1;
    int r;
    char r1[15];
    string nick;
    nick = nick1;
    char symb1 = 'O';
    char symb2 = 'X';


    while (runda < 100000) {
        plansza(t);

        if (runda % 2 == 1) {
            nick = nick1;
        }
        else {
            nick = nick2;
        }
        cout << "\nGRACZ " << nick << " : Twoj ruch : ";
        cin >> r1;

        r = atoi(r1);

        if (strcmp(r1, "help") == 0) cout << "Wybierz liczbe z przedzialu 1-36" << endl;
        cout << "-----------------------\n\n";

        system("cls");

        if ((r >= 1) && (r <= 36) && (t[r] == ' ') && !(t[r] == symb1) && !(t[r] == symb2)) {                //czy pole jest wolne 

            if (symbol == symb1) {
                nick = nick2;
                symbol = symb2;
                cout << "if1" << endl;
            }
            else {
                symbol = symb1;
                nick = nick1;
                cout << "else1" << endl;
            }

            runda++;
            nastepny = true;
            t[r] = symbol;
            cout << "Wolne miejsce" << endl;
        }
        else {
            cout << "Te pole jest juz zajete, popraw swoj ruch!!!" << endl;
            nastepny = false;
        }

        cout << "nr rundy: " << runda << endl;
    }
}


int main()
{
    char p[37], symbol, w;
    bool nastepny;
    char nick1[15];
    char nick2[15];
    char symb1 = 'O';
    char symb2 = 'X';
    cout << "Podaj nick gracza 1: ";
    cin >> nick1;
    cout << "Podaj nick gracza 2: ";
    cin >> nick2;
    do
    {
        cout << "Gra w Kolko i Krzyzyk dla dwoch graczy\n"
            "======================================\n\n";
        for (int i = 1; i <= 36; i++) p[i] = ' ';
        symbol = symb2;
        nastepny = true;
        while (!wygrana(p, symb1) && !wygrana(p, symb2) && !remis(p)) ruch(p, symbol, nick1, nick2, nastepny);
        cout << "Jeszcze raz ? (T = TAK) : ";
        cin >> w;
        cout << "\n\n\n";

    } while ((w == 'T') || (w == 't'));
}