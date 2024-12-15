#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<iomanip>
class clsDeleteClientScreen:protected clsScreen
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
public:
	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClients))
		{
			return;//this will exit the function and it will not continue
		}
		_DrawScreenHeader("\t Delete Client Screen");

		string AccountNumber = "";
		cout << "\nPlease Enter Account Number:";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
		    cout << "\nAccount number is not found, choose another one: ";
		    AccountNumber = clsInputValidate::ReadString();
		}
		
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);
		
		cout << "\nAre you sure you want to delete this Client y/n?";
		
		char Answer = 'n';
		cin >> Answer;
		
		if (Answer == 'y' || Answer == 'Y')
		{
		    if (Client1.Delete())
		    {
		        cout << "\nClient Deleted Successfully :-)\n";
		
		        _PrintClient(Client1);
		    }
		    else
		    {
		        cout << "\nError Client Was not Deleted\n";
		    }
		}
	}
};

