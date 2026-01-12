#include <iostream>
#include <string>
#include "MyInputLibrary.h"
#include "clsString.h"
using namespace std;


class cCalculator
{
private:
    float _lastInput = 0;
    float _currentResutlt = 0;
    float _previousResult = 0;
    string _lastOperationName = "Clearing";

    void SetlastInput(float input)
    {
        _lastInput = input;
    }
    float GetLastInput()
    {
        return _lastInput;
    }

    void SetCurrentResult(float result)
    {
        _currentResutlt = result;
    }
    float GetCurrentResult()
    {
        return _currentResutlt;
    }

    void SetPreviousResult(float prevResult)
    {
        _previousResult = prevResult;
    }
    float GetPreviousResult()
    {
        return _previousResult;
    }

public:
    void Add(float input)
    {
        SetlastInput(input);
        SetPreviousResult(_currentResutlt);
        SetCurrentResult(_currentResutlt + GetLastInput());
        _lastOperationName = "Adding";
    }

    void Subtract(float input)
    {
        SetlastInput(input);
        SetPreviousResult(_currentResutlt);
        SetCurrentResult(_currentResutlt - GetLastInput());
        _lastOperationName = "Subtracting";
    }

    void Multiply(float input)
    {
        SetlastInput(input);
        SetPreviousResult(_currentResutlt);
        SetCurrentResult(_currentResutlt * GetLastInput());
        _lastOperationName = "Multiplying by";
    }

    void Divide(float input)
    {
        if (input == 0)
            input = 1;

        SetlastInput(input);
        SetPreviousResult(_currentResutlt);
        SetCurrentResult(_currentResutlt / GetLastInput());
        _lastOperationName = "Dividing by";
    }

    void Clear()
    {
        SetlastInput(0);
        SetCurrentResult(0);
        SetPreviousResult(0);
        _lastOperationName = "Clearing";
    }


    void ShowResult()
    {
        if (_lastOperationName == "Clearing")
            cout << "Result after " + _lastOperationName + " = " + to_string(GetCurrentResult()) + ".\n";

        cout << "Result after " + _lastOperationName + " " + to_string(GetLastInput()) + " = " + to_string(GetCurrentResult()) + ".\n";
    }




};

class cPerson
{
private:
    int _ID;
    string _firstName;
    string _lastName;
    string _email;
    string _phoneNumber; 


public:

    cPerson(short id, string firstName, string lastName, string email, string phoneNumber)
    {
        _ID = id;
        _firstName = firstName;
        _lastName = lastName;
        _email = email;
        _phoneNumber = phoneNumber;
    }

    void  SetFirstName(string firstName)
    {
        _firstName = firstName;
    }
    string  GetFirstName()
    {
        return _firstName;
    }

    void  SetLastName(string lastName)
    {
        _lastName = lastName;
    }
    string  GetLastName()
    {
        return _lastName;
    }

    void  SetEmail(string email)
    {
        _email = email;
    }
    string  GetEmail()
    {
        return _email;
    }

    void  SetPhoneNo(string phoneNo)
    {
        _phoneNumber = phoneNo;
    }
    string  GetPhoneNo()
    {
        return _phoneNumber;
    }

    string GetFullName()
    {
        return _firstName + " " + _lastName;
    }

    int GetID()
    {
        return _ID;
    }

    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;
    __declspec(property(get = GetPhoneNo, put = SetPhoneNo)) string PhoneNo;
    __declspec(property(get = GetID)) int ID;

    void SendEmail(string header, string body)
    {
        cout << "Sending Email to: " << _email << endl;
        cout << header << endl;
        cout << body << endl;
    }

    void SendSMS(string SMSContent)
    {
        cout << "Sending SMS to :" << _phoneNumber << endl;
        cout << SMSContent << endl;
    }

