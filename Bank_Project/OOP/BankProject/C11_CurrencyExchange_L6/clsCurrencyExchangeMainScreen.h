#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
#include <iomanip>


class clsCurrencyExchangeMainScreen:protected clsScreen
{
private:
	enum enCurrencyExchangeMainScreen {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalculator = 4, eMainMenue = 5
	};

	static short ReadCurrencyExchangeMenue()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do From 1 to 5 ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 5  ");
		return Choice;
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\nList Currencies Screen Will be here...\n";
		clsListCurrenciesScreen::ShowCurrenciesList();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen Will be here...\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\nUpdate Rate Screen Will be here...\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nCurrency Calculator Screen Will be here...\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurrencyExchangeMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Currency Exchange Main Menue...\n";

		system("pause>0");
		ShowCurrencyExchangeMainMenue();
	}
	static void _PerformTransactionsMenueOption(enCurrencyExchangeMainScreen CurrencyExchangeMainScreen)
	{
		switch (CurrencyExchangeMainScreen)
		{
		case enCurrencyExchangeMainScreen::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMainMenue();
			break;
		}
		case enCurrencyExchangeMainScreen::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMainMenue();
			break;
		}
		case enCurrencyExchangeMainScreen::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMainMenue();
			break;
		}
		case enCurrencyExchangeMainScreen::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMainMenue();
			break;
		}
		case enCurrencyExchangeMainScreen::eMainMenue:
		{
			//do nothing here the main screen will handle it :-)
		}
		}

	}
public:
	static void ShowCurrencyExchangeMainMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
		{
			return;//this will exit the function and it will not continue
		}
		system("cls");
		_DrawScreenHeader("\t Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionsMenueOption((enCurrencyExchangeMainScreen)ReadCurrencyExchangeMenue());
	}
};

