#pragma once
#ifndef Deposit_funds_h
#define Deposit_funds_h
#include<cmath>

#include<iostream>

using namespace std;
class Deposit_funds //�x�W�����
{
public:

    int deposit(int abalance, int tbalance, int zxc); //�s�J�{��

    int deposit2(int abalance, int tbalance, int zxc);//�s��

    int deposit3(int abalance, int tbalance, int zxc); //�s�J�{��

    int deposit4(int abalance, int tbalance, int zxc);//�s��
     
    int inputAnInteger2(int begin, int end);
   
};
//�q��L��J�@�Ӿ�ơA�M��
//�p�G���ݩ�[begin�Aend]�A�h��^��ơA�_�h��^-1�C
int inputAnInteger2(int begin, int end)
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
        if (abc.length()==2&&abc[i] == '0' && abc[i + 1] == '0')
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
int deposit(int abalance, int tbalance, int zxc) //�s��
{

    int choice;
    int r;
    int m;
    while (true)
    {
        while (true)
        {
            cout << "Please enter a deposit amount in CENTS (or 0 to cancel): ";
            choice = inputAnInteger2(0, 100000);
            if (choice != -1)
            {
                break;
            }
        }
        if (choice == 0)
            break;
        
        r = choice / 100;
        m = choice % 100;
        if (m >= 0 && m <= 9)
        {
            cout << "\nPlease insert a deposit envelope containing $" << r << ".0" << m << " in the deposit slot.\n";
            cout << "\nYour envelope has been received.\n" << "NOTE: The money deposited will not be available until we\n" << "verify the amount of any enclosed cash, and any enclosed checks clear.\n";
        }
        else
        {
            cout << "\nPlease insert a deposit envelope containing $" << r << "." << m << " in the deposit slot.\n";
            cout << "\nYour envelope has been received.\n" << "NOTE: The money deposited will not be available until we\n" << "verify the amount of any enclosed cash, and any enclosed checks clear.\n";
        }
        cout << endl;
        return choice;
    }
}


int deposit2(int abalance, int tbalance, int zxc) //�s��
{

    int choice=zxc;
    int r;
    int m;
 
    if (choice == 0)
    {
        cout << endl;
        return 0;
    }
   
    m = choice % 100;
   
    return m;
    
}


int deposit3(int abalance, int tbalance, int zxc) //�s��
{

    int choice;
    int r;
    int m;
    while (true)
    {
        while (true)
        {
            cout << "Please enter a deposit amount in CENTS (or 0 to cancel): ";
            choice = inputAnInteger2(0, 100000);
            if (choice != -1)
            {
                break;
            }
        }
        if (choice == 0)
            break;

        r = choice / 100;
        m = choice % 100;
        if (m >= 0 && m <= 9)
        {
            cout << "\nPlease insert a deposit envelope containing $" << r << ".0" << m << " in the deposit slot.\n";
            cout << "\nYour envelope has been received.\n" << "NOTE: The money deposited will not be available until we\n" << "verify the amount of any enclosed cash, and any enclosed checks clear.\n";
        }
        else
        {
            cout << "\nPlease insert a deposit envelope containing $" << r << "." << m << " in the deposit slot.\n";
            cout << "\nYour envelope has been received.\n" << "NOTE: The money deposited will not be available until we\n" << "verify the amount of any enclosed cash, and any enclosed checks clear.\n";
        }
        cout << endl;
        return choice;
    }
}


int deposit4(int abalance, int tbalance, int zxc) //�s��
{

    int choice = zxc;
    int r;
    int m;

    if (choice == 0)
    {
        cout << endl;
        return 0;
    }

    m = choice % 100;

    return m;

}



#endif//_ACCOUNT_H_
