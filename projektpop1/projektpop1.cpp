#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Rysowanie planszy
void plansza(char* t) {
    {
        cout << "╔═══╦═══╦═══╦═══╦═══╦═══╗" << endl;

        for (int i = 1; i <= 36; i++)
        {
            cout << "║ " << t[i] << " ";


            if (i % 6)
                cout << "";

            else if (i != 36)
                cout << "║" << "\n╠═══╬═══╬═══╬═══╬═══╬═══╣\n";

            else
                cout << "║" << endl;

        }
        cout << "╚═══╩═══╩═══╩═══╩═══╩═══╝" << endl;
    }

}



//podzial planszy na cwiartki
int cwiartkanaidx(char cwiartka, char nr) {
    if (cwiartka == 'q' && nr == '1')
        return 13;
    if (cwiartka == 'q' && nr == '2')
        return 14;
    if (cwiartka == 'q' && nr == '3')
        return 15;
    if (cwiartka == 'q' && nr == '4')
        return 7;
    if (cwiartka == 'q' && nr == '5')
        return 8;
    if (cwiartka == 'q' && nr == '6')
        return 9;
    if (cwiartka == 'q' && nr == '7')
        return 1;
    if (cwiartka == 'q' && nr == '8')
        return 2;
    if (cwiartka == 'q' && nr == '9')
        return 3;
    if (cwiartka == 'w' && nr == '1')
        return 16;
    if (cwiartka == 'w' && nr == '2')
        return 17;
    if (cwiartka == 'w' && nr == '3')
        return 18;
    if (cwiartka == 'w' && nr == '4')
        return 10;
    if (cwiartka == 'w' && nr == '5')
        return 11;
    if (cwiartka == 'w' && nr == '6')
        return 12;
    if (cwiartka == 'w' && nr == '7')
        return 4;
    if (cwiartka == 'w' && nr == '8')
        return 5;
    if (cwiartka == 'w' && nr == '9')
        return 6;
    if (cwiartka == 'a' && nr == '1')
        return 31;
    if (cwiartka == 'a' && nr == '2')
        return 32;
    if (cwiartka == 'a' && nr == '3')
        return 33;
    if (cwiartka == 'a' && nr == '4')
        return 25;
    if (cwiartka == 'a' && nr == '5')
        return 26;
    if (cwiartka == 'a' && nr == '6')
        return 27;
    if (cwiartka == 'a' && nr == '7')
        return 19;
    if (cwiartka == 'a' && nr == '8')
        return 20;
    if (cwiartka == 'a' && nr == '9')
        return 21;
    if (cwiartka == 's' && nr == '1')
        return 34;
    if (cwiartka == 's' && nr == '2')
        return 35;
    if (cwiartka == 's' && nr == '3')
        return 36;
    if (cwiartka == 's' && nr == '4')
        return 28;
    if (cwiartka == 's' && nr == '5')
        return 29;
    if (cwiartka == 's' && nr == '6')
        return 30;
    if (cwiartka == 's' && nr == '7')
        return 22;
    if (cwiartka == 's' && nr == '8')
        return 23;
    if (cwiartka == 's' && nr == '9')
        return 24;
}



//sprawdzenie czy ktorys gracz wygral
bool wygrana(char* t, char s)
{
    bool sprawdz;
    sprawdz = false;

    for (int i = 1; i <= 31; i += 6) {
        sprawdz |= ((t[i] == s) && (t[i + 1] == s) && (t[i + 2] == s) && (t[i + 3] == s) && (t[i + 4] == s));
    }
    for (int i = 2; i <= 32; i += 6) {
        sprawdz |= ((t[i] == s) && (t[i + 1] == s) && (t[i + 2] == s) && (t[i + 3] == s) && (t[i + 4] == s));
    }
    for (int i = 1; i <= 6; i += 1) {
        sprawdz |= ((t[i] == s) && (t[i + 6] == s) && (t[i + 12] == s) && (t[i + 18] == s) && (t[i + 24] == s));
    }
    for (int i = 7; i <= 12; i += 1) {
        sprawdz |= ((t[i] == s) && (t[i + 6] == s) && (t[i + 12] == s) && (t[i + 18] == s) && (t[i + 24] == s));
    }
    for (int i = 1; i <= 36; i += 1) {
        sprawdz |= ((t[1] == s) && (t[8] == s) && (t[15] == s) && (t[22] == s) && (t[29] == s));
        sprawdz |= ((t[8] == s) && (t[15] == s) && (t[22] == s) && (t[29] == s) && (t[36] == s));
        sprawdz |= ((t[2] == s) && (t[9] == s) && (t[16] == s) && (t[23] == s) && (t[30] == s));
        sprawdz |= ((t[7] == s) && (t[14] == s) && (t[21] == s) && (t[28] == s) && (t[35] == s));

    }

    if (sprawdz) {
        plansza(t);
        system("cls");
        cout << "\nGRACZ " << s << " WYGRYWA!!!\n\n";

        return true;
    }
    return false;
}

// sprawdzenie czy wystapil remis (wszystkie pola sa zajete)
bool remis(char* t)
{
    for (int i = 1; i <= 36; i++)
        if (t[i] == ' ') return false;
    plansza(t);
    cout << "\nREMIS !!!\n\n";
    return true;
}



