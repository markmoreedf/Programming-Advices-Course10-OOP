#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace MyInputLibrary
{
    bool YesNo()
    {
        cout << endl << "Enter Y or N: ";
        char yesOrNo;
        cin.clear();
        cin >> yesOrNo;
        yesOrNo = toupper(yesOrNo);

        while (yesOrNo != 'Y' && yesOrNo != 'N') {
            cout << "Please enter Y or N only  -->  ";
            cin.clear();
            cin.ignore();
            cin >> yesOrNo;
            yesOrNo = toupper(yesOrNo);
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return yesOrNo == 'Y' ? true : false;
    }
    bool YesNo(string msg)
    {
        cout << endl << msg << " [Enter Y or N]  -->  ";
        char yesOrNo;
        cin.clear();
        cin >> yesOrNo;
        yesOrNo = toupper(yesOrNo);

        while (yesOrNo != 'Y' && yesOrNo != 'N') {
            cout << "Please enter Y or N only:\t ";
            cin >> yesOrNo;
            yesOrNo = toupper(yesOrNo);
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return yesOrNo == 'Y' ? true : false;
    }


    // Reading ints, flaots and doubles
    int ReadInt()
    {
        int n;
        cout << "Please Enter an integer number: ";
        cin >> n;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Input please enter a valid number \n";
            cin >> n;
        }
        
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }
    int ReadInt(string msg)
    {
        int n;
        cout << msg;
        cin >> n;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Input please enter a valid number \n";

            cin >> n;
        }
        
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }

    float ReadFloat()
    {
        float n;
        cout << "Please enter a Floating-Point number: ";
        cin >> n;

        while(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Input please enter a valid number \n";
            cin >> n;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }
    float ReadFloat(string msg)
    {
        float n;
        cout << msg;
        cin >> n;

        while(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Input please enter a valid number \n";
            cin >> n;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }


    double ReadDouble()
    {
        double n;
        cout << "Please enter a Floating-Point number: ";
        cin >> n;

        while(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Input please enter a valid number \n";
            cin >> n;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }
    double ReadDouble(string msg)
    {
        double n;
        cout << msg;
        cin >> n;

        while(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Input please enter a valid number \n";
            cin >> n;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }
///////

    // Reading Positive and Negative Integers 
    int ReadPositiveInt()
    {
        int n;
        do {
            cout << "Please Enter a positive number: ";
            cin >> n;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid Input please enter a valid number \n";
                cin >> n;
            }

        } while (n < 0);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }
    int ReadPositiveInt(string msg)
    {
        int n;
        do {
            cout << msg;
            cin >> n;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid Input please enter a valid number \n";
                cin >> n;
            }

        } while (n < 0);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }

    int ReadNegativeInt()
    {
        int n;
        do {
            cout << "Please Enter a Negative number: ";
            cin >> n;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid Input please enter a valid number \n";
                cin >> n;
            }

        } while (n > 0);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }
    int ReadNegativeInt(string msg)
    {
        int n;
        do {
            cout << msg;
            cin >> n;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid Input please enter a valid number \n";
                cin >> n;
            }

        } while (n > 0);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }
///////
 
    // Reading Positive and Negative Floats 
    float ReadPositiveFloat()
    {
        float n;
        do {
            cout << "Please enter a Positive Floating-Point number: ";
            cin >> n;
            cin.clear();

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid Input please enter a valid number \n";
                cin >> n;
            }

        } while (n < 0);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }
    float ReadPositiveFloat(string msg)
    {
        float n;
        do {
            cout << msg;
            cin >> n;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid Input please enter a valid number \n";
                cin >> n;
            }

        } while (n < 0);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }

    float ReadNegativeFloat()
    {
        float n;
        do {
            cout << "Please enter a Negative Floating-Point number: ";
            cin >> n;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid Input please enter a valid number \n";
                cin >> n;
            }

        } while (n > 0);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }
    float ReadNegativeFloat(string msg)
    {
        float n;
        do {
            cout << msg;
            cin >> n;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid Input please enter a valid number \n";
                cin >> n;
            }

        } while (n > 0);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }
///////

 
    // Reading Positive and Negative Doubles 
    double ReadPositiveDouble()
    {
        double n;
        do {
            cout << "Please enter a positive Floating-Point number: ";
            cin >> n;
            cin.clear();

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid Input please enter a valid number \n";
                cin >> n;
            }

        } while (n < 0);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }
    double ReadPositiveDouble(string msg)
    {
        double n;
        do {
            cout << msg;
            cin >> n;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid Input please enter a valid number \n";
                cin >> n;
            }

        } while (n < 0);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }

    double ReadNegativeDouble()
    {
        double n;
        do {
            cout << "Please enter a Negative Floating-Point number: ";
            cin >> n;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid Input please enter a valid number \n";
                cin >> n;
            }

        } while (n > 0);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }
    double ReadNegativeDouble(string msg)
    {
        double n;
        do {
            cout << msg;
            cin >> n;

            while (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid Input please enter a valid number \n";
                cin >> n;
            }

        } while (n > 0);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return n;
    }
///////
    
 
    int ReadChar()
    {
        char c;
        bool validInput = false;

        // Loop until valid input is provided
        while (!validInput) {
            cout << "Please enter a character: ";
            cin >> c;

            // Check if input is a valid character
            if (cin.fail()) {
                cin.clear();  // Clear error flags
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
                cout << "Invalid input. Please enter a single character.\n";
            } else {
                validInput = true;  // Input is valid, exit the loop
            }
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return c;
    }   
    int ReadChar(string msg)
    {
        char c;
        bool validInput = false;

        // Loop until valid input is provided
        while (!validInput) {
            cout << msg;
            cin >> c;

            // Check if input is a valid character
            if (cin.fail())
            {
                cin.clear();  // Clear error flags
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
                cout << "Invalid input. Please enter a single character.\n";
            } 
            else {
                validInput = true;  // Input is valid, exit the loop
            }
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return c;
    }


    string ReadWord()
    {
        string word = "";
        cout << "Enter a word [No spaces] : ";
        cin >> word;
        return word;
    }
    string ReadWord(string msg)
    {
        string word = "";
        cout << msg;
        cin >> word;
        return word;
    }


    string ReadLine()
    {
        string line = "";
        cout << "Enter a line of string : ";
        // Ensure cin is in a good state before reading a line
        cin.clear();
        // Clear newline from previous input
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, line);
        return line;
    }
    string ReadLine(string msg)
    {
        string line = "";

        cout << msg;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        getline(cin, line);
        return line;
    }


}