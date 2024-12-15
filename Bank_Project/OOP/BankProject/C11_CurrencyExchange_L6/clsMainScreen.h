#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyExchangeMainScreen.h"
#include"Global.h"
#include<iomanip>
class clsMainScreen:protected clsScreen
{
private:
	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4,
		eFindClient = 5, eShowTransactionsMenue = 6, eManageUsers = 7, eLoginRegister = 8,
		eCurrencyExchange = 9, eExit = 10
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10");
		return Choice;
	}
	
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowAllClientsScreen()
	{
		//cout << "\nClient List Screen Will be here...\n";
		clsClientListScreen::ShowClientsList();
	}
	
	static void _ShowAddNewClientScreen()
	{
		//cout << "\nAdd New Client Screen Will be here...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	
	static void _ShowDeleteClientScreen()
	{
		//cout << "\nDelete Client Screen Will be here...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	
	static void _ShowUpdateClientScreen()
	{
		//cout << "\nUpdate Client Screen Will be here...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	
	static void _ShowFindClientScreen()
	{
		//cout << "\nFind Client Screen Will be here...\n";
		clsFindClientScreen::ShowFindClientScreen();
	}
	
	static void _ShowTransactionMenueScreen()
	{
		//cout << "\nTransaction Menue Screen Will be here...\n";
		clsTransactionsScreen::ShowTransactionsMenue();
	}
	
	
	static void _ShowManageUsersScreen()
	{
		//cout << "\nManage Users Screen Will be here...\n";
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	static void _ShowLoginRegisterScreen()
	{
		//cout << "\nLogin Register Screen Will be here...\n";
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		//cout << "\nCurrency Exchange Screen Will be here...\n";
		clsCurrencyExchangeMainScreen::ShowCurrencyExchangeMainMenue();
	}
	
	static void _Logout()
	{
		//cout << "\nLogout Screen Will be here...\n";

		CurrentUser = clsUser::Find("", "");

		//clsLoginScreen:;ShowLoginScreen(); error..........circular referance causing deadlock
	}

	static void PerformMainMenueOption(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eShowTransactionsMenue:
		{
			system("cls");
			_ShowTransactionMenueScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eManageUsers:
		{
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eExit:
		{
			system("cls");
			_Logout();
			break;
		}

		}
	}

public:
	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t\tMainScreen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		PerformMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
	}
};

