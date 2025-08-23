#include <iostream>
#include <cstring>
using namespace std;

void compr(char* str, int numStrings) {
    for (int i = 0; i < numStrings; ++i) {
        char* currentStr = str;
        char* destination = str;

        while (*currentStr) {
            if (*currentStr != ' ') {
                *destination++ = *currentStr;
            }
            currentStr++;
        }

        *destination = '\0';
        str += strlen(str) + 1;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    char strings[][50] = {
        "Я хочу домой!",
        " Я х о ч у д о м о й ",
        "Привет, я пришёл домой"
    };

    cout << "До: " << strings[0] << endl;
    compr(strings[0], 1);
    cout << "После:  " << strings[0] << endl;

    cout << "\nДо: " << strings[1] << endl;
    compr(strings[1], 1);
    cout << "После:  " << strings[1] << endl;

    cout << "\nДо: " << strings[2] << endl;
    compr(strings[2], 1);
    cout << "После:  " << strings[2] << endl;

    return 0;
}
