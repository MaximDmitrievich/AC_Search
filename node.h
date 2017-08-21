#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
#include <cstdlib>
#include <memory>
#include <map>
#include <string>
#include <vector>
#include <queue>

namespace ssn {
    class TNode {
    private:
        std::map<std::string, TNode *> link;
        TNode *parent;
        TNode *exit;
        TNode *fail;
        int pattern;
        int size;
    public:
        TNode(TNode *parentvalue, const int sizevalue);
        TNode(TNode  *parentvalue, const int patternvalue, const int sizevalue);
        TNode();
        virtual ~TNode();

        TNode *SetLink(std::string word, TNode *nextlink);
        std::map<std::string, TNode *> &GetLink();
        TNode *GetNode(std::string value);

        void SetParent(TNode *value);
        TNode *GetParent();

        void SetExit(TNode *value);
        TNode *GetExit();

        void SetFail(TNode *value);
        TNode *GetFail();
        
        bool IsEnd();
        bool IsLeaf();

        void SetPattern(const int value);
        int GetPattern();

        void SetSize(const int value);
        int GetSize();
    };

}

#endif
