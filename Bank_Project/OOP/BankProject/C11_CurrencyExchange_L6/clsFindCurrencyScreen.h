#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsFindCurrencyScreen:protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\Currency Card:";
		cout << "\n___________________";
		cout << "\nCountry     : " << Currency.Country();
		cout << "\nCode        : " << Currency.CurrencyCode();
		cout << "\nName	    : " << Currency.CurrencyName();
		cout << "\nRate(1$)    : " << Currency.Rate();
		cout << "\n___________________\n";
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was Not Found :-(\n";
		}
	}
	
public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen ");

		short Answer =1;
		cout << "\nFind By: [1] Code or [2] Country ? ";
		Answer =clsInputValidate::ReadShortNumberBetween(1,2,"Please Enter Number between 1 to 2 ");
		
		if (Answer == 1)
		{
			string CountryCode;
			cout << "\nPlease Enter CurrencyCode: ";
			CountryCode = clsInputValidate::ReadString();

			clsCurrency Currency=clsCurrency::FindByCode(CountryCode);


			_ShowResults(Currency);
		}
		else 
		{
			string Country;
			cout << "\nPlease Enter Country: ";
			Country = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(Country);

			_ShowResults(Currency);
		}
	}

};

