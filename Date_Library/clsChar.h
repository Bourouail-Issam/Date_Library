#pragma once
#include <iostream>
using namespace std;

class clsChar
{
private:
	char _Value;

public:
	clsChar() {
		_Value = ' ';
	}
	clsChar(char Value) {
		_Value = Value;
	}
	//Get And Set Properties For _Value
	void SetChar(char Value) {
		_Value = Value;
	}
	char GetChar() {
		return _Value;
	}
	__declspec(property(get = GetChar, put = SetChar)) char Value;

	// change To UpperCase
	static char ToUpperCase(char Letter) {
		if ((int)Letter >= 97)
			return char((int)Letter - 32);
		return char(Letter);
	}
	char ToUpperCase() {
		return (_Value = ToUpperCase(_Value));
	}
	// Change to LowerCase
	static char ToLowerCase(char& Letter) {
		if ((int)Letter <= 90)
			return char((int)Letter + 32);
		return char(Letter);
	}
	char ToLowerCase() {
		return (_Value = ToLowerCase(_Value));
	}
	// Inverting Character Letter 
	static char InvertLetterCase(char Letter) {
		return isupper(Letter) ? ToLowerCase(Letter) : ToUpperCase(Letter);
	}
	char InvertLetterCase() {
		return (_Value = InvertLetterCase(_Value));
	}
	//found Vowel Character a,e,i,o,u
	static bool IsVowel(char ch1) {
		ch1 = ToLowerCase(ch1);
		return((ch1 == 'a') || (ch1 == 'e') || (ch1 == 'i') || (ch1 == 'o') || (ch1 == 'u'));
	}
	bool IsVowel() {
		return IsVowel(_Value);
	}
};

