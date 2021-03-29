#include "secret.h"

void  keyCheck(){
    char pass[15];
    int countPass = 5;
    abc:
    cout << "\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM" << endl;
    cout << "\t\t\t\t\t\t\t\t------------------------------"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t     LOGIN                  " << endl;
    cout << "\t\t\t\t\t\t\t\t------------------------------" << endl << endl;
    cout << "\t\t\t\t\t\t\t\tSecret Key of  Program: ";
    cin >> pass;  
    
    if(strcmp(pass,key) == 0){
      cout << "\n\t\t\t\t\t\t\t\tThe access is granted";
      cout << "\n\nPress any key to continue:";
    //   system("clear");
    }
    else{
        while (strcmp(pass,key) != 0 && countPass !=0 )
        {
            system("clear");
            cout << "\n\t\t\t\t\t\t\t\tThe invalid password!!\n";
            countPass--;
            cout << "\t\t\t\t\t\t\t\tYou have " << countPass << " chance to guess now." << endl
                << endl;
            if(countPass>0)
                goto abc;
            else{
              cout << "\t\t\t\t\t\t       You are kicked from the program due to over trying\n";
            }
        }
        exit(0);
    }

    cout << endl << endl;
}
