#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<iomanip>
class clsFindClientScreen:protected clsScreen
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
	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;//this will exit the function and it will not continue
		}
		_DrawScreenHeader("\tFind Client Screen");

		string AccountNumber;
		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		if (!Client1.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient Was not Found :-(";
		}
		_PrintClient(Client1);
	}
};

