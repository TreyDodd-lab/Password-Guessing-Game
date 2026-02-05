#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

const int Max_Attempts = 5;
const int Timeout_Seconds = 10;
const int Max_Time = 120;

string Correct_Password() {
    return "Password";
}

bool Check_Password(const string& input) {
    return input == Correct_Password();
}

void Game_Begin() {
    cout << "Welcome to the Password Guessing Game!" << endl;
    sleep_for(seconds(2));

    cout << "You have snuck into the headmaster's office to change your grades because you are failing your classes!" << endl;
    sleep_for(seconds(2));

    cout << "You have 2 minutes to hack into his computer before he comes back" << endl;
    sleep_for(seconds(2));

    cout << "If you dont get into his computer before the 2 minutes are up you fail and you are expelled!" << endl;
    sleep_for(seconds(2));

    cout << "Oh i forgot to mention, you have 5 attempts before you are locked out!" << endl;
    sleep_for(seconds(2));

    cout << "If you use 3 attempts you are timed out for 10 seconds!" << endl;
    sleep_for(seconds(2));

    cout << "Word on the street says the headmaster's password begins with the letter P" << endl;
    sleep_for(seconds(2));

    cout << "Good luck, prove to everyone that you're the master hacker you said you are!" << endl;
    sleep_for(seconds(2));
}

int main() {
    Game_Begin();

    int attempts = 0;
    string input;

    auto start_time = steady_clock::now();

    while (attempts < Max_Attempts) {
        
        auto current_time = steady_clock::now();
        auto elapsed = duration_cast<seconds>(current_time - start_time).count();

        if (elapsed >= Max_Time) {
            cout << "\nTime's up! The headmaster returned. You were expelled!" << endl;
            return 0;
        }

        cout << "\nEnter password: ";
        cin >> input;
        attempts++;

        if (Check_Password(input)) {
            cout << "\nAccess granted! You changed your grades successfully." << endl;
            return 0;
        }
        else {
            cout << "Incorrect password." << endl;
        }

       
        if (attempts == 3) {
            cout << "Too many attempts! System locked for " << Timeout_Seconds << " seconds..." << endl;
            sleep_for(seconds(Timeout_Seconds));
        }

        
        cout << "Attempts remaining: " << (Max_Attempts - attempts) << endl;
    }

    cout << "\nYou have been locked out of the system. Game over." << endl;
    return 0;
}
