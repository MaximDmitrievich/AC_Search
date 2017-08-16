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
        std::map<std::string, std::shared_ptr<TNode>> link;
        std::shared_ptr<TNode> parent;
        std::shared_ptr<TNode> exit;
        std::shared_ptr<TNode> fail;
        int pattern;
        int size;
    public:
        TNode(const std::shared_ptr<TNode> &parentvalue, const int sizevalue);
        TNode(const std::shared_ptr<TNode> &parentvalue, const int patternvalue, const int sizevalue);
        TNode();
        virtual ~TNode();

        const std::shared_ptr<TNode> &SetLink(std::string word, const std::shared_ptr<TNode> &&nextlink);
        std::map<std::string, std::shared_ptr<TNode>> &GetLink();
        const std::shared_ptr<TNode> &GetNode(std::string value);

        void SetParent(const std::shared_ptr<TNode> &value);
        const std::shared_ptr<TNode> &GetParent();

        void SetExit(const std::shared_ptr<TNode> &value);
        const std::shared_ptr<TNode> &GetExit();

        void SetFail(const std::shared_ptr<TNode> &value);
        const std::shared_ptr<TNode> &GetFail();
        
        bool IsEnd();

        void SetPattern(const int value);
        int GetPattern();

        void SetSize(const int value);
        int GetSize();
    };

}

#endif
