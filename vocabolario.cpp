// vocabolario.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

/******************************************************************************
VOCABOLARIO CON SOLE PAROLE IN CUI è POSSIBILE AGGIUNGERE LE DEFINIZIONI
*******************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#define dim 116878


using namespace std;

struct vocabolario
{
    string parola;
    string definizione;
};

vocabolario voca[116878];

void fill_ram()
{
    int i = 0;
    string appoggio;
    string stop=" *";

    ifstream fill("parole.txt", ios::in);
    while (getline(fill, appoggio))
    {
        voca[i].parola = appoggio;
        i++;
    }
    fill.close();
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
};

void scorrimento()//funzione che apre l'intero vocabolario a monitor
{
    int interno, i=0;
  
    for (i = 0; i < dim; i++)
    {
        cout << voca[i].parola << endl;
        cout << voca[i].definizione << endl;
    }
    

    do
    {
        interno = return_main();

    } while (interno != 0);

};

string ricerca()//funzione per la ricerca di una parola
{
    string searched, storage;
    int count;

    ofstream ricerca("deep_search.txt", ios::out | ios::trunc);//apro un file vuoto per filtrare le parole
    ricerca.close();


    do
    {
        count = 0;//numero per l'utente
        cout << "Inserire la parola cercata" << endl;
        cin >> searched;//parola da cercare

        cout << "Le parole simili alla tua ricerca sono:" << endl;
        ifstream voci("parole.txt", ios::in);
        while (getline(voci, storage))//finchè è aperto il buffer di lettura
        {
            voci >> storage;//rovescia il database nella ram

            if ((storage.find(searched) != string::npos))//se nella stringa ram c'è una porzione di parola cercata
            {
                cout << count + 1 << "." << storage << endl;//mostra tutte le parole numerate
                count++;

                ofstream deep("deep_search.txt", ios::out | ios::app);//apri il file svuotato precedentemente
                deep << storage << endl;//e metti le parole filtrate
                deep.close();  
            }
        }
        voci.close();

        ifstream deep2("deep_search.txt", ios::in);
        while (getline(deep2, storage))
        {
            deep2 >> storage;
            if (storage == searched)
            {
                return storage;
            }
        }

        /*if (count > 1)
        {
            cout << "Inserire il numero della parola cercata" << endl;
            cin >> scelta;
            
            i = 1;
            ifstream deep2("deep_search.txt", ios::in);
            while(i != scelta)
            {
                while (getchar() != '\n')
                {
                    deep2 >> storage_clean;
                }

                if (i = scelta)
                {
                    return storage_clean;
                }
                i++;
            }
            deep2.close();
        }*/

        if (count == 0)
        {
            char err = 7;
            cout << err;
            cout << err << "La parola cercata non e' presente nell'archivio prova ad invertire il genere " << endl;
        }


    } while (count != 0);

};

void inserisci_definizione()
{
    string word_insert, definition;
    int i;

    cout << "Inserire la parola in cui aggiungere la definizione" << endl;
    cin >> word_insert;

    for (i = 0; i <= dim; i++)
    {
        if (word_insert == voca[i].parola)
        {
            cout << "Inserire definizione per " << voca[i].parola << endl;
            cout << " :" << endl;
            cin.ignore();
            getline(cin, definition);
            voca[i].definizione = definition;
        }
    }

    if ((i == dim) && (word_insert != voca[i].parola))
    {
        cout << "Parola non presente nell'elenco" << endl;
    }

    ofstream upda_te("parole.txt", ios::out, ios::trunc);//MODIFICARE NOME FILE

    for (i = 0; i < dim; i++)
    {
        upda_te << voca[i].parola<<"\t";
        upda_te << voca[i].definizione  << endl;
    }
    upda_te.close();

    fill_ram();

    main();
}

void modifica(string da_modificare)
{

}


int main()
{
    int scelta;
    string parola;

    fill_ram();

    do
    {
        cout << "1.Scorri la lista" << endl;
        cout << "2.Cerca parola" << endl;
        cout << "3.Inserisci definizione" << endl;
        cout << "4.Modifica" << endl;
        cin >> scelta;

        switch (scelta)
        {
            case 1:
                scorrimento();
                break;

            case 2:
                parola = ricerca();
                cout << endl << endl;
                cout <<"La parola cercata e': "<< parola << endl;
                break;

            case 3:
                inserisci_definizione();
                break;

            case 4:

                break;

            default:
                cout << "Scelta errata" << endl;
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
