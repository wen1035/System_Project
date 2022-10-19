#pragma once
#ifndef Deposit_funds_h
#define Deposit_funds_h
#include<cmath>

#include<iostream>

using namespace std;
class Deposit_funds //儲蓄賬戶類
{
public:

    int deposit(int abalance, int tbalance, int zxc); //存入現金

    int deposit2(int abalance, int tbalance, int zxc);//存錢

    int deposit3(int abalance, int tbalance, int zxc); //存入現金

    int deposit4(int abalance, int tbalance, int zxc);//存錢
     
    int inputAnInteger2(int begin, int end);
   
};
//從鍵盤輸入一個整數，然後
//如果它屬於[begin，end]，則返回整數，否則返回-1。
int inputAnInteger2(int begin, int end)
{
    string abc;
    int number = 0;
    int i = 0;
    cin >> abc;//輸入字或2以上數字
    int k = pow(10, abc.length() - 1);//10的次方，用來轉數字

    //將輸入字串改成數字
    while (abc[i] != '\0')
    {
        if (!((abc[i] >= 48) && (abc[i] <= 57)))//判斷是否在ASCII的數字代號的範圍(其中48～57為0到9十個阿拉伯數字)
        {
            number = -1;
            break;
        }
        if (abc.length()==2&&abc[i] == '0' && abc[i + 1] == '0')
        {
            number = -1;
            break;
        }
        number += (abc[i] - '0') * k;//字元-'0'乘10的次方
        k /= 10;//減一個次方
        i++;
    }

    //判斷是否在範圍內
    for (int j = begin; j <= end; j++)
    {
        if (number == j)
            return j;
    }
    return -1;
}
int deposit(int abalance, int tbalance, int zxc) //存錢
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


int deposit2(int abalance, int tbalance, int zxc) //存錢
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


int deposit3(int abalance, int tbalance, int zxc) //存錢
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


int deposit4(int abalance, int tbalance, int zxc) //存錢
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