    void PrintInfo()
    {
        cout << "\n               Info Card\n";
        cout << "----------------------------------------\n";
        cout << "   ID:           "  << _ID           << endl;
        cout << "   First Name:   "  << _firstName    << endl;
        cout << "   Last Name:    "  << _lastName     << endl;
        cout << "   Full Name:    "  << GetFullName() << endl;
        cout << "   E_mail:       "  << _email        << endl;
        cout << "   Pnone Number: "  << _phoneNumber  << endl;
        cout << "----------------------------------------\n\n";
    }
};

class cEmployee : public cPerson
{
     
private:

    float _salary;
    string _jobTitle;
    string _department;


public:

    cEmployee(short id, string firstName, string lastName, string email, string phoneNumber, string jobTitle, string department, float salary)
        : cPerson(id,firstName,lastName,email,phoneNumber)
    {
        _jobTitle = jobTitle;
        _department = department;
        _salary = salary;
    }

    void SetSalary(float salary)
    {
        _salary = salary;
    }
    float GetSalary()
    {
        return _salary;
    }


    void SetJobTitle(string jobTitle)
    {
        _jobTitle = jobTitle;
    }
    string GetJobTitle()
    {
        return _jobTitle;
    }

    void SetDepartment(string department)
    {
        _department = department;
    }
    string GetDepartment()
    {
        return _department;
    }

    __declspec(property(get = GetSalary, put = SetSalary)) float Salary;
    __declspec(property(get = GetJobTitle, put = SetJobTitle)) string JobTitle;
    __declspec(property(get = GetDepartment, put = SetDepartment))  string Department;


    void PrintInfo()
    {
        cout << "\n               Info Card\n";
        cout << "----------------------------------------\n";
        cout << "   ID           : " << GetID()         << endl;
        cout << "   First Name   : " << GetFirstName()  << endl;
        cout << "   Last Name    : " << GetLastName()   << endl;
        cout << "   Full Name    : " << GetFullName()   << endl;
        cout << "   E_mail       : " << GetEmail()      << endl;
        cout << "   Pnone Number : " << GetPhoneNo()    << endl;
        cout << "   Job Title    : " << _jobTitle       << endl;
        cout << "   Department   : " << _department     << endl;
        cout << "   Salary       : " << _salary         << endl;
        cout << "----------------------------------------\n\n";
    }
};
  
class cProgrammer : public cEmployee
{

private: 
    string _mainProgrammingLanguage;

public:

    cProgrammer(short id, string firstName, string lastName, string email, string phoneNo, string jobTitle, string department, float salary, string mainProgLanguage)
        :cEmployee (id, firstName,lastName,email,phoneNo,jobTitle,department,salary)
    {
        _mainProgrammingLanguage = mainProgLanguage;
    }

    void SetProgrammingLanguage(string progLanguage)
    {
        _mainProgrammingLanguage = progLanguage;
    }
    string GetMainProgrammingLanguage()
    {
        return _mainProgrammingLanguage;
    }

    __declspec(property(get = GetMainProgrammingLanguage, put = SetProgrammingLanguage))   string MainProgrammingLanguage;

    void PrintInfo()
    {
        cout << "\n               Info Card\n";
        cout << "----------------------------------------\n";
        cout << "   ID                   : " << ID << endl;
        cout << "   First Name           : " << FirstName << endl;
        cout << "   Last Name            : " << LastName << endl;
        cout << "   Full Name            : " << GetFullName() << endl;
        cout << "   E_mail               : " << Email << endl;
        cout << "   Pnone Number         : " << PhoneNo << endl;
        cout << "   Job Title            : " << JobTitle << endl;
        cout << "   Department           : " << Department << endl;
        cout << "   Salary               : " << Salary << endl;
        cout << "   Main Coding Language : " << MainProgrammingLanguage << endl;
        cout << "----------------------------------------\n\n";

    }
};

// practising oop with gemini
class clsSmartDevice
{

protected: 
    string _deviceName;
    int _devicePower;
    bool _isConnected;

public:

    void SetDeviceName(string deviceName)
    {
        // maybe somelogic here to check if the name is taken before to avoid naming 2 deviced with the same name.
        _deviceName = deviceName;
    }
    string GetDeviceName() { return _deviceName; }

