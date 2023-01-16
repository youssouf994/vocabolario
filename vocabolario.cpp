// vocabolario.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

/******************************************************************************
VOCABOLARIO CON SOLE PAROLE IN CUI è POSSIBILE AGGIUNGERE LE DEFINIZIONI
*******************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#define dim 116878


using namespace std;

struct vocabolario
{
    string parola;
    string definizione;
};//dichiarazione della struct da usare nella ram

vocabolario voca[116878];

void scrivi()
{
    int c = 0;

    ofstream salva("parole.txt", ios::out | ios::trunc);
    for (c = 0; c < dim; c++)
    {
        salva << voca[c].parola << endl;
        salva << voca[c].definizione << endl;
        if (c == dim-1)
        {
            salva << voca[c].parola << endl;
            salva << voca[c].definizione;
        }
    }
    salva.close();
}

void ordina_file()
{
    int d;
    string appoggio;

    d = 0;
    ifstream leggi("parole.txt", ios::in);//apro il file in lettura
    while (getline(leggi, appoggio))//finchè posso fare la cin
    {
        voca[d].parola = appoggio;//riempo struct parola
        voca[d].definizione = "Nessuna definizione";
        d++;
    }
    leggi.close();

    ofstream write("parole.txt", ios::out | ios::trunc);
    for (d = 0; d < dim; d++)
    {
        write << voca[d].parola << endl;
        write << voca[d].definizione << endl;

        if (d == dim-1)
        {
            write << voca[d].parola << endl;
            write << voca[d].definizione;
        }
    }
    write.close();
}

void fill_ram()//funzione per riempire la struct precedentemente dichiarata
{

    int a = 0, b = 0;
    string appoggio;

    ifstream fill("parole.txt", ios::in);//apro il file in lettura
    while (getline(fill, appoggio))//finchè posso fare la cin
    {
        voca[a].parola = appoggio;//riempo struct parola
        voca[a].definizione = appoggio;
        a++;
    }
    fill.close();

    scrivi();
}

int main();

int return_main()//funzione che riporta l'utente al main(inutile)
{
    int interno;

    do
    {
        cout << endl << endl;
        cout << "0.Menù principale" << endl;
        cin >> interno;

        switch (interno)
        {

        case 0:
            main();
            break;

        default:
            char err = 7;
            cout << err;
            break;
        }
    } while (interno != 0);

    return interno;
}

void scorrimento()//funzione che apre l'intero vocabolario a monitor
{
    int i = 0;

    for (i = 0; i < dim; i++)
    {
        cout << voca[i].parola << endl;
        cout << voca[i].definizione << endl;
    }

}

void ricerca()
{
    int x = 0, y = dim - 1, i, pos = -1;
    string temp, searched;

    cout << "Inserire la parola da cercare" << endl;
    cin >> searched;

    do
    {
        i = (x + y) / 2;
        if (voca[i].parola == searched)
        {
            pos = i;
        }

        else if (voca[i].parola < searched)
        {
            x = i + 1;
        }

        else if (voca[i].parola > searched)
        {
            y = i - 1;
        }

    } while (x <= y && pos == -1);

    cout << "La parola cercata è: " << voca[i].parola << endl;
    cout << "La definizione presente in archivio è: " << voca[i].definizione << endl;

}

void inserisci_definizione()
{
    string word_insert, definition;
    int i;

    cout << "Inserire la parola in cui aggiungere la definizione" << endl;
    cin >> word_insert;//parola scelta dall'utente

    for (i = 0; i < dim; i++)
    {
        if (word_insert == voca[i].parola)//quando la parola è presente nella struct
        {
            cout << "Inserire definizione per " << voca[i].parola << endl;
            cout << " :" << endl;
            cin.ignore();
            getline(cin, definition);//l'utente ne inserisce la definizione
            voca[i].definizione = definition;//la definizione finiscce nella struct
        }
    }

    if ((i == dim) && (word_insert != voca[i].parola))//se l'indice è al massimo e la parola inserita non è stata trovata
    {
        cout << "Parola non presente nell'elenco" << endl;//errore
    }

    ofstream upda_te("parole.txt", ios::out | ios::trunc);//apri file in scrittura

    for (i = 0; i < dim; i++)//inserisci al suo interno tutta la struct con le modifiche
    {
        upda_te << voca[i].parola << endl;
        upda_te << voca[i].definizione << endl;

        if (i == dim-1)
        {
            upda_te << voca[i].parola << endl;
            upda_te << voca[i].definizione;
        }
    }
    upda_te.close();

}

void modifica()
{
    char scelta;
    string da_modificare, modificata;
    int j;

    cout << "vuoi modificare una parola o una definizione? p:parola - d:definizione" << endl;//cosa modifica l'utente?
    cin >> scelta;

    switch (scelta)//scelta utente
    {

    case 'd':
    case 'D':
        cout << "Definizione di quale parola?" << endl;
        cin >> da_modificare;//identifico la parola a cui dare la modifica

        for (j = 0; j < dim; j++)
        {
            if (voca[j].parola == da_modificare)//quajndo ho trovato la parola
            {
                cout << "vecchia definizione di: " << voca[j].parola << endl;
                cout << voca[j].definizione;//faccio vedere all'utente i dati vecchi
                Sleep(1500);
                cout << "inserire nuova definizione di: " << voca[j].parola << endl;
                cin.ignore();//utente inserisce dati nuovi
                getline(cin, modificata);
                voca[j].definizione = modificata;
                cout << voca[j].parola << endl << voca[j].definizione;

                Sleep(3000);
                main();
            }
        }

        break;

    case 'p':
    case 'P'://uguale al case d ma per le parole
        cout << "Parola da modificare?" << endl;
        cin >> da_modificare;

        for (j = 0; j < dim; j++)
        {
            if (voca[j].parola == da_modificare)
            {
                cout << "modifica: " << voca[j].parola << endl;
                Sleep(1500);
                cout << "inserire nuova parola: " << endl;
                cin >> modificata;
                voca[j].parola = modificata;
                cout << voca[j].parola << endl << voca[j].definizione;

                Sleep(3000);
                main();
            }
        }

        break;

    default:
        char err = 7;
        cout << err;
        cout << err << "Scelta non consentita" << endl;
        break;
    }
}


int main()
{
    int scelta;
    char stop;
    string parola;

    do
    {
        //ordina_file();
        fill_ram();
        system("CLS");       
        cout << endl;
        cout << "1.Scorri la lista" << endl;
        cout << "2.Cerca parola" << endl;
        cout << "3.Inserisci definizione" << endl;
        cout << "4.Modifica" << endl;
        cout << "5.Aggiorna file vocabolario" << endl;
        cin >> scelta;

        switch (scelta)
        {
        case 1:
            
            scorrimento();
            cout << "Tornare al menù principale? s/n" << endl;
            cin >> stop;

            switch (stop)
            {
            case 's':
            case 'S':
                break;

            case 'n':
            case 'N':
                while ((stop != 'n') | (stop != 'N'))
                {
                    cout << "Menù principale (N)" << endl;
                    cin >> stop;
                    Sleep(600000);
                }
                break;

            default:
                cout << "Scelta errata" << endl;
                break;

            }

            break;

        case 2:
            ricerca();
            break;

        case 3:
            inserisci_definizione();
            //rivi();
            break;

        case 4:
            modifica();
            scrivi();
            break;

        case 5:
            ordina_file();
            break;

        default:
            cout << "Scelta errata" << endl;
            break;
        }

    } while (scelta != 0);


    return 0;
}

// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug

// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln
