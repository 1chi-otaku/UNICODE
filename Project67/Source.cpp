#include <iostream>
#include <tchar.h>
#define _UNICODE
using namespace std;

void strspacetotab(_TCHAR* str);
void strprintstats(const _TCHAR* str);
void strcalculateword(const _TCHAR* str);
//5
bool Ispalindrom(const _TCHAR* str);
void strremove(_TCHAR*& str, int position);
void strremovesymbol(_TCHAR*& str, _TCHAR symbol);
void straddsymbol(_TCHAR*&, _TCHAR symbol, int position);

int main() {
	int size = 27;
	_TCHAR* str = new _TCHAR[size]{ 'H','e','1','1','o',' ','W','0','r','l','d','!',' ','a','n','d',' ', 'U','n','i','v','e','r','s','e','!','\0'};
	wcout << str << endl;
	strspacetotab(str);
	wcout << str << endl;
	strprintstats(str);
	strcalculateword(str);
	if (Ispalindrom(str))
		cout << "The word is palindorm " << endl;
	else
		cout << "The word is not a palindrom!" << endl;
	strremove(str, 0);
	cout << endl;
	wcout << str;
	strremovesymbol(str, '1');
	cout << endl;
	wcout << str;
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		straddsymbol(str, '0', 0);
		cout << endl;
		wcout << str;
	}
	strremovesymbol(str, '0');
	cout << endl;
	wcout << str;
	
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
