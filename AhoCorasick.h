#ifndef AHO_CORASICK_H
#define AHO_CORASICK_H
#include "node.h"


namespace ssn
{

    class TAhoCorasick {
    private:
        TNode *root;
        int patterns;
    public:
        TAhoCorasick();
        virtual ~TAhoCorasick();

        void Add(std::vector<std::string> &value); //pattern
        void Search(std::vector<std::pair<std::string, std::pair<int, int>>> &value); //text
        void NVAlgoritm();
    };
}

#endif
