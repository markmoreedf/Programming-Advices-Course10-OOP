#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class clsString
{
private:
    string _value;

public:

    clsString()  { _value = ""; }
    clsString(string s) { _value = s; }

    void SetValue(string s) { _value = s; }
    string GetValue() { return _value; }

    __declspec(property(get = GetValue, put = SetValue)) string value;

    //////////////////////////////////////////////////////////////////////
    static string UpperCaseTheFirstLetterOfEachWord(string s)
    {
        bool isFirstLetter = true;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ' && isFirstLetter)
                s[i] = toupper(s[i]);
            isFirstLetter = s[i] == ' ' ? true : false;
        }
        return s;
    }
    void UpperCaseTheFirstLetterOfEachWord()
    {
       _value = clsString::UpperCaseTheFirstLetterOfEachWord(_value);
    }


    static string LowerCaseTheFirstLetterOfEachWord(string s)
    {
        bool isFirstLetter = true;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ' && isFirstLetter)
                s[i] = tolower(s[i]);
            isFirstLetter = s[i] == ' ' ? true : false;
        }
        return s;
    }
    void  LowerCaseTheFirstLetterOfEachWord()
    {
        _value = clsString::LowerCaseTheFirstLetterOfEachWord(_value);
    }


    static string ToUpper(string s)
    {
        for (int i = 0; i < s.length(); i++)
            s[i] = toupper(s[i]);

        return s;
    }
    void ToUpper() 
    { 
        _value = clsString::ToUpper(_value);
    }


    static string ToLower(string s)
    {
        for (int i = 0; i < s.length(); i++)
            s[i] = tolower(s[i]);

        return s;
    }
    void ToLower()
    {
        _value = clsString::ToLower(_value);
    }


    static char InvertLetterCase(char c)
    {
        return isupper(c) ? tolower(c) : toupper(c);
    }


    static string InvertEveryLetterCase(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            s[i] = InvertLetterCase(s[i]);
        }

        return s;
    }
    void InvertEveryLetterCase()
    {
        _value = clsString::InvertEveryLetterCase(_value);
    }


    static int CountUpperCaseLetters(string s)
    {
        int upperCaseCount = 0;
        for (int i = 0; i < s.length(); i++)
        {
            upperCaseCount = isupper(s[i]) ? upperCaseCount + 1 : upperCaseCount;
        }
        return upperCaseCount;
    }
    int  CountUpperCaseLetters()
    {
        return clsString::CountUpperCaseLetters(_value);
    }


    static int CountLowerCaseLetters(string s)
    {
        int lowerCaseCount = 0;
        for (int i = 0; i < s.length(); i++)
        {
            lowerCaseCount = islower(s[i]) ? lowerCaseCount + 1 : lowerCaseCount;
        }
        return lowerCaseCount;
    }
    int  CountLowerCaseLetters()
    {
       return  clsString::CountLowerCaseLetters(_value);
    }


    enum enWhatCharToCount { CapitalLetter = 0, SmallLetter = 1, CapitalAndSmall = 2, Digit = 3, Symbol = 4, All = 5 };
    static int CountCharTypeInString(string s, enWhatCharToCount charType = enWhatCharToCount::All)
    {
        int charCount = 0;

        switch (charType)
        {
        case enWhatCharToCount::CapitalLetter:

            for (int i = 0; i < s.length(); i++)
                charCount = isupper(s[i]) ? charCount + 1 : charCount;
            break;

        case enWhatCharToCount::SmallLetter:

            for (int i = 0; i < s.length(); i++)
                charCount = islower(s[i]) ? charCount + 1 : charCount;
            break;

        case enWhatCharToCount::CapitalAndSmall:

            for (int i = 0; i < s.length(); i++)
                charCount = (islower(s[i]) || isupper(s[i])) ? charCount + 1 : charCount;
            break;

        case enWhatCharToCount::Digit:

            for (int i = 0; i < s.length(); i++)
                charCount = isdigit(s[i]) ? charCount + 1 : charCount;
            break;

        case enWhatCharToCount::Symbol:

            for (int i = 0; i < s.length(); i++)
                charCount = !(islower(s[i]) || isupper(s[i])) ? charCount + 1 : charCount;
            break;

        case enWhatCharToCount::All:

            charCount = s.length();
            break;
        }

        return charCount;
    }
    int CountCharTypeInString(enWhatCharToCount charType = enWhatCharToCount::All)
    {
        return clsString::CountCharTypeInString(_value, charType);
    }


    static int CountSpecificCharInString(string s, char charToCount, bool matchCase = true)
    {
        int charCount = 0;

        if (!matchCase)
        {
            charToCount = toupper(charToCount);
            s = ToUpper(s);
        }

        for (int i = 0; i < s.length(); i++)
            charCount = (s[i] == charToCount) ? charCount + 1 : charCount;

        return charCount;
    }
    int CountSpecificCharInString(char charToCount, bool matchCase = true)
    {
        return clsString::CountSpecificCharInString(_value, charToCount, matchCase);
    }


    static bool IsZVowel(char c)
    {
        c = tolower(c);

        return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
    }


    static int CountVowels(string s)
    {
        int vowelsCount = 0;

        s = ToLower(s);

        for (int i = 0; i < s.length(); i++)
            vowelsCount = ((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u')) ? vowelsCount + 1 : vowelsCount;

        return vowelsCount;
    }
    int CountVowels()
    {
       return  clsString::CountVowels(_value);
    }


    static void PrintAllVowelsInString(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (IsZVowel(s[i]))
                cout << setw(5) << s[i];
        }

        return;
    }
    void PrintAllVowelsInString()
    {
        clsString::PrintAllVowelsInString(_value);
    }


    static void PrintEachWordOnNewLine(string s)
    {
        string word, space = " ";
        short pos = 0;

        while ((pos = s.find(space)) != string::npos)
        {
            word = s.substr(0, pos);
            if (word != "")
            {
                cout << word << endl;
            }
            s.erase(0, pos + space.length());
        }

        if (s != "")
            cout << s << endl;


    }
    void PrintEachWordOnNewLine()
    {
        clsString::PrintEachWordOnNewLine(_value);
    }


    static short CountWordsInString(string s)
    {
        short wordCount = 0, pos = 0;
        string space = " ";

        while ((pos = s.find(space)) != string::npos)
        {
            if (s.substr(0, pos) != "")
                wordCount++;
            s.erase(0, pos + space.length());

        }

        if (s != "")
            wordCount++;

        return wordCount;
    }
    short CountWordsInString()
    {
        return clsString::CountWordsInString(_value);
    }


    static vector<string> Split(string s, string delimiter)
    {
        vector<string> vStringWords;
        string word;
        short pos = 0;

        while ((pos = s.find(delimiter)) != string::npos)
        {
            word = s.substr(0, pos);
            if (word != "")
            {
                vStringWords.push_back(word);
            }
            s.erase(0, pos + delimiter.length());
        }

        if (s != "")
            vStringWords.push_back(s);

        return vStringWords;
    }
    vector<string> Split(string delimiter)
    {
        return clsString::Split(_value, delimiter);
    }


    static string TrimLeft(const string& s) // Use const reference
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (!isspace(static_cast<unsigned char>(s[i]))) // Checks for space, tabs, etc.
            {
                return s.substr(i); // From i to the end
            }
        }
        return ""; // String was all whitespace
    }
    void TrimLeft()
    {
        _value = clsString::TrimLeft(_value);
    }


    static string TrimRight(const string& s)
    {
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (!isspace(static_cast<unsigned char>(s[i])))
            {
                return s.substr(0, i + 1);
            }
        }
        return ""; // String was all whitespace
    }
    void TrimRight()
    {
        _value = clsString::TrimRight(_value);
    }

 
    static string Trim(string& s)
    {
        return TrimLeft(TrimRight(s));
    }
    void Trim()
    {
        _value = clsString::Trim(_value);
    }
    

    static string JoinString(vector<string>& vStr, string delimiter)
    {
        string fullString;
        for (string& str : vStr) {
            fullString += str + delimiter;
        }


        return fullString.substr(0, fullString.length() - delimiter.length());
    }
    static string JoinString(const string str[], int size, const string& delimiter)
    {
        string fullString;
        for (int i = 0; i < size; ++i) {
            fullString += str[i] + delimiter;
        }

        return fullString.substr(0, fullString.length() - delimiter.length());
    }


    static string ReverseWords(string str, string delimiter)
    {
        vector<string> splittedString = Split(str, delimiter);
        vector<string>::iterator it = splittedString.end();
        string reversedString;
        while (it != splittedString.begin()) {
            it--;
            reversedString += *it + delimiter;
        }
        return reversedString.substr(0, reversedString.length() - delimiter.length());
    }
    void ReverseWords(string delimiter)
    {
        _value = clsString::ReverseWords(_value, delimiter);
    }


    static string ReplaceWord(string& str, string wordToReplace, string replaceTo, bool matchCase = true)
    {
        vector<string> splittedString = Split(str, " ");

        for (string& s : splittedString) {

            if (matchCase) {

                if (s == wordToReplace)
                    s = replaceTo;

            }
            else {

                wordToReplace = ToLower(wordToReplace);
                if (ToLower(s) == wordToReplace)
                    s = replaceTo;
            }

        }

        return JoinString(splittedString, " ");
    }
    void ReplaceWord(string wordToReplace, string replaceTo, bool matchCase = true)
    {
        _value = clsString::ReplaceWord(_value, wordToReplace, replaceTo, matchCase);
    }


    static string ReplaceWordInString(string &S1, string StringToReplace, string sRepalceTo)
    {
        short pos = S1.find(StringToReplace);
        while (pos != std::string::npos)
        {
            S1 = S1.replace(pos, StringToReplace.length(),
                sRepalceTo);
            pos = S1.find(StringToReplace);//find next
        }
        return S1;
    }
    void ReplaceWordInString(string StringToReplace, string sRepalceTo)
    {
        _value = clsString::ReplaceWordInString(_value, StringToReplace, sRepalceTo);
    }


    static string RemovePunctuation(string& str)
    {
        string strWithoutPunct = "";
        for (char& c : str)
        {
            if (!ispunct(c)) {
                strWithoutPunct += c;
            }
        }
        return strWithoutPunct;
    }
    void RemovePunctuation()
    {
        _value = clsString::RemovePunctuation(_value);
    }

};

