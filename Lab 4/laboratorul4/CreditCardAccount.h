#pragma once
#include "LoyaltyScheme.h"
using namespace System;








ref class CreditCardAccount
{
public:
	void RedeemLoyaltyPoints();
	literal String^ name = "Super Platinum Card";
	CreditCardAccount(long number, double limit);
	static  int GetNumberOfAccounts();
	void SetCreditLimit(double amount);
	bool MakePurchase(double amount);
	void MakeRepayment(double amount);
	void PrintStatement();
	long GetAccountNumber();
	static CreditCardAccount();

private:
	LoyaltyScheme^ scheme;
	static int numberOfAccounts = 0;
	initonly long accountNumber;
	double currentBalance;
	double creditLimit;
	static double interestRate;
};
