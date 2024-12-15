#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include"clsUtil.h"
#include <iomanip>
class clsTransferScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClientCard:";
		cout << "\n_______________________";
		cout << "\nFullName	:" << Client.FullName();
		cout << "\nAcc. Number	:" << Client.AccountNumber();
		cout << "\nBalance		:" << Client.AccountBalance;
		cout << "\n_______________________\n";
	}

	static string _ReadAccountNumber()
	{
		string   AccountNumber;
		cout << "\nPlease Enter Account Number To Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return  AccountNumber;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the avaiable Balance, Enter another Amount ? \n";
			Amount = clsInputValidate::ReadFloatNumber();
		}
		return Amount;
	}
public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t    Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(DestinationClient);

		float Amount = ReadAmount(SourceClient);

		cout << "\nAre you sure you want to perform this transaction?";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if(SourceClient.Transfer(Amount,DestinationClient,CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Failed.\n";
			}
		}
		

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}

};

