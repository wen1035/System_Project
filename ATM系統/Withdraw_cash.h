#pragma once
#ifndef Withdraw_cash_h
#define Withdraw_cash_h
#include<cmath>

#include<iostream>

using namespace std;
class Withdraw //�x�W�����
{
public:

    
    int withdraw(int abalance, int tbalance ,int zxc); //���X�{��
    int withdraw2(int abalance, int tbalance, int zxc); //���X�{��
 
    int inputAnInteger1(int begin, int end);
    
   
};
//�q��L��J�@�Ӿ�ơA�M��
//�p�G���ݩ�[begin�Aend]�A�h��^��ơA�_�h��^-1�C
int inputAnInteger1(int begin, int end)
{
    string abc;
    int number = 0;
    int i = 0;
    cin >> abc;//��J�r��2�H�W�Ʀr
    int k = pow(10, abc.length() - 1);//10������A�Ψ���Ʀr

    //�N��J�r��令�Ʀr
    while (abc[i] != '\0')
    {
        if (!((abc[i] >= 48) && (abc[i] <= 57)))//�P�_�O�_�bASCII���Ʀr�N�����d��(�䤤48��57��0��9�Q�Ӫ��ԧB�Ʀr)
        {
            number = -1;
            break;
        }
        if (abc[i] == '0' && abc[i + 1] == '0')
        {
            number = -1;
            break;
        }
        number += (abc[i] - '0') * k;//�r��-'0'��10������
        k /= 10;//��@�Ӧ���
        i++;
    }

    //�P�_�O�_�b�d��
    for (int j = begin; j <= end; j++)
    {
        if (number == j)
            return j;
    }
    return -1;
}
int withdraw(int abalance, int tbalance,int zxc) //���X�{���Azxc�O��X�Ӫ��B
{
    
    int choice;
    while (true)
    {
        cout << "Withdrawal options :" << endl;
        cout << "1 - $20\n";
        cout << "2 - $40\n";
        cout << "3 - $60\n";
        cout << "4 - $100\n";
        cout << "5 - $200\n";
        cout << "6 - Cancel transaction\n";
        while (true)
        {
            cout << "\nChoose a withdrawal option (1-6):";
            choice = inputAnInteger1(1, 6);
            if (choice != -1)
                break;
        }
        cout << endl;
        switch (choice)
        {
        case 1:
            if (abalance >= 20)
            {
                if (tbalance < 20)
                {
                    cout <<"Insufficient amount of this machine.\n" << endl << "Please choose a smaller amount.\n" << endl;
                }
                else
                {
                    abalance -= 20;
                    tbalance -= 20;
                    cout << "Please take your cash from the cash dispenser.\n" << endl;
                    zxc += 20;
                    return zxc;
                    
                }
            }
            else
                cout <<"Your balance:"<< abalance << "\nPlease choose a smaller amount.\n";
            break;

        case 2:
            if (abalance >= 40)
            {
                if (tbalance < 40)
                {

                    cout << "Insufficient amount of this machine.\n" << endl << "Please choose a smaller amount.\n" << endl;
                }
                else
                {
                    abalance -= 40;
                    tbalance -= 40;
                    cout << "Please take your cash from the cash dispenser." << endl;
                    zxc += 40;
                    return zxc;
                }
            }
            else
                cout << "Your balance:" << abalance << "\nPlease choose a smaller amount.\n";
            break;

        case 3:
            if (abalance >= 60)
            {
                if (tbalance < 60)
                {
                    cout << "Insufficient amount of this machine.\n" << endl << "Please choose a smaller amount.\n" << endl;
                }
                else
                {
                    abalance -= 60;
                    tbalance -= 60;
                    cout << "Please take your cash from the cash dispenser." << endl;
                    zxc += 60;
                    return zxc;
                }
            }
            else
                cout << "Your balance:" << abalance << "\nPlease choose a smaller amount.\n";
            break;

        case 4:
            if (abalance >= 100)
            {
                if (tbalance < 100)
                {
                    cout << "Insufficient amount of this machine.\n" << endl << "Please choose a smaller amount.\n" << endl;
                }
                else
                {
                    abalance -= 100;
                    tbalance -= 100;
                    cout << "Please take your cash from the cash dispenser." << endl;
                    zxc += 100;
                    return zxc;
                }
            }
            else
                cout << "Your balance:" << abalance << "\nPlease choose a smaller amount.\n";
            break;
        
        case 5:
            if (abalance >= 200)
            {
                if (tbalance < 200)
                {
                    cout << "Insufficient amount of this machine.\n" << endl << "Please choose a smaller amount.\n" << endl;
                }
                else
                {
                    abalance -= 200;
                    tbalance -= 200;
                    cout << "Plese take your cash from the cash dispenser." << endl;
                    zxc += 200;
                    return zxc;
                }
            }
            else
                cout << "Your balance:" << abalance << "\nPlease choose a smaller amount.\n";
            break;
        
        case 6:
            return 0;
        
        default:
            cout << "Input Error!\n\n";
            break;

        }
       
    }
   

}
int withdraw2(int abalance, int tbalance, int zxc) //���X�{���Azxc�O��X�Ӫ��B
{

    int choice;
    while (true)
    {
        cout << "Withdrawal options :" << endl;
        cout << "1 - $20\n";
        cout << "2 - $40\n";
        cout << "3 - $60\n";
        cout << "4 - $100\n";
        cout << "5 - $200\n";
        cout << "6 - Cancel transaction\n";
        while (true)
        {
            cout << "\nChoose a withdrawal option (1-6):";
            choice = inputAnInteger1(1, 6);
            if (choice != -1)
                break;
        }
        cout << endl;
        switch (choice)
        {
        case 1:
            if (abalance >= 20)
            {
                if (tbalance < 20)
                {
                    cout << "Insufficient amount of this machine.\n" << endl << "Please choose a smaller amount.\n" << endl;
                }
                else
                {
                    abalance -= 20;
                    tbalance -= 20;
                    cout << "Please take your cash from the cash dispenser.\n" << endl;
                    zxc += 20;
                    return zxc;

                }
            }
            else
                cout << "Your balance:" << abalance << "\nPlease choose a smaller amount.\n";
            break;

        case 2:
            if (abalance >= 40)
            {
                if (tbalance < 40)
                {

                    cout << "Insufficient amount of this machine.\n" << endl << "Please choose a smaller amount.\n" << endl;
                }
                else
                {
                    abalance -= 40;
                    tbalance -= 40;
                    cout << "Please take your cash from the cash dispenser." << endl;
                    zxc += 40;
                    return zxc;
                }
            }
            else
                cout << "Your balance:" << abalance << "\nPlease choose a smaller amount.\n";
            break;

        case 3:
            if (abalance >= 60)
            {
                if (tbalance < 60)
                {
                    cout << "Insufficient amount of this machine.\n" << endl << "Please choose a smaller amount.\n" << endl;
                }
                else
                {
                    abalance -= 60;
                    tbalance -= 60;
                    cout << "Please take your cash from the cash dispenser." << endl;
                    zxc += 60;
                    return zxc;
                }
            }
            else
                cout << "Your balance:" << abalance << "\nPlease choose a smaller amount.\n";
            break;

        case 4:
            if (abalance >= 100)
            {
                if (tbalance < 100)
                {
                    cout << "Insufficient amount of this machine.\n" << endl << "Please choose a smaller amount.\n" << endl;
                }
                else
                {
                    abalance -= 100;
                    tbalance -= 100;
                    cout << "Please take your cash from the cash dispenser." << endl;
                    zxc += 100;
                    return zxc;
                }
            }
            else
                cout << "Your balance:" << abalance << "\nPlease choose a smaller amount.\n";
            break;

        case 5:
            if (abalance >= 200)
            {
                if (tbalance < 200)
                {
                    cout << "Insufficient amount of this machine.\n" << endl << "Please choose a smaller amount.\n" << endl;
                }
                else
                {
                    abalance -= 200;
                    tbalance -= 200;
                    cout << "Plese take your cash from the cash dispenser." << endl;
                    zxc += 200;
                    return zxc;
                }
            }
            else
                cout << "Your balance:" << abalance << "\nPlease choose a smaller amount.\n";
            break;

        case 6:
            return 0;

        default:
            cout << "Input Error!\n\n";
            break;

        }

    }


}


#endif//_ACCOUNT_H_
