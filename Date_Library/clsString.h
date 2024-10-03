#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clsChar.h"

using namespace std;

class clsString :private clsChar
{
private:
	string _Value;

public:
	// Consturctor 
	clsString() {
		_Value = "";
	};
	clsString(string Value) {
		_Value = Value;
	}

	// Get And Set Properties For _Value
	void SetValue(string Value) {
		_Value = Value;
	}
	string GetValue() {
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;
	// length of string
	static short Length(string S1)
	{
		short count = 0;
		for (char Letter : S1)
			++count;
		return count;
	};
	short Length()
	{
		return Length(_Value);
	};

	// Count Numbers of words in string
	static short CountWords(string S1)
	{
		string delim = " "; // delimiter  
		short Counter = 0;
		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			if (sWord != "")
			{
				Counter++;
			}

			//erase() until positon and move to next word.
			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			Counter++; // it counts the last word of the string.
		}

		return Counter;

	}
	short CountWords()
	{
		return CountWords(_Value);
	};

	// Change the first Letter of each word in the string To UpperCase
	static string  UpperFirstLetterOfEachWord(string paragraph) {
		bool isFirstLetter = true;
		for (int i = 0; i < paragraph.length(); i++)
		{
			if (paragraph[i] != ' ' && isFirstLetter)
				paragraph[i] = ToUpperCase(paragraph[i]);

			isFirstLetter = paragraph[i] == ' ' ? true : false;
		};
		return paragraph;
	}
	void UpperFirstLetterOfEachWord() {
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	// Change the first Letter of each word in the string to LowerCase
	static string  LowerFirstLetterOfEachWord(string paragraph) {
		bool isFirstLetter = true;
		for (int i = 0; i < paragraph.length(); i++)
		{
			if (paragraph[i] != ' ' && isFirstLetter)
				paragraph[i] = ToLowerCase(paragraph[i]);

			isFirstLetter = paragraph[i] == ' ' ? true : false;
		};
		return paragraph;
	}
	void LowerFirstLetterOfEachWord() {
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	// change All word in the to UpperCase 
	static string  UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
			S1[i] = ToUpperCase(S1[i]);

		return S1;
	}
	void  UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	// change All word in the to LowerCase 
	static string  LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
			S1[i] = ToLowerCase(S1[i]);

		return S1;
	}
	void  LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	// change word in the string if OpperCaseto LowerCase and if LowerCase change to upperCase
	static string  InvertAllLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}
	void  InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	//count all Letters and small Letters and Capital letters
	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
			return Length(S1);

		short Counter = 0;

		for (short i = 0; i < Length(S1); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;

			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;
		}
		return Counter;
	}

	//count Capital letters
	static short  CountCapitalLetters(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (ToUpperCase(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short  CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	//count all Letters and small Letters and Capital letters
	static short  CountSmallLetters(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (ToLowerCase(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short  CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	//Count Specific Letter in the string
	static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 0; i < Length(S1); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
			{
				if (ToUpperCase(S1[i]) == ToUpperCase(Letter))
					Counter++;
			}
		}
		return Counter;
	}
	short  CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	// count numbres Letters vowels in the string
	static short  CountVowels(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < Length(S1); i++)
		{
			if (IsVowel(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short  CountVowels()
	{
		return CountVowels(_Value);
	}

	// split string to vector
	static vector<string> Split(string S1, string Delim)
	{
		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;
	}
	vector <string> Split(string Delim) {
		return (Split(_Value, Delim));
	}

	// Trim left 
	static string TrimLeft(string S1)
	{
		for (short i = 0; i < Length(S1); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, Length(S1) - i);
			}
		}
		return "";
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	//Trim rigth
	static string TrimRight(string S1)
	{
		for (short i = Length(S1) - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	//trim all
	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}

	//Joind vector string to string
	static string JoinString(vector<string> vString, string Delim)
	{
		string S1 = "";

		for (string& s : vString)
			S1 += s + Delim;

		return S1.substr(0, Length(S1) - Length(Delim));
	}

	//Joind Array string to string
	static string JoinString(string arrString[], short Length, string Delim)
	{
		string S1 = "";

		for (short i = 0; i < Length; i++)
			S1 += arrString[i] + Delim;

		return S1.substr(0, S1.length() - Delim.length());
	}
	//Reverse Words InString
	static string ReverseWordsInString(string S1)
	{
		vector<string> vString;
		string S2 = "";

		vString = Split(S1, " ");

		// declare iterator
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		S2 = S2.substr(0, S2.length() - 1); //remove last space.

		return S2;
	}
	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	//Replace Word
	static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{
		vector<string> vString = Split(S1, " ");

		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
				{
					s = sRepalceTo;
				}
			}
		}
		return JoinString(vString, " ");
	}
	string ReplaceWord(string StringToReplace, string sRepalceTo)
	{
		return ReplaceWord(_Value, StringToReplace, sRepalceTo);
	}

	// Remove all spécifique caratctere in string (?!#@......)
	static string RemovePunctuations(string S1)
	{
		string S2 = "";

		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
				S2 += S1[i];
		}
		return S2;
	}
	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}
};

