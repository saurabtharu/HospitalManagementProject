
/**************************************************
 * 
 *************************************************/
/**************************************************
 * 
 *************************************************/
/**************************************************
 * 
 *************************************************/
/**************************************************
 * 
 *************************************************/
/**************************************************
 * 
 *************************************************/
/**************************************************
 * 
 *************************************************/
/**************************************************
 * 
 *************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Login.h"

char time101[80];

/**************************************************
 * structure for doctor's detail
 *************************************************/
typedef struct
{
    int id, age;
    char name[50], experience[50], qualification[50], specialization[50], availablTime[50];
} doctorDetail;

/**************************************************
 * structure for patient's detail
 *************************************************/
typedef struct
{
    int id, age;
    long double contactNo;
    char fileName[50], name[50], address[50], bloodGroup[50], disease[50], syptoms[50], admitDate[50], roomNo[50], roomCharge[50], medCharge[50];
} patientDetail;

//store time in character variable
void TimeDisplay()
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(time101, sizeof(time101), "%d-%m-%Y %H:%M:%S", timeinfo);
}
/**************************************************
 * class for Hospital ( parent class)
 *************************************************/
class Hospital
{
public:
    int number;
};

/**************************************************
 * class for Doctor ( child class of Hospital)
 *************************************************/
class Doctor : public Hospital
{
public:
    doctorDetail d1[20];
    int docNo;
    int indexOfDoctors = 0;
    void addDoctorInfo();
    void displayDoctorInfo();
    void detailOfAllDoctor();
};

void Doctor::addDoctorInfo()
{
    cout << "How many new doctors??  ";
    cin >> docNo;

    if (docNo == 0)
    {
        return;
    }
    else
    {

        cout << "\t\t\t\tTime: " << time101 << endl;
        cout << "\t\t\tEnter the doctor's information:\n";

        for (int i = 0; i < docNo; i++)
        {
            cout << "\t\t\tEnter Doctor's ID                                      : ";
            cin >> d1[indexOfDoctors].id;
            fgetc(stdin);

            cout << "\t\t\tEnter Doctor's name                                    : ";
            cin.getline(d1[indexOfDoctors].name, 40);

            cout << "\t\t\tEnter Doctor's age                                     : ";
            cin >> d1[indexOfDoctors].age;
            fgetc(stdin);

            cout << "\t\t\tEnter Doctor's Qualification                           : ";
            cin.getline(d1[indexOfDoctors].qualification, 40);

            cout << "\t\t\tEnter Doctor's Specialization                          : ";
            cin.getline(d1[indexOfDoctors].specialization, 40);

            cout << "\t\t\tEnter Doctor's experience in year                      : ";
            cin.getline(d1[indexOfDoctors].experience, 40);

            cout << "\t\t\tEnter the available time for doctor (FORMAT: HH-MM)    : ";
            cin >> d1[indexOfDoctors].availablTime;
            indexOfDoctors++;

            cout << endl;
            cout << "The information of " << i + 1 << " doctor is added into database.\n";
            cout << endl
                 << endl;
            if (docNo > 1)
            {
                cout << "Fill the information of "
                     << " doctor " << i + 2 << endl;
            }
        }
    }
}

