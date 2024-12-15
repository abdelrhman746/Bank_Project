#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsTransferLogScreen:protected clsScreen
{
private:
	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord	TransferLogRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << TransferLogRecord.DateTime;
		cout << "| " << setw(12) << left << TransferLogRecord.SourceAccountNumber;
		cout << "| " << setw(12) << left << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << setw(12) << left << TransferLogRecord.Amount;
		cout << "| " << setw(12) << left << TransferLogRecord.SourceBalance;
		cout << "| " << setw(12) << left << TransferLogRecord.DestinationBalance;
		cout << "| " << setw(12) << left << TransferLogRecord.User;
	}
public:
	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;//this will exit the function and it will not continue
		}
		vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferlogList();
		string Title = "\t	Login Register List Screen";
		string SubTitle = "\t	  (" + to_string(vTransferLogRecord.size()) + ") Record(s)";

		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t________________________________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(12) << "s.Acct";
		cout << "| " << left << setw(12) << "d.Acct";
		cout << "| " << left << setw(12) << "Amouunt";
		cout << "| " << left << setw(12) << "s.Balance";
		cout << "| " << left << setw(12) << "d.Balance";
		cout << "| " << left << setw(12) << "User";
		cout << setw(8) << left << "" << "\n\t________________________________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (vTransferLogRecord.size() == 0)
		{
			cout << "\t\t\t\tNo Transfer logs Available In the System!";
		}
		else
		{
			for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
			{
				_PrintTransferLogRecordLine(Record);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t________________________________________________________________________";
		cout << "_________________________________________\n" << endl;


	}
};

