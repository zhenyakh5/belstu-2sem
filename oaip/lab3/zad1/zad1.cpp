#include <fstream>
#include <iostream>
using namespace std;

const int MAX = 1000;

bool isSameWord(char* word1, char* word2) {
    int i = 0;
    while (word1[i] != '\0' && word2[i] != '\0') {
        if (word1[i] != word2[i]) {
            return false;
        }
        i++;
    }
    if (word1[i] != word2[i]) {
        return false;
    }
    return true;
}

int countA(char* word) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == 'a') {
            count++;
        }
    }
    return count;
}

void copyString(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream file1("D:/University/oaip/2sem/lab3/FILE1.txt");
    ofstream file2("D:/University/oaip/2sem/lab3/FILE2.txt");

    char line[MAX], word[MAX], prevWord[MAX];
    int wordCount = 0, maxACount = 0, maxAWord = 0;

    while (file1.getline(line, MAX)) {
        int i = 0, j = 0;
        bool hasSameWord = false;
        while (true) {
            if (line[i] == ' ' || line[i] == '\0') {
                word[j] = '\0';
                if (isSameWord(prevWord, word)) {
                    hasSameWord = true;
                }
                copyString(prevWord, word);
                j = 0;
                wordCount++;
                if (countA(word) > maxACount) {
                    maxACount = countA(word);
                    maxAWord = wordCount;
                }
            }
            else {
                word[j] = line[i];
                j++;
            }
            if (line[i] == '\0') {
                break;
            }
            i++;
        }
        if (hasSameWord) {
            file2 << line << endl;
        }
    }

    cout << "Слово с 'а': " << maxAWord << endl;

    file1.close();
    file2.close();

    return 0;
}