#include <iostream>
#include <string>
using namespace std;

int main() {
    char shift_direction;
    string typed_message;
    cin >> shift_direction >> typed_message;

    string keyboard[] = {
        "qwertyuiop",
        "asdfghjkl;",
        "zxcvbnm,./"
    };

    string original_message;

    for (int i = 0; i < typed_message.length(); i++) {
        char c = typed_message[i];

        for (int j = 0; j < 3; j++) {
            size_t pos = keyboard[j].find(c);
            if (pos != string::npos) {
                if (shift_direction == 'R') {
                    original_message += keyboard[j][pos - 1];
                } else if (shift_direction == 'L') {
                    original_message += keyboard[j][pos + 1];
                }
                break;
            }
        }
    }

    cout << original_message << endl;

    return 0;
}
