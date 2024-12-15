#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
#include <iomanip>

class clsTransactionsScreen:protected clsScreen
{

private:
	enum enTransactionsMenueOptions {
		eDeposite = 1, eWithdraw = 2, eShowTotalBalances = 3,
		eTransfer = 4, eTransferLog = 5, eShowMainMenue = 6
	};

	static short ReadTransactionsMenue()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do From 1 to 6 ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6  ");
		return Choice;
	}
	static void _ShowDepositeScreen()
	{
		//cout << "\nDeposite Screen Will be here...\n";
		clsDepositScreen::ShowDepositScreen();

	}

	static void _ShowWithdrawScreen()
	{
		//cout << "\Withdraw Screen Will be here...\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		//cout << "\Show Total Balances Screen Will be here...\n";
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		//cout << "\Show Transfer Screen Will be here...\n";
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		//cout << "\Show Transfer Screen Will be here...\n";
		clsTransferLogScreen::ShowLoginRegisterScreen();
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menue...\n";

		system("pause>0");
		ShowTransactionsMenue();
	}
	static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
	{
		switch (TransactionsMenueOption)
		{
		case enTransactionsMenueOptions::eDeposite:
		{
			system("cls");
			_ShowDepositeScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowTotalBalances:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowMainMenue:
		{
			//do nothing here the main screen will handle it :-)
		}
		}

	}

public:
	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return;//this will exit the function and it will not continue
		}
		system("cls");
		_DrawScreenHeader("\t Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposite.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Show Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenue());
	}
};

