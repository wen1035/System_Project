#pragma once
#ifndef balance_h
#define balance_h
#include<cmath>
#include"Account.h"
#include"Withdraw_cash.h"
#include"Deposit_funds.h"
#include<iostream>

using namespace std;
class balance //�x�W�����
{
public:

    int getBalance1(int b,int a ,int i ,int j ,int k);
    int getBalance2(int b, int a, int i, int j, int k);//a�O�ۤv���l�B�Ab�O���x��,i�O�n��Aj�O�n�[��,k�O�l��
   
};
#endif//_ACCOUNT_H_

int getBalance1(int b,int a ,int i ,int j ,int k)//a�O�ۤv���l�B�Ab�O���x��,i�O�n��Aj�O�n�[��
{
    a -= i;
    b -= i;
    j /= 100;
    b += j;
    int s = 0;
   
    if (k >= 0 && k <= 9)
    {
        cout << "Balance Information:" << endl;
        cout << "- Available balance: $" << a << ".00" << endl;
        cout << "- Total balance :    $" << b << ".0"<<k << endl << endl;
    }
    else
    {
        if (k >= 100)
        {
            s = k / 100;
            b += s;
            k %= 100;
            if (k >= 0 && k <= 9)
            {
                cout << "Balance Information:" << endl;
                cout << "- Available balance: $" << a << ".00" << endl;
                cout << "- Total balance :    $" << b << ".0" << k << endl << endl;
            }
            else
            {
                cout << "Balance Information:" << endl;
                cout << "- Available balance: $" << a << ".00" << endl;
                cout << "- Total balance :    $" << b << "." << k << endl << endl;
            }
        }
        else
        {
            cout << "Balance Information:" << endl;
            cout << "- Available balance: $" << a << ".00" << endl;
            cout << "- Total balance :    $" << b << "." << k << endl << endl;
        }
    }
    return k;
}

int getBalance2(int b, int a, int i, int j, int k)//a�O�ۤv���l�B�Ab�O���x��,i�O�n��Aj�O�n�[��
{
    a -= i;
    b -= i;
    j /= 100;
    b += j;
    int s = 0;

    if (k >= 0 && k <= 9)
    {
        cout << "Balance Information:" << endl;
        cout << "- Available balance: $" << a << ".00" << endl;
        cout << "- Total balance :    $" << b << ".0" << k << endl << endl;
    }
    else
    {
        if (k >= 100)
        {
            s = k / 100;
            b += s;
            k %= 100;
            if (k >= 0 && k <= 9)
            {
                cout << "Balance Information:" << endl;
                cout << "- Available balance: $" << a << ".00" << endl;
                cout << "- Total balance :    $" << b << ".0" << k << endl << endl;
            }
            else
            {
                cout << "Balance Information:" << endl;
                cout << "- Available balance: $" << a << ".00" << endl;
                cout << "- Total balance :    $" << b << "." << k << endl << endl;
            }
        }
        else
        {
            cout << "Balance Information:" << endl;
            cout << "- Available balance: $" << a << ".00" << endl;
            cout << "- Total balance :    $" << b << "." << k << endl << endl;
        }
    }
    return k;
}