    void SetDevicePower(int devicePower)
    {
        if (devicePower < 0 || devicePower >100) 
        {
            cout << "Error!\tPower cannot exeed [0:100] limits\n";
            cout << "Try again\n";
            _devicePower = 0;
        }
        else
            _devicePower = devicePower;
    }
    int GetDevicePower() { return _devicePower; }

    void SetIsConnected(bool isConnected) { _isConnected = isConnected; }
    bool GetIsConnected() { return _isConnected; }

    clsSmartDevice(string deviceName, int devicePower)
    {
        SetDeviceName(deviceName);
        SetDevicePower(devicePower);
        _isConnected = false;
    }
    clsSmartDevice(string deviceName, int devicePower, bool isConnected)
    {
        SetDeviceName(deviceName);
        SetDevicePower(devicePower);
        _isConnected = isConnected;
    }

    void ToggleConnection() { _isConnected = !_isConnected; }

    void ShowStatus()
    {
        cout << "\t" << _deviceName << endl;
        cout << "---------------------------\n";
        cout << "   " << "Device Power        : " << _devicePower << endl;
        cout << "   " << "Is Device Connected : " << boolalpha << _isConnected << endl;
        cout << "---------------------------\n";

    }
};
class clsSmartLight : public clsSmartDevice
{
private: 
    int _brightness;

public:
    void SetBrightness(int brightness)
    {
        if (brightness < 0 || brightness > 500) {
            cout << "Error brightness level cannot exeed [0:500] level \n";
            cout << "TRy again \n";
        }
        else
            _brightness = brightness;
    }
    int GetBrightness() { return _brightness; }

    clsSmartLight(string deviceName, int devicePower, int brightness)
        : clsSmartDevice(deviceName, devicePower)
    {
        SetBrightness(brightness);
    }
    clsSmartLight(string deviceName, int devicePower,bool isConnected,  int brightness)
        : clsSmartDevice(deviceName, devicePower, isConnected)
    {
        SetBrightness(brightness);
    }

    void ShowStatus()
    {
        cout << "\t" << _deviceName << endl;
        cout << "---------------------------\n";
        cout << "   " << "Device Power        : " << _devicePower << endl;
        cout << "   " << "Is Device Connected : " << boolalpha << _isConnected << endl;
        cout << "   " << "Brightness          : " << _brightness << endl;
        cout << "---------------------------\n";
    }
};

class clsSecretData
{
private:
    string _rawPassword;

protected: 
    short _securityLevel;

public: 
    string userName;

    void SetPassword(string password)
    {
        if (password.length() < 8)
        {
            cout << "Password is too short please try again\n";
            return;
        }

        _rawPassword = password;
        cout << "password was changed successfully\n";
    }
    bool CheckPassword(string password) { return (_rawPassword == password); }

    void SetSecurityLevel(short securityLevel)
    {
        // some logic for the security level
        _securityLevel = securityLevel;
    }
    short GetSecurityLevel() { return _securityLevel; }

    void SetUserName(string userName) { this->userName = userName; }
    string GetUserName() { return userName; }

    clsSecretData(string userName, short securityLevel, string rawPassword)
    {
        clsSecretData::userName = userName;
        SetSecurityLevel(securityLevel);
        SetPassword(rawPassword);
    }
};
class clsAdminPanel : protected clsSecretData
{
public:
    clsAdminPanel(string userName, short securityLevel, string password)
        : clsSecretData(userName, securityLevel, password)    {    }

    void ShowAdminAccess()
    {
        cout << "username       : " << userName << endl;
        cout << "security level : " << _securityLevel << endl;
        cout << "password       : " << "stfu password is a critical data that cannot be displayed :D\n";
    }
};

class clsEmployee
{
private:
    float _salary;

protected:
    int _id;
    string _name;

public: 
    string department;

    void SetSalary(float salary)
    {
        if (salary < 0)
        {
            cout << "Salary can only be positive\n";
            _salary = 0;
        }
        else { _salary = salary; }
    }
    float GetSalary() { return _salary; }

