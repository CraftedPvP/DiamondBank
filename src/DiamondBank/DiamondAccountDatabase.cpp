#include "DiamondAccountDatabase.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::stringstream;
DiamondAccountDatabase::DiamondAccountDatabase()
{
    databaseUrl = "database.txt";
    databaseCopyUrl = databaseUrl + "copy";
    delimiter = ',';
}

AccountInfo DiamondAccountDatabase::GetAccount(string email)
{
    string line;
    ifstream inputFile (databaseUrl);
    bool foundUser = false;
    AccountInfo user;
    if (!inputFile.is_open())
    {
        cerr << "Unable to connect to the database" << endl;
        return user;
    }

    while ( getline (inputFile,line) )
    {
        user = ParseDelimitedData(ParseLine(line));
        if(user.Email == email) {
            foundUser = true;
            break;
        }
    }
    inputFile.close();

    // reset data to prevent leak
    if(!foundUser){
        user.Email = "";
        user.Name = "";
        user.Money = 0;
    }

    return user;
}

void DiamondAccountDatabase::MakeDatabaseBackup()
{
    std::ifstream  src(databaseUrl, std::ios::binary);
    std::ofstream  dst(databaseCopyUrl, std::ios::binary);
    dst << src.rdbuf();
}

vector<string> DiamondAccountDatabase::ParseLine(std::string line)
{
    // 0 email
    // 1 hashed password
    // 2 name
    // 3 diamonds
    stringstream lineStream(line);
    vector<string> data;
    while( lineStream.good() )
    {
        string substr;
        getline( lineStream, substr, delimiter );
        data.push_back( substr );
    }
    return data;
}
AccountInfo DiamondAccountDatabase::ParseDelimitedData(vector<string> data)
{
    if(data.size() == 0) return AccountInfo();
    return AccountInfo(data[0],data[2],std::stoi(data[3]));
}
string DiamondAccountDatabase::HashPassword(string password)
{
    return password + "1"; // ideally we use a crypto library. I'm not gonna use it for now
}
bool DiamondAccountDatabase::CheckIfUserExists(string email)
{
    return GetAccount(email).Email != "";
}

AccountInfo DiamondAccountDatabase::Login(string email, string pass)
{
    ifstream inputFile (databaseUrl);
    if (!inputFile.is_open()){
        cerr << "Unable to connect to the database" << endl;
        return AccountInfo();
    }

    string line;
    AccountInfo user;
    bool foundUser = false;
    while ( getline (inputFile,line) )
    {
        vector<string> data = ParseLine(line);
        user = ParseDelimitedData(data);
        if(user.Email == email) {
            if(data[1] == pass){
                foundUser = true;
                //cout << "Found user" << endl;
                break;
            }
        }
    }

    // reset data to prevent leak
    if(!foundUser){
        user.Email = "";
        user.Name = "";
        user.Money = 0;
    }

    inputFile.close();
    return user;
}

bool DiamondAccountDatabase::CreateAccount(AccountInfo user, string pass)
{
    if(CheckIfUserExists(user.Email)) {
        cerr << "Unable to create account as account already exists in the database" << endl;
        return false;
    }
    MakeDatabaseBackup();
    ofstream outputFile (databaseUrl, std::ios::app);
    if(!outputFile.is_open()){
        cerr << "Unable to connect to the database" << endl;
        return false;
    }
    outputFile << user.Email << delimiter << HashPassword(pass) << delimiter << user.Name << delimiter << user.Money << endl;
    outputFile.close();
    //cout << "User account created" << endl;
    return true;
}

float DiamondAccountDatabase::GetMoney(string email) { return GetAccount(email).Money; }

bool DiamondAccountDatabase::AddMoney(string email, float amount)
{
    MakeDatabaseBackup();
    ifstream inputFile (databaseCopyUrl);
    ofstream outputFile (databaseUrl);
    if (!outputFile.is_open() || !inputFile.is_open()){
        cerr << "Unable to connect to the database" << endl;
        return false;
    }

    string line;
    AccountInfo user;
    bool foundUser = false;
    while ( getline (inputFile,line) )
    {
        vector<string> data = ParseLine(line);
        user = ParseDelimitedData(data);
        if(user.Email == email) {
            user.Money += amount;
                                            // hashed password
            outputFile << user.Email << delimiter << data[1] << delimiter << user.Name << delimiter << user.Money << delimiter << endl;
            //cout << "User money has been updated to " << user.Money << endl;
            foundUser = true;
        }
        else{
            outputFile << line << endl;
        }
    }

    // reset data to prevent leak
    user.Email = "";
    user.Name = "";
    user.Money = 0;

    inputFile.close();
    outputFile.close();

    if(!foundUser) cerr << "Unable to add money to user" << endl;
    return foundUser;
}

bool DiamondAccountDatabase::DeleteAccount(string email)
{
    if(!CheckIfUserExists(email)){
        cerr << "Unable to delete. User is not found" << endl;
        return false;
    }

    MakeDatabaseBackup();
    ifstream inputFile (databaseCopyUrl);
    ofstream outputFile (databaseUrl);
    if (!outputFile.is_open() || !inputFile.is_open()){
        cerr << "Unable to connect to the database" << endl;
        return false;
    }

    string line;
    AccountInfo user;
    while ( getline (inputFile,line) )
    {
        vector<string> data = ParseLine(line);
        user = ParseDelimitedData(data);
        if(user.Email != email)
            outputFile << line << endl;
    }

    // reset data to prevent leak
    user.Email = "";
    user.Name = "";
    user.Money = 0;

    inputFile.close();
    outputFile.close();
    cout << "User is deleted" << endl;
    return true;
}
