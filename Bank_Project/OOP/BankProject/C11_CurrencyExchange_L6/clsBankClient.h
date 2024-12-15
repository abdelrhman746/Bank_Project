#pragma once
#include<iostream>
#include<string>
#include"clsPerson.h"
#include"clsString.h"
#include<vector>
#include<fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode=2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDeleted = false;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Separator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Separator);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1]
			, vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}
	static string _ConvertClientObjectToLine(clsBankClient Client, string Separator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Separator;
		stClientRecord += Client.LastName + Separator;
		stClientRecord += Client.Email + Separator;
		stClientRecord += Client.Phone + Separator;
		stClientRecord += Client.AccountNumber() + Separator;
		stClientRecord += Client.PinCode + Separator;
		stClientRecord += to_string(Client.AccountBalance) ;

		return stClientRecord;
	}
	static vector<clsBankClient> _LoadClientDataFromFile()
	{
		vector<clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}
	
	static void _SaveClientDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				if (C._MarkedForDeleted == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
				
			}

			MyFile.close();

		}

	}
	void _Update()
	{
		vector<clsBankClient>_vClients;
		_vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientDataToFile(_vClients);

	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	string _PrepareTransferLogRecord(double Amount, clsBankClient DestinationClient, string UserName, string Separator = "#//#")
	{
		string TransferRecord = "";
		TransferRecord += clsDate::GetSystemDateTimeString() + Separator;
		TransferRecord += AccountNumber() + Separator;
		TransferRecord += DestinationClient.AccountNumber() + Separator;
		TransferRecord += to_string(Amount) + Separator;
		TransferRecord += to_string(AccountBalance) + Separator;
		TransferRecord += to_string(DestinationClient.AccountBalance) + Separator;
		TransferRecord += UserName;

		return TransferRecord;
	}
	void _RegisterTransferLog(double Amount, clsBankClient DestinationClient, string UserName)
	{
		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}
	struct stTransferLogRecord;

	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Separator = "#//#")
	{
		stTransferLogRecord TransferLogRecord;

		vector<string> vTransferLogRecord = clsString::Split(Line, Separator);

		TransferLogRecord.DateTime = vTransferLogRecord[0];
		TransferLogRecord.SourceAccountNumber = vTransferLogRecord[1];
		TransferLogRecord.DestinationAccountNumber = vTransferLogRecord[2];
		TransferLogRecord.Amount = stof(vTransferLogRecord[3]);
		TransferLogRecord.SourceBalance = stof(vTransferLogRecord[4]);
		TransferLogRecord.DestinationBalance = stof(vTransferLogRecord[5]);
		TransferLogRecord.User = vTransferLogRecord[6];

		return TransferLogRecord;
	}

public:
	struct stTransferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float SourceBalance;
		float DestinationBalance;
		string User;
	};

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	//Property Set
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	//Property Get
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	//Property Set
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	//Property Get
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;


	//Property Set
	void SetMarkedForDeleted(bool MarkedForDeleted)
	{
		_MarkedForDeleted = MarkedForDeleted;
	}
	
	//Property Get
	bool GetMarkedForDeleted()
	{
		return _MarkedForDeleted;
	}

	__declspec(property(get = GetMarkedForDeleted, put = SetMarkedForDeleted))bool MarkedForDeleted;
	/*void Print()
	{
		cout << "\nClientCard:";
		cout << "\n_______________________";
		cout << "\nFirstName	:" << FirstName;
		cout << "\nLastName	:" << LastName;
		cout << "\nFullName	:" << FullName();
		cout << "\nEmail		:" << Email;
		cout << "\nPhone		:" << Phone;
		cout << "\nAcc. Number	:" << _AccountNumber;
		cout << "\nPassword	:" << _PinCode;
		cout << "\nBalance		:" << _AccountBalance;
		cout << "\n_______________________\n";
	}*/

	static clsBankClient Find(string AccountNumber)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);	//Read Mode
		
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}


	static clsBankClient Find(string AccountNumber ,string PinCode)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);	//Read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber&&Client.PinCode==PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C.MarkedForDeleted = true;
				break;
			}
		}

		_SaveClientDataToFile(_vClients);

		*this = _GetEmptyClientObject();
		return true;
	}

	enum enSaveResults { svFailEmptyObject = 0, svSucceeded = 1 ,svFaildAccountNumberExists=2};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			if (IsEmpty())
			{
				return enSaveResults::svFailEmptyObject;
			}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}
			

		case enMode::AddNewMode:
		{
			//This will be add new record file or database
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				//we need to set the mode to update mode after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}

		}
	}

	void Deposite(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool Transfer(double Amount,clsBankClient& DestinationClient,string UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}
		else
		{
			Withdraw(Amount);
			DestinationClient.Deposite(Amount);
			_RegisterTransferLog(Amount, DestinationClient, UserName);
			return true;
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "",0);
	}
	
	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		double TotalBalances = 0;
		for (clsBankClient Client : vClients)
		{
			TotalBalances += Client.AccountBalance;
		}
		return TotalBalances;
	}

	static vector <stTransferLogRecord> GetTransferlogList()
	{
		vector <stTransferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;

			stTransferLogRecord TransferLogRecord;
			while (getline(MyFile, Line))
			{
				TransferLogRecord = _ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferLogRecord);
			}
			MyFile.close();
		}
		return vTransferLogRecord;
	}
};

