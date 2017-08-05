#ifndef AHO_CORASICK_H
#define AHO_CORASICK_H
#include "nodeend.h"
#include "nodelink.h"


namespace ssn
{

    class TAhoCorasick {
    private:
        std::shared_ptr<TNode> root;
        int patterns;
    public:
        TAhoCorasick();
        virtual ~TAhoCorasick();

        void Add(std::vector<std::string> &value); //pattern
        void Print(std::vector<std::pair<std::string, std::pair<int, int>>> &value); //text
        void BuildAutomat();
    };
}

#endif
