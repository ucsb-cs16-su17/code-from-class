#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <fstream>
using namespace std;

struct TranslatedWord {
    string english;
    string spanish;
    string german;
    string chinese;
    string russian;
};

void toLowercase(string &s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
}

void initializeTranslationsArray(TranslatedWord translations[], int length) {
    TranslatedWord snow = {"snow", "nieve", "Schnee", "xuě", "sneg"};
    TranslatedWord mountain = {"mountain", "montaña", "Berg", "shān", "gora"};
    TranslatedWord queen = {"queen", "reina", "Königin", "nuwáng", "koroleva"};
    translations[0] = snow;
    translations[1] = mountain;
    translations[2] = queen;
}

string translate(string word, string to_language, 
                 TranslatedWord translations[], int length) {
    for (int i = 0; i < length; i++) {
        if (translations[i].english == word) {
            if (to_language == "spanish") {
                return translations[i].spanish;
            }
            else if (to_language == "german") {
                return translations[i].german;
            }
            else if (to_language == "chinese") {
                return translations[i].chinese;
            }
            else {
                return translations[i].russian;
            }
        }
    }

    return word;
}

int main(int argc, char *argv[])
{
    assert(argc == 3);
    string to_language = argv[2];

    ifstream ifs;
    ifs.open(argv[1]);
    if (ifs.fail()) {
        exit(1);
    }

    TranslatedWord translations[3];
    initializeTranslationsArray(translations, 3);

    while (true) {
        if (ifs.eof()) {
            break;
        }

        char next_char = ifs.peek();
        if (isspace(next_char)) {
            cout << next_char;
            ifs.get();
            continue;
        }

        string word;
        ifs >> word;
        toLowercase(word);

        cout << translate(word, to_language, translations, 3);
    }

    return 0;
}