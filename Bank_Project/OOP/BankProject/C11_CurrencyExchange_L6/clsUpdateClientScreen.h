#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<iomanip>
class clsUpdateClientScreen:protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();

	}

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
	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;//this will exit the function and it will not continue
		}
		_DrawScreenHeader("\tUpdate Client Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
		    cout << "\nAccount Number is not found, choose another one: ";
		    AccountNumber = clsInputValidate::ReadString();
		}
		
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);
		
		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";
		
		_ReadClientInfo(Client1);
		
		clsBankClient::enSaveResults SaveResult;
		
		SaveResult = Client1.Save();
		
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
		    cout << "\nAccount Updated Successfully :-)\n";
		    _PrintClient(Client1);
		    break;
		}
		case clsBankClient::enSaveResults::svFailEmptyObject:
		{
		    cout << "\nError account was not saved because it's Empty";
		}
		}
	}
};

