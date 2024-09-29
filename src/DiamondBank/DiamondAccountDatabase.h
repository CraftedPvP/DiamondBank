#ifndef DIAMONDACCOUNTDATABASE_H
#define DIAMONDACCOUNTDATABASE_H

#include <string>
#include <vector>

#include "../Bank/IAccountDatabase.h"
using std::string;
using std::vector;

class DiamondAccountDatabase : public IAccountDatabase {
    // used to separate between the data found in our local database
    char delimiter;
    
    // relative file path beside the executable
    std::string databaseUrl;
    std::string databaseCopyUrl;

    // slices the line from the local database into manageable strings
    vector<string> ParseLine(std::string line);
    // returns user visible content without the password
    AccountInfo ParseDelimitedData(vector<string> data);
    
    string HashPassword(string password);
public:
    DiamondAccountDatabase();
    
    bool CanConnect() override;
    void MakeDatabaseBackup() override;
    bool CheckIfUserExists(string email) override;
    AccountInfo GetAccount(string email) override;
    
    AccountInfo Login(string email, string pass) override;
    bool CreateAccount(AccountInfo user, string pass) override;
    bool DeleteAccount(string email) override;

    float GetMoney(string email) override;
    bool AddMoney(string email, float amount) override;

    bool CreateDatabase() override;
    string GetDatabaseUrl();
};

#endif