#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H_
#include<cmath>
#include <ctime>
#include <vector>
#include<iostream>

using namespace std;
class Account1 //Àx»W½ã¤áÃþ
{
 public:
     int number1=12345;
     int PIN2 =54321;
     int available_balance1 = 1000;
     int total_balance1=1200;
    

};
class Account2 //Àx»W½ã¤áÃþ
{
public:
    int number2 = 98765;
    int PIN2 = 56789;
    int available_balance2 = 200;
    int total_balance2=200;
    int inputAnInteger2(int begin, int end);
};

#endif//_ACCOUNT_H_
