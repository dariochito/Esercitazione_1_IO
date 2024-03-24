#include <iostream>
#include <fstream>
#include <iomanip>

//Creo la funzione che mappa i punti dell'intervallo [1,5] nell'intervallo [-1,2]

unsigned int a = 1;
unsigned int b = 5;
int c = -1;
unsigned int d = 2;

/**La seguente funzione calcola la percentuale di quanto x sia
 * posizionato rispetto all'intervallo [a,b] e poi la usa per
 * mappare il valore nell'intervallo [c,d]. **/

double changeInterval(double x)
{
    return c + ((x-a)/(b-a)*(d-c));
}

int main()
{
    std::string FileName = "data.csv";
    std::ifstream ifstr(FileName); //Apro il file in modalità lettura.

    if(ifstr.fail()) //Controllo se il file che voglio aprire esiste, altrimenti lancio un messaggio di errore.
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }


    std::ofstream outputFile("results.csv"); //Apro il file in modalità scrittura.
    std::string  header;                     /**Inserisco
    outputFile << header << "# N mean\n";       il titolo del file**/

    double val = 0;                //Inizializzo le variabili che andrò ad usare nel ciclo while,in particolare:
    unsigned int i = 1;            //val rappresenta le righe del file;
    double sumValues = 0;          //i rappresenta l'indice di riga;
    double mapped_x = 0;           //mapped_x rappresenta il valore mappato nel nuovo intervallo.

    while(ifstr >> val)
    {
     mapped_x = changeInterval(val);
     sumValues += mapped_x;
     double mean = sumValues/i;
     outputFile << std::fixed << std::setprecision(16) << std::scientific << i << " " << mean << "\n" ;
     i++;
    }
    outputFile.close();

/**Il programma non esce dal ciclo while finchè non legge tutte le righe. Inoltre funziona nel seguente modo:
 * partendo da i=1,legge l'i-esima riga,aggiunge il suo valore nella variabile sumValues, calcola la media
 * dei primi i-valori e infine stampa quest'ultima nel file di output.**/

    return 0;
}





