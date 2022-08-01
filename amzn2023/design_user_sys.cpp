#include <bits/stdc++.h>

using std::vector;
using std::string;

vector<string> str_split(const string &s, char delim) {
    vector<string> res;
    std::stringstream ss(s);
    string item;

    while (std::getline(ss, item, delim)) {
        res.push_back(std::move(item));
    }
    return res;
}

vector<string> api(const vector<string>& logs) {
    std::unordered_map<string, string> reg;
    std::unordered_set<string> login;
    vector<string> res;

    for (const auto& log : logs) {
        vector<string> parts = str_split(log, ' ');
        if (parts[0] == "register") {
            if (reg.find(parts[1]) != reg.end()) {
                res.push_back("Username already exists");
            } else {
                reg[parts[1]] = parts[2];
                res.push_back("Registered Successfully");
            }
        } else if (parts[0] == "login") {
            if (reg.find(parts[1]) != reg.end()) {
                if (login.find(parts[1]) != login.end()) {
                    res.push_back("Login Unsuccessful");
                } else {
                    if (reg[parts[1]] == parts[2]) {
                        login.insert(parts[1]);
                        res.push_back("Logged In Successfully");
                    } else {
                        // wrong password
                        res.push_back("Login Unsuccessful");
                    }
                }
            } else {
                // not registered
                res.push_back("Login Unsuccessful");
            }
        } else {
            if (reg.find(parts[1]) != reg.end()) {
                if (login.find(parts[1]) != login.end()) {
                    res.push_back("Logged Out Successfully")
                } else {
                    // not logged in
                    res.push_back("Logout Unsuccessful");
                }
            } else {
                // not registered
                res.push_back("Logout Unsuccessful");
            }
        }
    }
}
