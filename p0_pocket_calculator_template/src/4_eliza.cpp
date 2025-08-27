#include <iostream>
using namespace std;
int main() {
    string name;
    string response2;
    string response3;

    cout << "Hello, I am Eliza. I'll be your therapist today.\nTell me, what is your name?\n";
    getline(cin, name);
    cout << "Nice to meet you, " << name << ", how can I help you today?\nWhat is bothering you?\n";
    getline(cin, response2);
    cout << "\"" << response2 << "\"? Please tell me more. How does that make you feel?\n";
    getline(cin, response3);
    cout << "Intresting intreseting........ well would you look at the time I am afriad we will have to end the session here.\nHave a good rest of your day, " << name << ", I hope to see you again soon!";

}