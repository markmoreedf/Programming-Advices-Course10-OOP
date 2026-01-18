#pragma once

#include <iostream>
#include <string>
#include <random>
#include <limits> // Required to find the min/max of the each datatype
#include <vector>
#include "MyInputLibrary.h";
#include "clsString.h";
#include "clsDate.h";

using namespace std;

class clsUtility
{
private:
    // --- ENCRYPTION KEY ---
    // We keep this private so only the class functions can access it.
    // You can change its value to any number you like (Typically 32-126).
    const static short _encryptionKey = 5;

    // --- THE ENGINE (The Brain of random functions) ---
    // We keep this outside so all functions can share the same "source" of randomness.
    static std::mt19937& _GetEngine()
    {
        static std::mt19937 gen(static_cast<unsigned int>(std::time(0)));
        return gen;
    }

public:

    enum enCharacterType { enSmallLetter, enCapitalLetter, enSpecialCharacter, enDigit, enMix };

    static bool IsOdd(int number)
    {
        return (number % 2) != 0;
    }
    static bool IsPrime(int n)
    {
        if (n == 2 || n == 3)
            return true;
        else
            for (int i = 2; i <= (n / 2); i++)
            {
                if (n % i == 0)
                    return false;
            }
        return true;
    }
    static bool IsPerfect(int n)
    {
        int SumOfTheDevisors = 0;
        for (int i = 1; i <= ((n / 2) + 1); i++)
        {
            if (n % i == 0)
                SumOfTheDevisors += i;
        }
        return  SumOfTheDevisors == n;
    }

