#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include <iomanip>

using namespace std;
class clsManageUsersScreen:protected clsScreen
{
private:
	enum enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUsers = 2, eDeleteUsers = 3,
		eUpdateUser = 4, eFindUser, eMainMenue = 6
	};

	static short _ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 8, "Enter Number between 1 to 6");
		return Choice;
	}

	static void _ShowListUsersScreen()
	{
		//cout << "\List Users Screen Will be here...\n";
		clsListUsersScreen::ShowUsersList();
	}

	static void _AddNewUsersScreen()
	{
		//cout << "\Add New Users Screen Will be here...\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _DeleteUsersScreen()
	{
		//cout << "\nDelete Users Screen Will be here...\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _UpdateUsersScreen()
	{
		//cout << "\nUpdate Users Screen Will be here...\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _FindUsersScreen()
	{
		//cout << "\Find Users Screen Will be here...\n";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users Menue...\n";

		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
	{
		switch (ManageUsersMenueOption)
		{
		case enManageUsersMenueOptions::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eAddNewUsers:
		{
			system("cls");
			_AddNewUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eDeleteUsers:
		{
			system("cls");
			_DeleteUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eUpdateUser:
		{
			system("cls");
			_UpdateUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eFindUser:
		{
			system("cls");
			_FindUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eMainMenue:
		{
			//do nothing here the main screen will be handled it :-)
		}
		}
	}
public:

	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;//this will exit the function and it will not continue
		}
		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformManageUsersMenueOption((enManageUsersMenueOptions)_ReadManageUsersMenueOption());
	}
};

