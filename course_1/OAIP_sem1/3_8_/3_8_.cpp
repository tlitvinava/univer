#include <iostream>
#include <string>

bool vowel_check(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        ch += 32;
    }
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' || ch < 'a' || ch > 'z';
}

bool compare(char symbol1, char symbol2)
{
    return tolower(symbol1) == tolower(symbol2);
}

std::string change_string(std::string str) {

    if (str.empty()) {
        std::cout << "";
    }

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 'C' || str[i] == 'Q' || str[i] == 'W' || str[i] == 'X') {
            if (str.empty()) {
                std::cout << "";
            }
            str.erase(i, 1);
            --i;
            continue;
        }
    }

    const int size = 29;
    std::string replacements[size][2] = {
        {"ph", "f"}, {"pH", "f"}, {"Ph", "F"},{"PH", "F"},{"th", "z"}, {"tH", "z"},{"Th", "Z"},{"TH", "Z"}, {"ee", "i"}, {"eE", "i"},{"Ee", "I"},{"EE", "I"},
        {"qu", "kv"}, {"qU", "kv"}, {"you", "u"}, 
        {"yOU", "u"}, {"yoU", "u"},{"yOu", "u"},{"You", "U"},{"YOU", "U"},{"YoU", "U"},{"YOu", "U"}, {"oo", "u"},
         {"oO", "u"},{"Oo", "U"},{"OO", "U"}, {"q", "k"}, {"x", "ks"}, {"w", "v"}
    };

    for (int i = 0; i < str.length();i++) {
        for (int j = 0; j < size; j++) {
            int stop = replacements[j][0].length();
            if (i+stop > str.length()) {
                stop = str.length()-i;
            }
            std::string str1 = str.substr(i, stop);
            if (str1 == replacements[j][0]) {
                str.replace(i, replacements[j][0].length(), replacements[j][1]);
                i+= replacements[j][1].length()-1;
                break;
            }
        }
    }

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 'c') {
            bool up = false;
            if (isupper(str[i + 1])) {
                up = true;
                str[i + 1] += 32;
            }
            if (str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y') {
                str[i] = 's';
            }
            else {
                str[i] = 'k';
            }

            if (up) {
                str[i + 1] -= 32;
            }
        }
    }

    for (int i = 0; i < str.length(); ++i) {
        bool big_letter = false;
        if (isupper(str[i])) {
            str[i] += 32;
            big_letter = true;
        }

        char symbol = str[i];

        if (!vowel_check(symbol))
        {
            int position = i + 1;
            int counter = 0;

            for (int j = position; j < str.size() && compare(str[j], symbol); j++)
            {
                counter++;
            }

            str.erase(position, counter);
        }
        if (big_letter) {
            str[i] -= 32;
        }
    }
    return str;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::string output = change_string(input);
    std::cout << output;
    return 0;
}
