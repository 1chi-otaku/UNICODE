#include <iostream>
#include <tchar.h>
#define _UNICODE
using namespace std;

void strspacetotab(_TCHAR* str); //Replaces spaces in a string with \t
void strprintstats(const _TCHAR* str); //Prints the static of the word.
void strcalculateword(const _TCHAR* str); //Counts the number of words
void countthevowels();						//Counts the wovel in russian text. Keyboard imput.
bool Ispalindrom(const _TCHAR* str);   //Returns true if the word is palindrom.
void strremove(_TCHAR*& str, int position); //Removes a symbol from the respective position.
void strremovesymbol(_TCHAR*& str, _TCHAR symbol); //Removes the respective symbol from the string completely.
void straddsymbol(_TCHAR*&, _TCHAR symbol, int position); //Adds a symbol to the respective position.

int main() {
	setlocale(LC_ALL, "RUS");
	int size = 32;
	_TCHAR* str = new _TCHAR[size]{ 'H','e','1','1','o',' ','W','0','r','l','d','!',' ','a','n','d',' ', 'U','n','i','v','e','r','s','e','!'};
	wcout << str << endl;
	strspacetotab(str);
	wcout << str << endl;
	strprintstats(str);
	strcalculateword(str);
	if (Ispalindrom(str))
		wcout << "The word is palindorm " << endl;
	else
		wcout << "The word is not a palindrom!" << endl;
	strremove(str, 0);
	wcout << endl;
	wcout << str;
	strremovesymbol(str, '1');
	wcout << endl;
	wcout << str;
	wcout << endl;
	for (int i = 0; i < 10; i++)
	{
		straddsymbol(str, '0', 0);
		wcout << endl;
		wcout << str;
	}
	strremovesymbol(str, '0');
	wcout << endl;
	wcout << str;
	
	countthevowels();

	return 0;
}

void strspacetotab(_TCHAR* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ') {
			str[i] = '\t';
		}
	}
}
void strprintstats(const _TCHAR* str)
{
	int letters = 0;
	int figures = 0;
	int other = 0;

	for (int i = 0;str[i] != '\0'; i++)
	{
		if (int(str[i]) >= 65 && int(str[i] <= 90) || int(str[i]) >= 97 && int(str[i]) <= 122) {
			letters++;
		}
		else if (int(str[i]) >= 48 && int(str[i]) <= 57) {
			figures++;
		}
		else {
			other++;
		}
	}
	cout << "Letters - " << letters << endl;
	cout << "Figures - " << figures << endl;
	cout << "Other - " << other << endl;

}
void strcalculateword(const _TCHAR* str)
{
	unsigned short words = 1;
	int i = 0;
	bool prevspace = false;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
			prevspace = true;
		}
		else {
			if (prevspace) {
				words++;
			}
			prevspace = false;
		}
		i++;
	}
	

	cout << "Words - " << words << endl;
}
void countthevowels()
{
	int wovel_count = 0;
	_TCHAR wovel[22] = _TEXT("аяуюоеёэиыАЯУЮОЕЁЭИЫ");
	wstring lol;
	wcout << "Enter the text: " << endl;
	wcin >> lol;

	for (int i = 0; i < lol.size(); i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if (lol[i] == wovel[j]) {
				wovel_count++;
				break;
			}
		}
	}

	wcout << "Wovel - " << wovel_count << endl;


}
bool Ispalindrom(const _TCHAR* str)
{
	int len = wcslen(str);
	for (int i = 0; i < len / 2; ++i)
	{
		if (str[i] != str[len - i - 1])
		{
			return false;
		}
	}
	return true;
}
void strremove(_TCHAR*& str, int position)
{
	int size = wcslen(str);

	if (size < position)
		return;

	_TCHAR* temp = new _TCHAR[size];
	for (int i = 0, j = 0; i < size; ++i, j++)
	{
		if (i != position)
			temp[j] = str[i];
		else
			--j;
	}

	temp[size - 1] = '\0';
	delete[] str;
	str = temp;
}
void strremovesymbol(_TCHAR*& str, _TCHAR symbol)
{
	int size = wcslen(str);
	int i = 0;
	int symbols_to_delete = 0;
	while (str[i] != '\0')
	{
		if (str[i] == symbol) {
			symbols_to_delete++;
		}
		i++;
	}
	if (symbols_to_delete == 0) {
		return;
	}

	_TCHAR* temp = new _TCHAR[(size+1) - symbols_to_delete];
	for (int i = 0, j = 0; i < size; ++i, j++)
	{
		if (str[i] != symbol)
			temp[j] = str[i];
		else
			--j;
	}

	temp[size - symbols_to_delete] = '\0';
	delete[] str;
	str = temp;
}
void straddsymbol(_TCHAR*& str, _TCHAR symbol, int position)
{
	int size = wcslen(str);

	if (size < position)
		return;

	bool isEntered = false;
	_TCHAR* temp = new _TCHAR[size+2];
	for (int i = 0, j = 0; i < size; ++i, j++)
	{
		if (i == position && isEntered == false) {
			temp[j] = symbol;
			isEntered = true;
			i--;
		}
		else {
			temp[j] = str[i];
		}

	}
	temp[size + 1] = '\0';
	delete[] str;
	str = temp;
}
