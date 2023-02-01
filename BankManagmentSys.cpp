#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<fstream>
#include <stdlib.h>
#include <ctime>
#pragma warning(disable : 4996)
using namespace std;

class bank
{
    int acno;
    char nm[100], acctype[100];
    float bal;

public:bank(int acc_no, char* name, char* acc_type, float balance)
{
    acno = acc_no;
    strcpy_s(nm, name);
    strcpy_s(acctype, acc_type);
    bal = balance;
}
      void deposit();
      void withdraw();
      void display();
};
void bank::deposit()
{
    int damt1;
    cout << "\n Enter Deposit Amount = ";
    cin >> damt1;
    bal += damt1;
}
void bank::withdraw()
{
    int wamt1;
    cout << "\n Enter Withdraw Amount = ";
    cin >> wamt1;
    if (wamt1 > bal)
        cout << "\n Cannot Withdraw Amount";
    bal -= wamt1;
}
void bank::display()
{
    cout << "\n ----------------------";
    cout << "\n Accout No. : " << acno;
    cout << "\n Name : " << nm;
    cout << "\n Account Type : " << acctype;
    cout << "\n Balance : " << bal << " $.";
}
int main()
{
    int acc_no;
    char name[100], acc_type[100];
    float balance;
    string bankHistorySaver;
    cout << "Make your choise: 1 - Account Details | 2 - GetHistoryAboutYourAccount | 3 - Quit\n";
    int choise;
    cin >> choise;
    
    if (choise == 1) {
        cout << "\n Enter Details: \n";
        cout << "-----------------------";

        cout << "\n Accout No. ";
        cin >> acc_no;

        cout << "\n Name : ";
        cin >> name;

        cout << "\n Account Type : ";
        cin >> acc_type;

        cout << "\n Balance : ";
        cin >> balance;

        cout << "\n BankHistoryName: ";
        cin >> bankHistorySaver;

        ofstream file;
        file.open("D:\\CProjects\\Pr6\\BDSys\\" + bankHistorySaver + ".txt");
        if (file.is_open()) {
            time_t ttime = time(0);
            tm* local_time = localtime(&ttime);

            file << "Account No: " << acc_no << endl << "Name: " << name << endl << "Account Type: " << acc_type << endl << "Balance: " << balance << " $" << endl;
            file << "Year: " << 1900 + local_time->tm_year << " ";
            file << "Month: " << 1 + local_time->tm_mon << " ";
            file << "Day: " << local_time->tm_mday << " ";
            file << "Time: " << local_time->tm_hour << ":";
            file << local_time->tm_min << ":";
            file << local_time->tm_sec << endl;
        }

        bank b1(acc_no, name, acc_type, balance);
        b1.deposit();
        b1.withdraw();
        b1.display();
        


    }

    else if (choise == 2) {
        //Show info
        cout << "-------- BankHistoryInfo -----------\n";
        cout << "Enter BankHistoryName: ";
        string bankaccname;
        cin >> bankaccname;
        
        ifstream read("D:\\CProjects\\Pr6\\BDSys\\" + bankaccname + ".txt");
        if (read.is_open()) {
            string str;
            while (read)
            {
                str = read.get();
                cout << str;
            }
            
        }
        read.close();
    }
    else if (choise == 3){
        cout << "Bye, bye !";
        exit(0);
    }
    else
    {
        cout << "Error ! Try again.";
    }

    return 0;
}