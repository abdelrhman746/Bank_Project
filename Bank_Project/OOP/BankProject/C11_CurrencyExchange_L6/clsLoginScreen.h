#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"
#include <iomanip>

class clsLoginScreen:protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFailed = false;
		short FailedLoginCount = 0;
		string Username, Password;
		do
		{
			if (LoginFailed)
			{
				FailedLoginCount++;
				cout << "\nInvalid Username/Password!";
				cout << "\nyou have "<<(3 - FailedLoginCount) <<" Trial(s) to login.\n\n";
			}

			if (FailedLoginCount == 3)
			{
				cout << "\nYou are Locked after 3 failed trials";
				return false;
			}
			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:
	static short ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();

	}
};

