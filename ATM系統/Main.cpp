#include<iostream>
#include"Account.h"
#include"balance.h"
#include"Withdraw_cash.h"
#include"Deposit_funds.h"

//#include"account.cpp"
using namespace std;

int main()

{
  
    Account1 v1;
    int Total_balance = v1.total_balance1;
    int available_balance = v1.available_balance1;

    int zxc = 0;
    int mo = 0;

    int nm = 0;
    int mo1 = 0, mo2 = 0;

    int o = 0;
    int p = 0;

    Account2 v2;
    int Total_balance2 = v2.total_balance2;
    int available_balance2 = v2.available_balance2;


    int q = 0, w = 0, e = 0, mo3 = 0, mo4 = 0;
   
    while (true)
    {

        int number=0, PIN=0, id=0;
        int s = 0;
        int sum = 0;
        do
        {
            cout << "Welcome!\n" << endl;
            cout << "Please enter your account number:";
            cin >> number;
            if (number == 12345 || number == 98765)
            {
                cout << endl << "Enter your PIN:";
                cin >> PIN;
                if (number == 12345 && PIN == 54321)
                {
                    sum = 1;
                    break;
                }
                if (number != 12345 && PIN != 54321 && PIN == 56789)
                {
                    sum = 2;
                    break;
                }
                else {
                    cout << "\nYour wrong.\n\n";
                }
            }
            else
                cout << "\nYour wrong.\n\n";
        } while (true);
        int choice;
        cout << endl;
        while (true)
        {
            
            
            if (s == 1)
                break;
            else
                s = 0;
           
            cout << "Main menu:" << endl;
            cout << "1 - View my balance\n";
            cout << "2 - Withdraw cash\n";
            cout << "3 - Deposit funds\n";
            cout << "4 - Exit\n";
            cout << endl;
            cout << "Enter a choice:";
            choice = inputAnInteger1(1, 4);
            cout << endl;

            switch (choice)
            {
            case 1:
                if (sum == 1)
                {
                    o = getBalance1(Total_balance, available_balance, mo, p, o);
                    break;
                }
                else
                {
                    q = getBalance2(Total_balance2, available_balance2, e, w, q);
                    break;
                }
            case 2:
                if (sum == 1)
                {
                    mo += withdraw(Total_balance, available_balance, zxc);
                    break;
                }
                else
                {
                    e += withdraw2(Total_balance2, available_balance2, zxc);
                    break;
                }
            case 3:
                if (sum == 1)
                {
                    mo1 = deposit(Total_balance, available_balance, nm);
                    mo2 = deposit2(Total_balance, available_balance, mo1);
                    o += mo2;
                    p += mo1;
                    break;
                }
                else
                {
                    mo3 = deposit3(Total_balance2, available_balance2, nm);
                    mo4 = deposit4(Total_balance2, available_balance2, mo3);
                    q += mo4;
                    w += mo3;
                    break;
                }
            case 4:
                cout << "Exiting the system...\n\n";
                cout << "Thank you! Goodbye!\n\n";
                s = 1;
                break;

            default:
                cout << "Input Error!\n\n";
                break;

            }
            
        }
    }



    system("pause");

    
}


