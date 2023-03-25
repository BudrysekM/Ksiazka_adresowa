#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

struct Adresat
{
    int id = 0;
    string imie, nazwisko, numer_telefonu, adres_email, adres_zamieszkania;

};

string wczytajLinie()
{
    string wejscie;
    cin.sync();
    getline(cin, wejscie);
    return wejscie;
}

int pobierzOstatniID ()
{

    int ostatniID= 0;

    string ostatniaLinia = "";
    string daneBezZnakuPionowejLini = "";
    fstream plik;

    plik.open("ksiazki.txt", ios::in);

    if (plik.good()) {
        while (getline(plik, daneBezZnakuPionowejLini)) {
            int ID = daneBezZnakuPionowejLini.find('|');
            ostatniaLinia = daneBezZnakuPionowejLini.substr(0, ID);
            ostatniID = atoi(ostatniaLinia.c_str());
        }
    }
    plik.close();
    return ostatniID;
}

void dodanieAdresataDoPliku (vector <Adresat> &adresaci )
{
    fstream plik;

    plik.open("ksiazki.txt", ios::out );

    if (plik.good())
    {
        for (unsigned int i = 0; i < adresaci.size(); i++)
        {
            plik << adresaci[i].id << "|";
            plik << adresaci[i].imie << "|";
            plik << adresaci[i].nazwisko << "|";
            plik << adresaci[i].numer_telefonu <<"|";
            plik << adresaci[i].adres_email << "|";
            plik << adresaci[i].adres_zamieszkania << "|" <<endl;
        }
    }
    plik.close();
}

void dodanieAdresata (vector <Adresat> &adresaci )
{
    Adresat nowaOsoba;
    cout << "Podaj imie: ";
    nowaOsoba.imie = wczytajLinie();
    cout << "Podaj nazwisko: ";
    nowaOsoba.nazwisko = wczytajLinie();
    cout << "Podaj numer telefonu: ";
    nowaOsoba.numer_telefonu = wczytajLinie();
    cout << "Podaj adres e-mail: ";
    nowaOsoba.adres_email = wczytajLinie();
    cout << "Podaj adres zamieszkania: ";
    nowaOsoba.adres_zamieszkania = wczytajLinie();
    nowaOsoba.id = pobierzOstatniID() + 1;
    adresaci.push_back(nowaOsoba);
    cout << "Dodano adresata" << endl;

    Sleep(1000);

    dodanieAdresataDoPliku(adresaci);
}

void wyszukajPoImieniu (vector <Adresat> &adresaci)
{
    string imie;
    cout <<"Podaj imie po ktorym chcesz wyszukac: ";
    cin >> imie;

    for (unsigned int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].imie == imie)
        {
            cout << "ID:                    " << adresaci[i].id << "." << endl;
            cout << "Imie:                  " << adresaci[i].imie << endl;
            cout << "Nazwisko:              " << adresaci[i].nazwisko << endl;
            cout << "Numer telefonu:        " << adresaci[i].numer_telefonu << endl;
            cout << "Adres email:           " << adresaci[i].adres_email << endl;
            cout << "Adres zamieszkania:    " << adresaci[i].adres_zamieszkania << endl;
            cout << endl;
        }
    }
}

void wyszukajPoNazwisku (vector <Adresat> &adresaci)
{
    string nazwisko;
    cout <<"Podaj nazwisko po ktorym chcesz wyszukac: ";
    cin >> nazwisko;

    for (unsigned int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].nazwisko == nazwisko)
        {
            cout << "ID:                    " << adresaci[i].id << "." << endl;
            cout << "Imie:                  " << adresaci[i].imie << endl;
            cout << "Nazwisko:              " << adresaci[i].nazwisko << endl;
            cout << "Numer telefonu:        " << adresaci[i].numer_telefonu << endl;
            cout << "Adres email:           " << adresaci[i].adres_email << endl;
            cout << "Adres zamieszkania:    " << adresaci[i].adres_zamieszkania << endl;
            cout << endl;
        }
    }
}