    static int MyAbs(int number)
    {
        return number >= 0 ? number : -number;
    }
    static int MyFloor(float number)
    {
        return number >= 0 ? number : number - 1;
    }
    static int MyCeil(float number)
    {
        return number >= 0 ? int(number) == number ? number : int(number) + 1 : number;
    }
    static int MyRound(float number)
    {
        return number >= 0 ? int(number) + 0.5f <= number ? int(number) + 1 : int(number) /*<<< Pstv Ngtv >>>*/ : int(number) - 0.5f >= number ? int(number) - 1 : int(number);
    }
    static double MyPow(double base, int exponent)
    {
        if (exponent == 0) return 1.0;

        double result = 1.0;

        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }
        return result;
    }
    static float Mysqrt(float number)
    {
        if (number == 0) return 0;

        double x = number;
        double y = number / 2; // Initial guess

        while (x - y > 0.00001) {
            x = (x + y) / 2;
            y = number / x;
        }
        return x;

    }


    static bool DoesExcist(const vector <int> & vInts,  const int & member)
    {
        for (int startingPoint = 0; startingPoint < vInts.size(); startingPoint++)
        {
            if (vInts[startingPoint] == member)
                return true;
        }
        return false;
    } 
    static bool DoesExcist(const vector <float> & vFloats, const float & member)
    {
        for (int startingPoint = 0; startingPoint < vFloats.size(); startingPoint++)
        {
            if (vFloats[startingPoint] == member)
                return true;
        }
        return false;
    } 
    static bool DoesExcist(const vector <double> & vDoubles,  const double & member)
    {
        for (int startingPoint = 0; startingPoint < vDoubles.size(); startingPoint++)
        {
            if (vDoubles[startingPoint] == member)
                return true;
        }
        return false;
    } 
    static bool DoesExcist(const vector <string> & vStrings, const string & member)
    {
        for (int startingPoint = 0; startingPoint < vStrings.size(); startingPoint++)
        {
            if (vStrings[startingPoint] == member)
                return true;
        }
        return false;
    } 


    static int RandomNumber(int min, int max)
    {
        std::uniform_int_distribution<int> dis(min, max);
        return dis(_GetEngine());
    }
    static float RandomNumber(float min, float max)
    {
        std::uniform_real_distribution<float> dis(min, max);
        return dis(_GetEngine());
    }
    static double RandomNumber(double min, double max)
    {
        std::uniform_real_distribution<double> dis(min, max);
        return dis(_GetEngine());
    }

    static char RandomChar(enCharacterType charType)
    {
        short type = charType;
        if (type == enCharacterType::enMix)
            type = RandomNumber(0, 3);
        
        switch (type)
        {
        case  enCharacterType::enSmallLetter:         return char(RandomNumber(97, 122));
            // small letter     
            break;
        case  enCharacterType::enCapitalLetter:       return char(RandomNumber(65, 90));
            // capital letter               
            break;
        case  enCharacterType::enSpecialCharacter:    return char(RandomNumber(33, 47));
            // special character              
            break;
        case  enCharacterType::enDigit:                return char(RandomNumber(48, 57));
            // digit
            break;
        default:
            cout << "Error! try again\n";
            return '0';
            break;
        }

    }

    static string RandomWord(int length, enCharacterType charType)
    {
        string randomWord = "";
        for (int j = 0; j < length; j++)
        {
            randomWord += RandomChar(charType);
        }
        return randomWord;
    } 

    static clsString RandomWord_clsString(int length, enCharacterType charType)
    {
       return  clsString (RandomWord(length,charType));
    }


    static void Swap(int& x, int& y)
    {
        int temp;
        temp = x;
        x = y;
        y = temp;
    } 
    static void Swap(float& x, float& y)
    {
        float temp;
        temp = x;
        x = y;
        y = temp;
    }  
    static void Swap(double& x, double& y)
    {
        double temp;
        temp = x;
        x = y;
        y = temp;
    }  
    static void Swap(char& x, char& y)
    {
        char temp;
        temp = x;
        x = y;
        y = temp;
    }  
    static void Swap(string& x, string& y)
    {
        string temp;
        temp = x;
        x = y;
        y = temp;
    }  
    static void Swap(clsString & x, clsString & y)
    {
        clsString temp;
        temp = x;
        x = y;
        y = temp;
    } 
    static void Swap(clsDate & x, clsDate & y)
    {
        clsDate::SwapDates(x, y);
    }


    static void Shuffle(vector<int> & vInts)
    {
        short length = vInts.size();
        for (short i = 0; i < vInts.size(); i++)
        {
            Swap(vInts[RandomNumber(0, length - 1)], vInts[RandomNumber(0, length - 1)]);
        }
    }
    static void Shuffle(vector<float> & vFloats)
    {
        short length = vFloats.size();
        for (short i = 0; i < length; i++)
        {
            Swap(vFloats[RandomNumber(0, length - 1)], vFloats[RandomNumber(0, length - 1)]);
        }   
    }    
    static void Shuffle(vector<double> & vDoubles)
    {
        short length = vDoubles.size();
        for (short i = 0; i < length; i++)
        {
            Swap(vDoubles[RandomNumber(0, length - 1)], vDoubles[RandomNumber(0, length - 1)]);
        }   
    } 
    static void Shuffle(vector<char> & vChars)
    {
        short length = vChars.size();
        for (short i = 0; i < length; i++)
        {
            Swap(vChars[RandomNumber(0, length - 1)], vChars[RandomNumber(0, length - 1)]);
        }   
    }
    static void Shuffle(vector<string> & vStrings)
    {
        short length = vStrings.size();
        for (short i = 0; i < length; i++)
        {
            Swap(vStrings[RandomNumber(0, length - 1)], vStrings[RandomNumber(0, length - 1)]);
        }   
    }  
    static void Shuffle(vector<clsString> & vClsString)
    {
        short length = vClsString.size();
        for (short i = 0; i < length; i++)
        {
            Swap(vClsString[RandomNumber(0, length - 1)], vClsString[RandomNumber(0, length - 1)]);
        }   
    }
    static void Shuffle(vector<clsDate> & vClsDates)
    {
        short length = vClsDates.size();
        for (short i = 0; i < length; i++)
        {
            Swap(vClsDates[RandomNumber(0, length - 1)], vClsDates[RandomNumber(0, length - 1)]);
        }   
    }


    static string GenerateKey(enCharacterType charType)
    {
        string key = "";
        for (int i = 0; i < 4; i++)
        {
            key += RandomWord(4, charType);
            key += '-';
        }
        key.pop_back();
        return key;
    }
    static clsString GenerateKey_clsString(enCharacterType charType)
    {
        string key = "";
        for (int i = 0; i < 4; i++)
        {
            key += RandomWord(4, charType);
            key += '-';
        }
        key.pop_back();
        clsString clsStrKey(key);
        return clsStrKey;
    }

    static void FillVectorWithRandomKeys(vector<string> &vStrings, const int & numberOfKeys, const enCharacterType & charType)
    {
        for (int i = 0; i < numberOfKeys; i++)
        {
            vStrings.push_back(GenerateKey(charType));
        }
    }
    static void FillVectorWithRandomKeys(vector<clsString> &vStrings,const int &numberOfKeys, const enCharacterType & charType)
    {
        for (int i = 0; i < numberOfKeys; i++)
        {
            vStrings.push_back(GenerateKey(charType));
        }
    }


    static string EncryptText(string str, const short& encryptionKey)
    {
        for (int i = 0; i < str.length(); i++)
        {
            str[i] = char(int(str[i]) + encryptionKey);
        }
        return str;
    }
    static string EncryptText(string str)
    {
        return EncryptText(str, _encryptionKey);
    }
    static clsString EncryptText(clsString str, const short& encryptionKey)
    {
        for (int i = 0; i < str.value.length(); i++)
        {
            str.value[i] = char(int(str.value[i]) + encryptionKey);
        }
        return str;
    }
    static clsString EncryptText(clsString str)
    {
        return EncryptText(str, _encryptionKey);
    }


    static string DecryptText(string str, const short& decryptionKey)
    {
        for (int i = 0; i < str.length(); i++)
        {
            str[i] = char(int(str[i]) - decryptionKey);
        }
        return str;
    }
    static string DecryptText(string str)
    {
        return DecryptText(str, _encryptionKey);
    }
    static clsString DecryptText(clsString str, const short & decryptionKey)
    {
        for (int i = 0; i < str.value.length(); i++)
        {
            str.value[i] = char(int(str.value[i]) - decryptionKey);
        }
        return str;
    }
    static clsString DecryptText(clsString str)
    {
        return DecryptText(str, _encryptionKey);
    }


};

