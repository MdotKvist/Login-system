#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool LoggingIn() {  //Kontrollere om status skal bibeholde true værdien
    string brugernavn, password, user, pass;

    cout << "Indtast brugernavn: "; cin >> brugernavn;
    cout << "Indtast password: "; cin >> password;

    ifstream read(brugernavn + ".txt");  //åben Filen som tideligere er oprettet
    getline(read, user);                 //Læs brugernavn
    getline(read, pass);                 //læs password

    if (user == brugernavn && pass == password) { //Hvis brugernavn og password matcher
        return true;  // ændre "loggingin"
    }
    else {
        cout << "Fejl i Brugernavn eller adgangskode, Prøv veligst igen!";
        return false; // ændre "loggingin"
    }
}

int main()
{
    int valget;
                    //træf et valg
    cout << "Dit valg: \n1) Registrer\n2) Login\nDit valg:";
                    //input Hvad man vælger
    cin >> valget;
                    //hvis du valgte registrer Opretter et brugernavn og adgangskode
    if (valget == 1) {

        string brugernavn, password;
            
        cout << "Indtast dit nye brugernavn:"; cin >> brugernavn;
        cout << "Indtast dit nye password:"; cin >> password;

        ofstream file;
        file.open(brugernavn + ".txt"); //opret/åben fil
        file << brugernavn << endl << password; //Indtast oplysninger
        file.close();                           //luk filen

        main();                                 //start forfra
    }
    else if (valget == 2) {         //hvis du har valgt at logge ind

        bool status = LoggingIn(); //status er sat til "true"
        if (!status) {              // 
            cout << "Fejl i Brugernavn eller password, pr\x9Bv venligst igen \n";
            system("PAUSE");
            return 0;
        }
        else {
            system("PAUSE");
            return 1;
        }
    }
    

}