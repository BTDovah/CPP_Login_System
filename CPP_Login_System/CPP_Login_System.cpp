#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn() {
    string username, password, un, pw;
    cout << "Please enter your username:  ";
    cin >> username;
    cout << "Please enter your password:  ";
    cin >> password;

    ifstream read("data" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password) {

        return true;
    }
    else {
        return false;
    }
}

int main() {

    int choice;

    cout << "1:Register\n2:Login\nYour choice:  ";
    cin >> choice;

    if (choice == 1) {
        string username, password;
        cout << "Select a username:";
        cin >> username;
        cout << "Select a password:";
        cin >> password;

        ofstream file;
        file.open("data" + username + ".txt");
        file << username << endl << password;
        file.close();

    }
    else if (choice == 2) {
        bool status = IsLoggedIn();
        if (!status) {
            cout << "False login!\n";
            system("PAUSE");
            return 0;
        }
        else {
            cout << "Successfully logged in!\n";
            system("PAUSE");
            return 1;
        }
    }

}
