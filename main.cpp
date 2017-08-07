#include "AhoCorasick.h"

int main(int argc, char **argv)
{
    std::vector<std::string> pattern;
    std::vector<std::pair<std::string, std::pair<int, int>>> text; //word, num, str
    std::string input;
    std::string buf;
    int len = 0;
    int inputsize = 0;
    ssn::TAhoCorasick search;
    while (getline(std::cin, input)) {
        input += " ";
        if (input == " " && input.size() == 1) {
            break;
        }
        inputsize = input.size();
        for (int i = 0; i < inputsize; i++) {
            if (input[i] != ' ') {
                buf.push_back((char) tolower(input[i]));
            } else {
                if (len > 16) {
                    pattern.clear();
                    buf.clear();
                    break;
                }
                if (buf.size() > 0  && buf != " ") {
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
    int pos = 1;
    while (getline(std::cin, input)) {
        str++;
        pos = 1;
        input += " ";
        for (int i = 0; i < input.size(); i++) {
            if (input[i] != ' ') {
                buf.push_back((char) tolower(input[i]));
            } else {
                if (buf.size() > 0 && buf != " ") {
                    text.push_back(std::make_pair(buf, std::make_pair(pos, str)));
                    pos++;
                }
                buf.clear();
            }
        }
    }
    search.Print(text);
    return 0;
}