//umozliwienie odpowiedniego ruchu gracza
void ruch(char* t, char& symbol, char nick1[], char nick2[], bool nastepny, char symbol1, char symbol2, int* runda, bool* gra)
{

    int r;
    char w;
    char r1[4];
    string nick;
    nick = nick1;
    char symb1 = symbol1;
    char symb2 = symbol2;

    while (*runda < 100000) {

        cout << "Nick gracza 1: " << nick1 << endl;
        cout << "Nick gracza 2: " << nick2 << endl;
        cout << endl << endl;
        plansza(t);

        if (*runda % 2 == 1) {
            nick = nick1;
            symbol = symb1;
        }
        else {
            nick = nick2;
            symbol = symb2;
        }

        cout << "\n Tura gracza " << nick << " symol: " << symbol << " Twoj ruch : ";
        cin >> r1;
        r = cwiartkanaidx(r1[0], r1[1]);

        system("cls");

        if (strcmp(r1, "m") == 0) {
            break;
            cout << "-----------------------\n\n";
        }

        if ((r >= 1) && (r <= 36) && (t[r] == ' ') && !(t[r] == symb1) && !(t[r] == symb2)) {                //czy pole jest wolne 
            t[r] = symbol;
            (*runda)++;
            nastepny = true;
        }
        else {
            cout << "Wybierz poprawne pole!!!" << endl;
            nastepny = false;
        }

        cout << "nr rundy: " << *runda << endl;

        if (wygrana(t, (*runda % 2 == 0 ? symb1 : symb2)))
            *gra = false;

    }
}


int main()
{
    char p[37], symbol;
    char w = '1';
    bool nastepny;
    bool gra = false;
    int runda = 1;
    int* wsk_runda = &runda;
    bool* wsk_gra = &gra;
    char nick1[15];
    char nick2[15];
    char symb1 = 'O';
    char symb2 = 'X';
    cout << "Podaj nick gracza 1: ";
    cin >> nick1;
    cout << "Podaj nick gracza 2: ";
    cin >> nick2;
    cout << endl << endl;
    cout << "Wybierz 1 zeby zagrac w kolko i krzyzyk" << endl;
    cout << "Wybierz h zeby zobazcyc instrukcje" << endl;
    cout << "Wybierz 'm' zeby odpalic menu (podczas gry)" << endl;
    char menu;
    cin >> menu;
    system("cls");

    //obsluga programu (menu)
    while (1) {
        switch (menu) {
        case 'm':
            cout << "Wybierz 1 zeby kontynuowac gre" << endl;
            cout << "Wybierz h zeby zobaczyc instrukcje" << endl;
            cout << "Wybierz 3 zeby zmienic zetony" << endl;
            cout << "Wybierz 4 zeby zagrac w nowa gre kolko i krzyz" << endl;
            cout << "wybierz 'o' zeby odpalic uzupelniona plansze" << endl;
            cin >> menu;
            break;

        case '1':
            system("cls");
            do
            {
                if (!gra) {
                    cout << "Gra w Kolko i Krzyzyk dla dwoch graczy\n"
                        "======================================\n\n";
                    for (int i = 1; i <= 36; i++) p[i] = ' ';
                    symbol = symb2;
                }
                nastepny = true;
                gra = true;
                ruch(p, symbol, nick1, nick2, nastepny, symb1, symb2, wsk_runda, wsk_gra);

                if (wygrana(p, symb1) || wygrana(p, symb2)) {
                    menu = '0';
                    break;
                }


            } while (gra == false);
            menu = 'm';
            break;


        case 'h':
            system("cls");
            cout << "q,w,a,s to wybor czesci planszy odpowiednio: " << endl;
            cout << "lewej gornej, prawej gornej, lewej dolnej, " << endl;
            cout << "prawej dolnej" << endl;
            cout << "1..9 to wybor pola na czesci planszy jak na klawiaturze numerycznej tj. 1 " << endl;
            cout << "to dolne lewe pole" << endl;
            cout << "wcisnij 'm' podczas gry by odpalic menu" << endl;
            cout << "Napisz 'o' zeby kontynuowac" << endl;

            char klawisz;
            cin >> klawisz;
            system("cls");
            menu = 'm';
            break;

        case '3':
            char nowysymb1;
            char nowysymb2;
            cout << "Wybierz symbol gracza 1: " << endl;
            cin >> nowysymb1;
            cout << "Wybierz symol gracza 2: " << endl;
            cin >> nowysymb2;
            if (nowysymb1 == nowysymb2) {
                cout << "wybierz inne symbole";
                menu = '3';

            }
            else {

                for (int i = 0; i <= 37; i++) {
                    if (p[i] == symb1) {
                        p[i] = nowysymb1;
                    }
                    if (p[i] == symb2) {
                        p[i] = nowysymb2;
                    }
                }
                symb1 = nowysymb1;
                symb2 = nowysymb2;
                menu = 'm';

            }
            break;

        case '4':
            gra = false;
            menu = '1';
            break;

        case 'o':                           //uzupelniona tablica

            p[2] = symb1;
            p[9] = symb1;
            p[11] = symb1;
            p[25] = symb1;
            p[29] = symb1;
            p[32] = symb1;
            p[35] = symb1;
            p[36] = symb1;
            p[5] = symb2;
            p[7] = symb2;
            p[8] = symb2;
            p[10] = symb2;
            p[14] = symb2;
            p[19] = symb2;
            p[20] = symb2;
            p[27] = symb2;

            menu = 'm';
            break;

        }


    }

}