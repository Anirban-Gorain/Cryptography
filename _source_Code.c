// A simple message encryption.
/*
Actual motive of this program is, This poogram take a data from user data can be any essential any information like password  or 
any message after take data program take a key and perform bitwise "XOR" between  user's data and key after processed encryption
wich data genrated this data store on a file in a another format, When user neaded to actual strcture of user's data user will give there
after encryption data and key then after a minor second user will give his actual data.
E.G)
Encryption time ---
Actual data of user is : United state
Key: 123lk
After encryption : aert4(23ji%^
Decryption time ---
After encryption : aert4(23ji%^
Key: 123lk
After decryotion : aert4(23ji%^
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
// Function declartion section.
_encryptino_Genrator(char *, char *);
_put_Encryption_Data_On_File(char *);
_decryption_Genrator(void);
_key_Verificataion_And_Validation(char *);
int main(void)
{
	// Variable section.
	char _user_Choice;
	printf("Enter your choice \'E\' for encryption or \'D\' decryption:");
	fflush(stdin);
	scanf("%c", &_user_Choice);
	if (_user_Choice == 'E' || _user_Choice == 'e')
	{
		// This downward arrays take encryption data from user.
		char _encryption_Data[1000] = {'~'};
		char _key[20] = {'~'};
		printf("\nEnter your message wich you want to encrypt:");
		fflush(stdin);
		gets(_encryption_Data);
		printf("\nEnter your key wich, You must be remember your key after encryption outherwise you do't decrypt your data:");
		fflush(stdin);
		gets(_key);
		// Key veryfication.
		_key_Verificataion_And_Validation(_key);
		// Call enc genrator.
		_encryptino_Genrator(_key, _encryption_Data);
	}
	else if (_user_Choice == 'D' || _user_Choice == 'd')
	{
		// Decryption section.
		_decryption_Genrator();
	}
	else
	{
		printf("\n\'%c\', It is wrong input an wrong value, You should read caerfully message then enter a proper keyword.", _user_Choice);
		getch();
	}
	return 0;
}
// Function defination.
int _encryptino_Genrator(char *_key, char *_encryption_Data)
{
	// Variable section.
	int _access_Key_Loop = 0;
	int _access_Encryption_Data_Loop = 0;
	char _after_Encryptino_Your_Data[1000] = {'~'};
	while (*(_encryption_Data + _access_Encryption_Data_Loop) != '\0')
	{
		_after_Encryptino_Your_Data[_access_Encryption_Data_Loop] = *(_encryption_Data + _access_Encryption_Data_Loop);
		while (*(_key + _access_Key_Loop) != '\0')
		{
			_after_Encryptino_Your_Data[_access_Encryption_Data_Loop] = _after_Encryptino_Your_Data[_access_Encryption_Data_Loop] ^ _key[_access_Key_Loop];
			_access_Key_Loop++;
		}
		_access_Key_Loop = 0;
		_access_Encryption_Data_Loop++;
	}
	printf("\nAfter encryption your data is, You must be remember your key:%s", _after_Encryptino_Your_Data);
	_put_Encryption_Data_On_File(_after_Encryptino_Your_Data);
	getch();
	return 0;
}
int _put_Encryption_Data_On_File(char *_access_After_Encryption_Data)
{
	int _loop = 0;
	FILE *_file_Pointer = fopen("Encryption_Data.txt", "w");
	if (_file_Pointer == NULL)
	{
		printf("\nFile not found, Coppy data from screen and use, Or make a file \'Encryption_Data.txt\' on over there where have this software.");
	}
	while (*(_access_After_Encryption_Data + _loop) != '\0')
	{
		fputc(*(_access_After_Encryption_Data + _loop), _file_Pointer);
		_loop++;
	}
	return 0;
}
int _decryption_Genrator(void)
{
	// Take a choice for user can want to decrypt data from file or user enter data manualy.
	char _user_Choice;
	printf("\nEnter a choice where you want to decrypt your data if \'FILE\' then press \'F\' if you enetr encrypted data \'MANUALY\' then press \'M\'");
	fflush(stdin);
	scanf("%c", &_user_Choice);
	if (_user_Choice == 'F' || _user_Choice == 'f')
	{
		// Varibale section.
		char _key[20] = {'~'};
		int _loop = 0;
		char _store_File_data_Par_Time = '~';
		char _store_Decrypt_Array[1000] = {'~'};
		int _printer_And_Assigner = 0;
		fflush(stdin);
		FILE *_file_Pointer = fopen("Encryption_Data.txt", "r");
		if (_file_Pointer == NULL)
		{
			printf("\nFile not found, Coppy data from screen and use, Or make a file \'Encryption_Data.txt\' on over there where have this software.");
			getch();
		}
		printf("\nEnter you key:");
		fflush(stdin);
		gets(_key);
		_key_Verificataion_And_Validation(_key);
		while (!(feof(_file_Pointer)))
		{
			_store_File_data_Par_Time = fgetc(_file_Pointer);
			while (_key[_loop] != '\0')
			{
				_store_File_data_Par_Time = _store_File_data_Par_Time ^ _key[_loop];
				_loop++;
			}
			_loop = 0;
			_store_Decrypt_Array[_printer_And_Assigner] = _store_File_data_Par_Time;
			_printer_And_Assigner++;
		}
		_printer_And_Assigner = 0;
		while (_store_Decrypt_Array[_printer_And_Assigner] != '\0' && _store_Decrypt_Array[_printer_And_Assigner + 1] != '\0')
		{
			printf("%c", _store_Decrypt_Array[_printer_And_Assigner]);
			_printer_And_Assigner++;
		}
	}
	else if (_user_Choice == 'M' || _user_Choice == 'm')
	{
		char _key[20] ;
		char _user_Encrypted_Value[1000] ;
		int _printer_And_Index = 0;
		int _loop = 0;
		printf("\nEnter you key:");
		fflush(stdin);
		gets(_key);
		printf("\nEnter you key encrypted data:");
		fflush(stdin);
		gets(_user_Encrypted_Value);
		// printf("%s", _user_Encrypted_Value);
		while (_user_Encrypted_Value[_printer_And_Index] != '\0')
		{
			
			while (_key[_loop] != '\0')
			{
				_user_Encrypted_Value[_printer_And_Index] = _user_Encrypted_Value[_printer_And_Index] ^ _key[_loop];
				_loop++;
			}
			_loop = 0;
			_printer_And_Index++;
		}
		_printer_And_Index = 0;
		// printf("%s", _store_Decrypt_Array);
		while (_user_Encrypted_Value[_printer_And_Index] != '\0')
		{
			printf("%c", _user_Encrypted_Value[_printer_And_Index]);
			_printer_And_Index++;
		}
	}
	else
	{
		printf("Yout enter a wrong value, Read every message caerfully outherwise  you can lost your data.");
		Beep(1000, 900);
		getch();
	}

	return 0;
}
int _key_Verificataion_And_Validation(char *_access_Key)
{
	// Variable section.
	int _loop_For_Assign_Source_Key_To_Local_Key = 0;
	static char _local_Key[20] = {'~'};
	char _veryfiction_Key[20];
	bool _condition_Decision = true;
	static int _count_Maximum_Time = 0;
	// Here assign value of actual key on local key.
	if (_count_Maximum_Time == 0)
	{
		while (*(_access_Key + _loop_For_Assign_Source_Key_To_Local_Key) != '\0')
		{
			_local_Key[_loop_For_Assign_Source_Key_To_Local_Key] = *(_access_Key + _loop_For_Assign_Source_Key_To_Local_Key);
			_loop_For_Assign_Source_Key_To_Local_Key++;
		}
	}
	// Take  veryfiction key to user.
	printf("\nEnter you key one more time for veryfiction:");
	fflush(stdin);
	gets(_veryfiction_Key);
	// Doing veryfiction.
	if (strcmp(_local_Key, _veryfiction_Key) == 0)
	{
		_condition_Decision = true;
	}
	else
	{
		// String uneqal.
		_condition_Decision = false;
		if (_count_Maximum_Time == 2)
		{
			printf("\nYou Cross maximum time of attempt");
			exit(1);
		}
		printf("\n\nveryfiction unsucessfull, Because veryfiction time your entered key is wrong.");
		_count_Maximum_Time++;
		_key_Verificataion_And_Validation(_local_Key);
	}

	// If the string is eqal.
	if (_condition_Decision == true)
	{
		printf("\nVeryficiton sucessfully done.");
	}
	return 0;
}