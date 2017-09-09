#include "AhoCorasick.h"


int main(int argc, char **argv)
{
    std::vector<std::string> pattern;
    std::vector<std::pair<std::string, std::pair<int, int>>> text;
    std::string buf;
    std::string input;
    int len = 0;
    ssn::TAhoCorasick search;
    while (getline(std::cin, input)) {
        input += " ";
        if (input == " " && input.size() == 1) {
            break;
        }
        for (int i = 0; i < input.size(); i++) {
            if (input[i] != ' ') {
                buf.push_back((char) tolower(input[i]));
            } else {
                if (len > 16) {
                    pattern.clear();
                    buf.clear();
                    break;
                }
                if (buf.size() > 0 && buf != " ") {
                    pattern.push_back(buf);
                }
                buf.clear();
                len++;
            }
        }
        if (pattern.size() > 0) {
            search.Add(pattern);
        }
        len = 0;
        pattern.clear();
    }
    int str = 0;
    int pos = 0;
    while (getline(std::cin, input)) {
        str++;
        pos = 0;
        input += " ";
        for (int i = 0; i < input.size(); i++) {
            if (input[i] != ' ') {
                if (input[i + 1] == ' ') {
                    pos++;
                }
                buf.push_back((char) tolower(input[i]));
            } else {
                if (buf.size() > 0 && buf != " ") {
                    text.push_back(std::make_pair(buf, std::make_pair(pos, str)));
                }
                buf.clear();
            }
        }
    }
    search.Search(text);
    return 0;
}
