#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsDepositScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClientCard:";
		cout << "\n_______________________";
		cout << "\nFirstName	:" << Client.FirstName;
		cout << "\nLastName	:" << Client.LastName;
		cout << "\nFullName	:" << Client.FullName();
		cout << "\nEmail		:" << Client.Email;
		cout << "\nPhone		:" << Client.Phone;
		cout << "\nAcc. Number	:" << Client.AccountNumber();
		cout << "\nPassword	:" << Client.PinCode;
		cout << "\nBalance		:" << Client.AccountBalance;
		cout << "\n_______________________\n";
	}
	static string _ReadAccountNumber()
	{
		cout << "\nPlease Enter Account Number: ";
		return clsInputValidate::ReadString();	 
	}

public:
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t	Deposit Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease enter deposit amount ";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure you want to perform this transaction?";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Client1.Deposite(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance is: " << Client1.AccountBalance;
		}
		else
		{
			cout << "\nOperation is cancelled.\n";
		}
	}
};

