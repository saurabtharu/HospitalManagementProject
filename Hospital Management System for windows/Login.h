#include "secret.h"
#include<unistd.h>

void  askKey(){
    char pass[15];
    int countPass = 5;
    cout << "\n\n\n\n\n\n\n";
    abc:
    cout << "\t\t\t\t\t\t\t\t------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM  " << endl;
    cout << "\t\t\t\t\t\t\t\t------------------------------"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t     LOGIN                  " << endl;
    cout << "\t\t\t\t\t\t\t\t------------------------------" << endl << endl;
    cout << "\t\t\t\t\t\t\t\tSecret Key of  Program: ";
    cin >> pass;
    cin.ignore();

    cout << endl << endl << endl;

    if (strcmp(pass, key) == 0)
    {
        sleep(1);
        system("cls");
        
        cout << "\n\n\n\n\n\n\n";
        cout << "\n\t\t\t\t\t\t\t\tThe access is granted";
        cout << "\n\n\t\t\t\t\t\t\t  Press any key to continue . . . ";
        cin.get();
        sleep(1);
    }
    else{
        while (strcmp(pass,key) != 0 && countPass !=0 )
        {
            system("cls");
            sleep(1);
            cout << "\n\n\n\n\n\n\n";
            cout << "\n\t\t\t\t\t\t\t\tThe invalid password!!\n";
            countPass--;
            cout << "\t\t\t\t\t\t\t\tYou have " << countPass << " chance to guess now." << endl << endl;
            
            if (countPass > 0){
                // sleep(1);
                goto abc;
            }
            else{
              cout << "\t\t\t\t\t\t       You are kicked from the program due to over trying\n";
            }
        }
        exit(0);
    }

    cout << endl << endl;
}
