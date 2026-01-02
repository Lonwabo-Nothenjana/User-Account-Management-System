// Lonwabo Nothenjana
// 56157533

/*User Account Manager system*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

const int MAX = 500;

struct User {
    string email;
    string name;
    string surname;
    int age;
    string country;
    string password;
    string gender;
};

int loadUsers(User users[]);
void mainMenu();
void userMenu();
int validateInt(string prompt);
int login(User users[], int count);
void viewProfile(User user);
void updateCountry(User &user);
void changePassword(User &user);
void saveUsers(User users[], int count);
double averageAge(User users[], int count);
void genderStats(User users[], int count);

int main() {
    User users[MAX];
    int userCount = loadUsers(users);

    if (userCount == 0) {
        cout << "No users loaded. Exiting program.\n";
        return 0;
    }

    int choice;
    do {
        mainMenu();
        choice = validateInt("Choose option: ");

        if (choice == 1) {
            int loggedInIndex = login(users, userCount);
            if (loggedInIndex != -1) {
                int userChoice;
                do {
                    userMenu();
                    userChoice = validateInt("Choose option: ");

                    switch (userChoice) {
                        case 1:
                            viewProfile(users[loggedInIndex]);
                            break;
                        case 2:
                            updateCountry(users[loggedInIndex]);
                            saveUsers(users, userCount);
                            break;
                        case 3:
                            changePassword(users[loggedInIndex]);
                            saveUsers(users, userCount);
                            break;
                        case 4:
                            cout << "\nAverage Age: "
                                 << averageAge(users, userCount) << endl;
                            genderStats(users, userCount);
                            break;
                        case 5:
                            cout << "Logged out successfully.\n";
                            break;
                        default:
                            cout << "Invalid option.\n";
                    }
                } while (userChoice != 5);
            }
        }
        else if (choice == 2) {
            cout << "Goodbye.\n";
        }
        else {
            cout << "Invalid option.\n";
        }

    } while (choice != 2);

    return 0;
}

int loadUsers(User users[]) {
    ifstream file("Data.txt");
    string line;
    int count = 0;

    if (!file) {
        cout << "Error opening Data.txt\n";
        return 0;
    }

    while (getline(file, line) && count < MAX) {
        size_t d1 = line.find('|');
        size_t d2 = line.find('|', d1 + 1);
        size_t d3 = line.find('|', d2 + 1);
        size_t d4 = line.find('|', d3 + 1);

        string email = line.substr(0, d1);
        int age = stoi(line.substr(d1 + 1, d2 - d1 - 1));
        string country = line.substr(d2 + 1, d3 - d2 - 1);
        string password = line.substr(d3 + 1, d4 - d3 - 1);
        string gender = line.substr(d4 + 1);

        size_t dot = email.find('.');
        size_t at = email.find('@');

        users[count].email = email;
        users[count].name = email.substr(0, dot);
        users[count].surname = email.substr(dot + 1, at - dot - 1);
        users[count].age = age;
        users[count].country = country;
        users[count].password = password;
        users[count].gender = gender;

        count++;
    }

    file.close();
    return count;
}

/* ---------- MENUS ---------- */
void mainMenu() {
    cout << "\n===== USER MANAGEMENT SYSTEM =====\n";
    cout << "1. Login\n";
    cout << "2. Exit\n";
}

void userMenu() {
    cout << "\n===== USER DASHBOARD =====\n";
    cout << "1. View My Profile\n";
    cout << "2. Update Country\n";
    cout << "3. Change Password\n";
    cout << "4. View Demographic Stats\n";
    cout << "5. Logout\n";
}

/* ---------- INPUT VALIDATION ---------- */
int validateInt(string prompt) {
    int value;
    cout << prompt;
    cin >> value;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return value;
}

int login(User users[], int count) {
    string email, password;

    cout << "\nEmail: ";
    cin >> email;
    cout << "Password: ";
    cin >> password;

    for (int i = 0; i < count; i++) {
        if (users[i].email == email && users[i].password == password) {
            cout << "\nLogin successful. Welcome "
                 << users[i].name << " " << users[i].surname << "!\n";
            return i;
        }
    }

    cout << "Invalid email or password.\n";
    return -1;
}

void viewProfile(User user) {
    cout << "\n===== MY PROFILE =====\n";
    cout << "Name    : " << user.name << " " << user.surname << endl;
    cout << "Age     : " << user.age << endl;
    cout << "Country : " << user.country << endl;
    cout << "Gender  : " << user.gender << endl;
    cout << "Email   : " << user.email << endl;
}

void updateCountry(User &user) {
    cout << "\nEnter new country: ";
    cin.ignore();
    getline(cin, user.country);
    cout << "Country updated successfully.\n";
}

void changePassword(User &user) {
    string newPass;
    cout << "Enter new password: ";
    cin >> newPass;
    user.password = newPass;
    cout << "Password updated successfully.\n";
}

void saveUsers(User users[], int count) {
    ofstream file("Data.txt");

    for (int i = 0; i < count; i++) {
        file << users[i].email << "|"
             << users[i].age << "|"
             << users[i].country << "|"
             << users[i].password << "|"
             << users[i].gender << endl;
    }

    file.close();
}

double averageAge(User users[], int count) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += users[i].age;
    }
    return static_cast<double>(total) / count;
}

void genderStats(User users[], int count) {
    int male = 0, female = 0;

    for (int i = 0; i < count; i++) {
        if (users[i].gender == "Male") male++;
        else if (users[i].gender == "Female") female++;
    }

    cout << "\nGender Statistics:\n";
    cout << "Male   : " << male << endl;
    cout << "Female : " << female << endl;
}