void wyswietlWszystkichAdresatowZKsiazkiAdresowej (vector <Adresat> adresaci)
{

    for (unsigned int i = 0; i < adresaci.size(); i++)
    {
        cout << "ID:                    " << adresaci[i].id << "." << endl;
        cout << "Imie:                  " << adresaci[i].imie << endl;
        cout << "Nazwisko:              " << adresaci[i].nazwisko << endl;
        cout << "Numer telefonu:        " << adresaci[i].numer_telefonu << endl;
        cout << "Adres email:           " << adresaci[i].adres_email << endl;
        cout << "Adres zamieszkania:    " << adresaci[i].adres_zamieszkania << endl;
        cout << endl;
    }
}

void wyswietlAdresatowZapisanychWPliku (vector <Adresat> &adresaci)
{
    Adresat poszczegolnyAdresat;

    string daneOsoby{};
    fstream plik;
    plik.open("ksiazki.txt", ios::in);

    if (plik.good())
    {
        while(getline(plik,daneOsoby))
        {
            string daneIndywidualneOsoby{};
            int numerOsoby = 1;
            for (size_t i{}; i < daneOsoby.length(); ++i)
            {
                if (daneOsoby[i] != '|')
                {
                    daneIndywidualneOsoby += daneOsoby[i];
                }
                else
                {
                    switch (numerOsoby)
                    {
                    case 1:
                        poszczegolnyAdresat.id = stoi(daneIndywidualneOsoby);
                        break;
                    case 2:
                        poszczegolnyAdresat.imie = daneIndywidualneOsoby;
                        break;
                    case 3:
                        poszczegolnyAdresat.nazwisko = daneIndywidualneOsoby;
                        break;
                    case 4:
                        poszczegolnyAdresat.numer_telefonu = daneIndywidualneOsoby;
                        break;
                    case 5:
                        poszczegolnyAdresat.adres_email = daneIndywidualneOsoby;
                        break;
                    case 6:
                        poszczegolnyAdresat.adres_zamieszkania = daneIndywidualneOsoby;
                        break;
                    }
                    daneIndywidualneOsoby = "";
                    numerOsoby++;
                }
            }
            adresaci.push_back(poszczegolnyAdresat);
        }
    }
    plik.close();
}

void usunAdresata (vector <Adresat> &adresaci)
{
    int idAdresataDoUsuniecia;
    char wybor;
    cout << "Podaj id adresata do usuniecia" << endl;
    cin >> idAdresataDoUsuniecia;

    for (unsigned int i = 0; i < adresaci.size(); i++ )
    {
        if (idAdresataDoUsuniecia == adresaci[i].id )
        {
            cout << "Usuwasz ";
            cout << "ID:                    " << adresaci[i].id << endl;
            cout << "Imie:                  " << adresaci[i].imie << endl;
            cout << "Nazwisko:              " << adresaci[i].nazwisko << endl;
            cout << "Numer telefonu:        " << adresaci[i].numer_telefonu << endl;
            cout << "Adres email:           " << adresaci[i].adres_email << endl;
            cout << "Adres zamieszkania:    " << adresaci[i].adres_zamieszkania << endl;

            cout << "ze swojej listy znajomych. ";
            cout << endl;
            cout << "Czy chcesz usunac tego adresata? Jezeli tak wcisnij <t>   ";
            cin >> wybor;
            if (wybor == 't')
            {
                adresaci.erase(adresaci.begin() + i);
                cout << "Usunieto adresata" << endl;
            }
            else
                cout << "Bledne potwierdzenie. Nie usunieto adresata" << endl;
        }
        else
            cout << "Brak adresta o tym ID w ksiazce adresowej" << endl;
    }
    dodanieAdresataDoPliku(adresaci);
}