void Doctor::displayDoctorInfo()
{
    int inpId;
    int i = 0;

    if (indexOfDoctors == 0)
    {
        cout << "\n\t\t\tOOPS!!No record to display\n";
    }
    else
    {
        cout << "\t\t\t\t\tEnter the doctor's id: ";
        cin >> inpId;
        int flag = 0;
        for (i = 0; i < indexOfDoctors; i++)
        {
            if (d1[i].id == inpId)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {

            cout << "\t\t\t\t\tInformation of Docotor " << endl;
            cout << "\t\t\t\t\t-" << setfill('-') << setw(45) << "-" << endl;
            // cout << "" << time101 << endl;
            cout << "\t\t\t\t\t1 >> Doctor's Id                   : " << d1[i].id << endl;
            cout << "\t\t\t\t\t2 >> Doctor's Name                 : " << d1[i].name << endl;
            cout << "\t\t\t\t\t3 >> Doctor's Age                  : " << d1[i].age << endl;
            cout << "\t\t\t\t\t4 >> Doctor's Qualification        : " << d1[i].qualification << endl;
            cout << "\t\t\t\t\t5 >> Doctor's Specilization        : " << d1[i].specialization << endl;
            cout << "\t\t\t\t\t6 >> Doctor's Experience           : " << d1[i].experience << endl;
            cout << "\t\t\t\t\t7 >> Doctor's Time of available    : " << d1[i].availablTime << endl;
            cout << endl
                 << endl;
        }
        else
        {
            cout << " \n\n\t\t\t\t No such ID in database " << endl;
            cout << " \n\t\t\t\tPress Any KEY To choose another Option.... ";
        }
    }
    cout << endl;
}

void Doctor::detailOfAllDoctor()
{

    if (indexOfDoctors == 0)
    {
        cout << "\n\t\t\tOOPS!!No record to display\n";
    }
    else
    {

        cout << "\t\t\t\t**************************************************************************\n";
        cout << "\t\t\t\t*                 DETAILS OF ALL THE DOCTORS IN THE HOSPITAL              \n";
        cout << "\t\t\t\t**************************************************************************\n";
        cout << "\t\t\t\tID\t"
             << "Name \t\t"
             << "Specialization\t\t\t"
             << "   Available At" << endl;
        cout << "\t\t\t\t\t\t\t(Form(HH) - TO(HH)" << endl;
        cout << "\t\t\t\t**************************************************************************\n";

        int i;
        for (i = 0; i < indexOfDoctors; i++)
        {
            cout << "\t\t\t\t" << d1[i].id << "\t" << d1[i].name << "\t\t" << d1[i].specialization << "\t\t\t";
            cout << d1[i].availablTime << endl;
            cout << "\t\t\t\t--------------------------------------------------------------------------\n";
        }
        cout << " \n\t\t\tPress Any Button To choose another Option.... ";
    }
    // getwchar();
    cin.ignore();
    cout << endl;
}

/**************************************************
 * class for Patient  ( child class of Hospital ) 
 *************************************************/
class Patient : public Hospital
{
public:
    void addPatientInfo();
    void displayPatientInfo();
    void detailOfAllPatients();
    void genPatientReport();
    void genPatientBill();
};

/********************************
 * start of main function
 ********************************/
int main()
{

    int n1, n2;

    int repeat = 1;
    int choice1, choice2, choice3, choice4;
    Doctor d;
    Patient p;

    keyCheck();
    cin.get();
label1:
    system("clear");
    cout << "\t\t\t\t\t\t  ******< HOSPITAL MANAGEMENT SYSTEM >******" << endl;
    cout << "\t\t\t\t\t    =" << setfill('=') << setw(50) << "=" << endl
         << endl;
    cout << "\t\t\t\t\t\t\t1. MENU" << endl
         << endl;
    cout << "\t\t\t\t\t\t\t2. EXIT" << endl
         << endl;

    cout << "\t\t\t\t\t\t    Enter your choice: ";
    cin >> choice1;

    switch (choice1)
    {

    case 1:
        system("clear");
    label2:
        cout << "\t\t\t\t\t\t\tWHO ARE YOU??  " << endl;
        cout << "\t\t\t\t\t\t=" << setfill('=') << setw(26) << "=" << endl
             << endl;
        cout << "\t\t\t\t\t\t\t1. DOCTOR      " << endl
             << endl;
        cout << "\t\t\t\t\t\t\t2. PATIENT     " << endl
             << endl;
        cout << "\t\t\t\t\t\t\t3. EXIT        " << endl
             << endl;

        cout << "\t\t\t\t\t\t    Enter your choice: ";
        cin >> choice2;

        switch (choice2)
        {

        case 1:
            system("clear");
        label3:

            cout << "\t\t\t\t\t\t         *********< DOCTOR'S SYSTEM >*********" << endl;
            cout << "\t\t\t\t\t\t      =" << setfill('=') << setw(43) << "=" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t1. Add new Doctor's Information              " << endl
                 << endl;
            TimeDisplay();
            cout << "\t\t\t\t\t\t\t2. Display Doctor's Information              " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t3. Details of All the Doctor's Information   " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t4. EXIT                                      " << endl
                 << endl
                 << endl;

            cout << "\t\t\t\t\t\t    Enter your choice: ";
            cin >> choice3;

            switch (choice3)
            {

            case 1:
                system("clear");
                //new doctor's info
                d.addDoctorInfo();
                goto label3;
                system("clear");
                break;

            case 2:
                system("clear");
                //display doctor's info
                d.displayDoctorInfo();
                cin.get();
                goto label3;
                system("clear");
                break;

            case 3:
                system("clear");
                //details of all the doctor's info
                d.detailOfAllDoctor();
                goto label3;
                cin.get();
                break;

            case 4:
                system("clear");
                //EXIT
                goto label2;
                break;

            default:
                cout << "Invalid choice : " << choice3 << endl;
                goto label3;
                break;
            }
            break;

        case 2:
            system("clear");
        label4:

            cout << "\t\t\t\t\t\t         *********< PATIENT'S SYSTEM >*********" << endl;
            cout << "\t\t\t\t\t\t    =" << setfill('=') << setw(48) << "=" << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t1. Add new Patient's Information              " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t2. Display Patient's Information              " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t3. Details of All the Patient's Information   " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t4. Generate Patient's Report                  " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t5. Generate Patient's Bill                    " << endl
                 << endl;
            cout << "\t\t\t\t\t\t\t6. EXIT                                       " << endl
                 << endl;

            cout << "\t\t\t\t\t\t    Enter your choice: ";
            cin >> choice4;

            switch (choice4)
            {

            case 1:
                system("clear");
                //Add new Patient's Information
                break;
            case 2:
                system("clear");
                //Display Patient's Information
                break;
            case 3:
                system("clear");
                //Details of All the Patient's Information
                break;
            case 4:
                system("clear");
                //Generate Patient's Report
                break;
            case 5:
                system("clear");
                //Generate Patient's Bill
                break;

            case 6:
                system("clear");
                //EXIT
                goto label2;
                break;

            default:
                cout << "Invalid choice : " << choice4 << endl;
                goto label4;
                break;
            }
            break;
        case 3:
            goto label1;
            break;
        default:
            cout << "Invalid choice: " << choice2 << endl;
            goto label2;
        }
        break;

    case 2:
        cout << "\t\t\t\t\t**********< THANK YOU FOR WORKING!! >**********" << endl;
        exit(0);
    default:
        cout << "Invalid choice: " << choice1 << endl;
        goto label1;
        break;
    }
}