    void SetID(int id) { _id = id; }
    int GetID() { return _id; }

    void SetName(string name) { _name = name; }
    string GetName() { return _name; }

    void SetDepartment(string department) { this->department = department; }
    // get property for a public member will not make sense :V
    // string GetDepartment() { return department; }

    //clsEmployee(string name, int id, string department, float salary)
    //{
    //    _name = name;  
    //    _id = id;   
    //    this->department = department; 
    //    SetSalary(salary);
    //}
    
    clsEmployee(string name, int id, string department, float salary)
        : _name(name), _id(id), department(department) // Initializing directly!
    {
        SetSalary(salary); // Logic-heavy stuff stays in the body
    }


};
class clsManager : public clsEmployee
{
private:
    short _teamSize;

public:
    void SetTeamSize(int teamSize)
    {
        if (teamSize < 0)
        {
            cout << "Team Size can only be positive\n";
            _teamSize = 0;
        }
        else { _teamSize = teamSize; }
    }
    short GetTeamSize() { return _teamSize; }

    clsManager(string name, int id, string department, float salary, short teamsize)
        : clsEmployee(name, id, department, salary)
    {
        SetTeamSize(teamsize);
    }

    void ShowManagerInfo()
    {
        cout << "ID         : " <<  _id         << endl;
        cout << "Name       : " <<  _name       << endl;
        cout << "Department : " <<  department  << endl;
        cout << "Salary     : " <<  GetSalary() << endl;
    }
};
class clsContractor : private clsEmployee
{
public:
    clsContractor (string name, int id, string department, float salary)
                  : clsEmployee(name, id, department, salary)    {    }

    void ShowContractorID()
    {
        cout << "contractor id : " << _id << endl;
    }
};
class clsSubContractor : public clsContractor
{
private:
    int _index;
public:
    clsSubContractor(string name, int id, int index, string department, float salary)
        : clsContractor(name, id, department, salary), _index(index)
    {
    }

    void ShowIndex() { cout << _index << endl; }
};

class clsMediaFile
{
protected:
    string _fileName;
    float _fileSize;

public:

    void SetFileName(string fileName) { _fileName = fileName; }
    string GetFileName() { return _fileName; }

    float GetFileSize() { return _fileSize; }

    clsMediaFile(string fileName, float fileSize)
        : _fileName(fileName), _fileSize(fileSize)  {  }

    virtual void ShowFileInfo() = 0;
    virtual void Play() = 0;
    virtual ~clsMediaFile() {}
};

class clsAudioFile : public clsMediaFile
{
private :
    float _bitRate;

public:

    float GetBitRate() { return _bitRate; }

    clsAudioFile(string fileName, float fileSize, float bitRate)
        : clsMediaFile(fileName, fileSize)
    {
        _bitRate = bitRate;
    }

    void ShowFileInfo()
    {
        cout << "File Name : " << _fileName << endl;
        cout << "File Size : " << _fileSize << endl;
        cout << "Bit Rate  : " << _bitRate << endl;
    }

    void Play()
    {
        cout << "Audio is Playing rn ♪♫♪♪♫.." << endl;
    }

    ~clsAudioFile()
    {
        cout << "Hello this is destructor and i dont know what i should use it for\n";
    }
};

class clsVideoFile : public clsMediaFile
{
private:
    int _resolution;

public:
    int GetResolution() { return _resolution; } 
    clsVideoFile(string fileName, float fileSize, int resolution)
        :clsMediaFile(fileName, fileSize)
    {
        _resolution = resolution;
    }

    void ShowFileInfo()
    {
        cout << "File Name   : " << _fileName << endl;
        cout << "File Size   : " << _fileSize << endl;
        cout << "Resolution  : " << _resolution << endl;
    }

    void Play()
    {
        cout << "Hello, a video is playing rn :D\n";
    }

    void ShowSubtitles()
    {
        cout << "Showing subtitles for the video...\n";
    }
    ~clsVideoFile()
    { 
        cout << "This is the constructor in video class and i still don't know what to use it for\n"; 
    }

};


int main()
{


}