void edytujAdresata(vector <Adresat> &adresaci)
{
    system("cls");
    int idAdresataDoEdycji;
    char wybor;

    string imie, nazwisko, numer_telefonu, adres_email, adres_zamieszkania;

    cout << ">>>>Edycja adresata<<<" << endl;
    cout << ">>>>Podaj Id adresata do edycji<<<" << endl;
    cin >> idAdresataDoEdycji;

    cout << ">>>>Dane do edycji<<<" << endl;
    cout << "1. Imie" << endl;
    cout << "2. Nazwisko" << endl;
    cout << "3. Numer telefonu" << endl;
    cout << "4. Adres mail" << endl;
    cout << "5. Adres zamieszkania" << endl;
    cout << "Twoj wybor: " << endl;
    cin >> wybor;


    switch (wybor)
    {
    case '1':
        cout << "Podaj nowe imie" << endl;
        cin >> imie;
        for (unsigned int i = 0; i < adresaci.size(); i++)
        {
            if(adresaci[i].id == idAdresataDoEdycji )
                adresaci[i].imie = imie;
        }
        break;
    case '2':
        cout << "Podaj nowe nazwisko" << endl;
        cin >> nazwisko;
        for (unsigned int i = 0; i < adresaci.size(); i++)
        {
            if(adresaci[i].id == idAdresataDoEdycji )
                adresaci[i].nazwisko = nazwisko;
        }
        break;
    case '3':
        cout << "Podaj nowy telefon" << endl;
        cin >> numer_telefonu;
        for (unsigned int i = 0; i < adresaci.size(); i++)
        {
            if(adresaci[i].id == idAdresataDoEdycji )
                adresaci[i].numer_telefonu = numer_telefonu;
        }
        break;
    case '4':
        cout << "Podaj nowy adres email" << endl;
        cin >> adres_email;
        for (unsigned int i = 0; i < adresaci.size(); i++)
        {
            if(adresaci[i].id == idAdresataDoEdycji )
                adresaci[i].adres_email = adres_email;
        }
        break;
    case '5':
        cout << "Podaj nowy adres zamieszkania" << endl;
        cin >> adres_zamieszkania;
        for (unsigned int i = 0; i < adresaci.size(); i++)
        {
            if(adresaci[i].id == idAdresataDoEdycji )
                adresaci[i].adres_zamieszkania = adres_zamieszkania;
        }
        break;

    }
    dodanieAdresataDoPliku(adresaci);
}

bool czyIstniejePlik (const string& fileName)
{
    fstream plik;
    plik.open(fileName.c_str(), ios::in);
    if ( plik.is_open() )
    {
        plik.close();
        return true;
    }
    plik.close();
    return false;
}

int main()
{
    char wybor;
    vector <Adresat> adresaci;


    wyswietlAdresatowZapisanychWPliku(adresaci);

    while(true)
    {
        system("cls");
        cout << ">>>>Ksiazka adresowa<<<" << endl;
        cout << "1. Dodaj adresata" << endl;
        cout << "2. Wyszkuaj po imieniu" << endl;
        cout << "3. Wyszukaj po nazwisku" << endl;
        cout << "4. Wyswietl wszystkich adresatowe" << endl;
        cout << "5. Usun adresata" << endl;
        cout << "6. Modyfikuj adresata" << endl;
        cout << "7. Zakoncz program" << endl;
        cout << "Twoj wybor: " << endl;
        cin >> wybor;


        switch(wybor)
        {
        case '1':
            dodanieAdresata(adresaci);
            system("pause");
            break;
        case '2':
            wyszukajPoImieniu(adresaci);
            system("pause");
            break;
        case '3':
            wyszukajPoNazwisku(adresaci);
            system("pause");
            break;
        case '4':
            wyswietlWszystkichAdresatowZKsiazkiAdresowej(adresaci );
            system("pause");
            break;
        case '5':
            usunAdresata(adresaci);
            system("pause");
            break;
        case '6':
            edytujAdresata(adresaci );
            system("pause");
            break;
        case '7':
            cout << "Koniec programu !!" << endl;
            exit(0);
            break;
        }
    }
    return 0;
}
