#include <iostream>
#include <string>
using namespace std;

void TimeCon(string timestr) {
    if (timestr[8] == 'A' || timestr[8] == 'a') {
        cout << "Time = " << timestr << endl;
    } else if (timestr[8] == 'P' || timestr[8] == 'p') {

        switch (timestr[0]) {
        case '0':
            switch (timestr[1]) {
                case '1': cout << "Time = 13" << timestr.substr(2) << endl; break;
                case '2': cout << "Time = 14" << timestr.substr(2) << endl; break;
                case '3': cout << "Time = 15" << timestr.substr(2) << endl; break;
                case '4': cout << "Time = 16" << timestr.substr(2) << endl; break;
                case '5': cout << "Time = 17" << timestr.substr(2) << endl; break;
                case '6': cout << "Time = 18" << timestr.substr(2) << endl; break;
                case '7': cout << "Time = 19" << timestr.substr(2) << endl; break;
                case '8': cout << "Time = 20" << timestr.substr(2) << endl; break;
                case '9': cout << "Time = 21" << timestr.substr(2) << endl; break;
                default:  cout << "Invalid time" << endl; break;
            }
            break;

        case '1':
            switch (timestr[1]) {
                case '0': cout << "Time = 22" << timestr.substr(2) << endl; break;
                case '1': cout << "Time = 23" << timestr.substr(2) << endl; break;
                case '2': cout << "Time = 12" << timestr.substr(2) << endl; break;
                default:  cout << "Invalid time" << endl; break;
            }
            break;

        default:
            cout << "Invalid time" << endl;
            break;
        }

    } else {
        cout << "Invalid time format" << endl;
    }
}

int main() {
    string time;
    cout << "Enter the time in format HH:MM:SSAM/PM: ";
    cin >> time;
    TimeCon(time);
    return 0;
}
