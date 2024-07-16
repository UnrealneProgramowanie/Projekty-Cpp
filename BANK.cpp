#include <iostream>
#include <cctype>
using namespace std;
class Konto 
{
public:
    int getStan()
    {
        return stan;
    }
    int wyplac(int x) {
        if (x <= stan) {
            stan -= x;
            return x;
        }
        else 
        {
            return 0;
        }
    }
    

    void wplac(int x) {
        if (x > 0 && stan + x != numeric_limits<long>::max())
            stan += x;
    }
    bool getMenu() {
        return menu;
    }
    void doMenu() {
        cout << "Wrocic do menu? (y/n)" << endl;
        string doMenu;
        cin >> doMenu;

        if (doMenu == "y") {
            system("cls");
        }
        else if (doMenu == "n") {
            menu = false;
        }
        else {
            cout << "Error!" << endl;
        }
    }

private: 
    long stan = 1000;
    bool menu = true;




};
int main()
{
    Konto konto;
    
    ;
    while (konto.getMenu() == true)
    {
        string odp;
        cout << "----------Bank-----------" << endl;
        cout << " ---Co chcesz zrobic?---" << endl;
        cout << "   Menu - menu" << endl;
        cout << "   Pokaz stan konta - stan" << endl;
        cout << "   Wplac pieniadze - wplac" << endl;
        cout << "   Wyplac pieniadze - wyplac" << endl;
        cout << "   Wyjdz - wyjdz" << endl;
        cin >> odp;
        if (odp == "stan") {
            cout << "Stan Konta: " << konto.getStan() << "zl" << endl;
            konto.doMenu();
        }
        else if (odp == "wplac") {
            cout << "Ile chcesz wplacic?" << endl;
            cout << "Wplata: ";
            int wplata;
            cin >> wplata;
            if (wplata > 0 && konto.getStan() + wplata != numeric_limits<long>::max()) {
                konto.wplac(wplata);
                cout << "Wplacono " << wplata << "zl!" << endl;
            }
            else {
                cout << "Wpisana wartosc jest zbyt duza lub niepoprawna!" << endl;
            }
            konto.doMenu();
        }
        else if (odp == "wyplac") {
            int wyplata;
            cout << "Ile chcesz wyplacic?" << endl;
            cout << "Wyplata: ";
            cin >> wyplata;
            if (wyplata < konto.getStan()) {
                konto.wyplac(wyplata);
                cout << "Wyplacono " << wyplata << "zl!" << endl;
            }
            else
                cout << "Wpisana wartosc jest zbyt duza lub niepoprawna!";
            
            konto.doMenu();
        }
        else if (odp == "wyjdz") {
            break;
        }
        else {
            cout << "Error!" << endl;
            system("cls");
            konto.doMenu();
        }

    }


    
}


