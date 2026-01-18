// This is a test code for the clsUtility.h class 

#include <iostream>
#include "clsUtility.h";

using namespace std;

void PrintHeader(string title)
{
    cout << "\n==================================================" << endl;
    cout << " >>> " << title << endl;
    cout << "==================================================" << endl;
}

int main()
{
    // Setting precision for float/double tests
    cout << fixed << setprecision(5);

    /* 
    ---------------------------------------------------
       TEST 1: MATH BOUNDARY SENSITIVITY
       Checks if your Math functions handle 0, negative, and large numbers.
    ---------------------------------------------------
    */
    PrintHeader("MATH & LOGIC STRESS TEST");

    cout << "Prime Test (Boundary): 2 is " << (clsUtility::IsPrime(2) ? "Prime" : "Not Prime") << endl;
    cout << "Prime Test (Large): 97 is " << (clsUtility::IsPrime(97) ? "Prime" : "Not Prime") << endl;

    cout << "Floor Test (Negative): -2.1 -> " << clsUtility::MyFloor(-2.1f) << " (Expected: -3)" << endl;
    cout << "Ceil Test (Negative): -2.9 -> " << clsUtility::MyCeil(-2.9f) << " (Expected: -2)" << endl;

    cout << "Power Test (Zero Exp): 5^0 = " << clsUtility::MyPow(5, 0) << endl;
    cout << "Sqrt Test (Edge): Sqrt(0.0001) = " << clsUtility::Mysqrt(0.0001f) << endl;


    /* 
    ---------------------------------------------------
      TEST 2: RANDOM DISTRIBUTION UNIFORMITY
      Generates 10,000 numbers to see if 'MixAll' hits every range.
    --------------------------------------------------- 
    */
    PrintHeader("RANDOMNESS UNIFORMITY TEST");
    int smallCount = 0, capCount = 0, digitCount = 0, specCount = 0;

    for (int i = 0; i < 10000; i++) {
        char c = clsUtility::RandomChar(clsUtility::enMix);
        if (c >= 'a' && c <= 'z') smallCount++;
        else if (c >= 'A' && c <= 'Z') capCount++;
        else if (c >= '0' && c <= '9') digitCount++;
        else specCount++;
    }

    cout << "Out of 10,000 Random Mix Characters:" << endl;
    cout << " - Small Letters: " << smallCount << endl;
    cout << " - Capital Letters: " << capCount << endl;
    cout << " - Digits: " << digitCount <<  endl;
    cout << " - Special Chars: " << specCount << endl;


    /* 
    ---------------------------------------------------
       TEST 3: VECTOR SHUFFLE & EXISTENCE
       Testing if the reference passing works (Original vector must change).
    --------------------------------------------------- 
    */
    PrintHeader("VECTOR & MEMORY TEST");
    vector<string> names = { "Ali", "Ahmed", "Sara", "Zain", "Omar" };
    vector<string> originalNames = names;

    cout << "Original: Ali, Ahmed, Sara, Zain, Omar" << endl;
    clsUtility::Shuffle(names);

    cout << "Shuffled: ";
    for (string & s : names) cout << s << ", ";
    cout << "\nStatus: " << (names == originalNames ? "FAILED (Did not shuffle)" : "PASSED (Shuffled)") << endl;

    cout << "Existence Check: 'Sara' exists? " << (clsUtility::DoesExcist(names, string("Sara")) ? "Yes" : "No") << endl;
    cout << "Existence Check: 'Ghost' exists? " << (clsUtility::DoesExcist(names, string("Ghost")) ? "Yes" : "No") << endl;


    /* 
    ---------------------------------------------------
       TEST 4: ENCRYPTION STRENGTH & INTEGRITY
       This is the 'Round-Trip' test.
    --------------------------------------------------- 
    */
    PrintHeader("ENCRYPTION INTEGRITY TEST");
    string secret = "C++_is_Awesome_2026! @#$";
    short customKey = 15;

    string encDefault = clsUtility::EncryptText(secret);
    string decDefault = clsUtility::DecryptText(encDefault);

    string encCustom = clsUtility::EncryptText(secret, customKey);
    string decCustom = clsUtility::DecryptText(encCustom, customKey);

    cout << "Round Trip (Default Key): " << (secret == decDefault ? "SUCCESS " : "CORRUPT ") << endl;
    cout << "Round Trip (Custom Key):  " << (secret == decCustom ? "SUCCESS " : "CORRUPT ") << endl;

    if (encDefault == encCustom) {
        cout << "CRITICAL ERROR: Default and Custom encryptions are the same!" << endl;
    }


    /* ---------------------------------------------------
       TEST 5: LARGE KEY GENERATION
       Verifying the 'pop_back' logic and key formatting.
    --------------------------------------------------- */
    PrintHeader("KEY GENERATION FORMATTING");
    string key = clsUtility::GenerateKey(clsUtility::enMix);
    cout << "Generated Key: " << key << endl;
    cout << "Key Length: " << key.length() << " (Expected 19 characters: XXXX-XXXX-XXXX-XXXX)" << endl;

    if (key.back() == '-') cout << "ERROR: Key ends with a dash! Error in pop_back logic." << endl;
    else cout << "Key Format: Correct " << endl;

    cout << "\n==================================================" << endl;
    cout << " >>> STRESS TEST COMPLETE" << endl;
    cout << "==================================================" << endl;

    return 0;
}
