#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <memory>
#include <vector>
#include <queue>
#include <map>
#include <cstdlib>
#include <string>

namespace ssn
{
    class TNode {
    public:
        virtual ~TNode() {}

        virtual void SetLink(std::string word, std::shared_ptr<TNode> nextlink) = 0;
        virtual std::map<std::string, std::shared_ptr<TNode>> GetLink() = 0;

        virtual void SetParent(std::shared_ptr<TNode> value) = 0;
        virtual std::shared_ptr<TNode> GetParent() = 0;

        virtual void SetExit(std::shared_ptr<TNode> value) = 0;
        virtual std::shared_ptr<TNode> GetExit() = 0;

        virtual void SetFail(std::shared_ptr<TNode> value) = 0;
        virtual std::shared_ptr<TNode> GetFail() = 0;

        virtual bool IsEnd() = 0;

        virtual void SetPattern(int value) = 0;
        virtual int GetPattern() = 0;

        virtual void SetSize(int value) = 0;
        virtual int GetSize() = 0;
    };
}

#endif
