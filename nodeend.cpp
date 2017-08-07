#include "nodeend.h"

namespace ssn
{
    TNodeEnd::TNodeEnd(const std::shared_ptr<TNode> &parentvalue, const int patternvalue, const int sizevalue) : isEnd(true)
    {
        this->exit = nullptr;
        this->fail = nullptr;
        this->link.clear();
        this->parent = parentvalue;
        this->pattern = patternvalue;
        this->size = sizevalue;
    }
    TNodeEnd::TNodeEnd() : isEnd(true), pattern(0), size(0)
    {

    }

    TNodeEnd::~TNodeEnd()
    {
        this->parent = nullptr;
        this->exit = nullptr;
        this->fail = nullptr;
        this->link.clear();
    }
    
    std::shared_ptr<TNode> TNodeEnd::SetLink(std::string value, const std::shared_ptr<TNode> &nextlink)
    {
        if (this->link.find(value) == this->link.end()) {
            this->link.insert(std::pair<std::string, std::shared_ptr<TNode>>(value, nextlink));
        }
        return nextlink;
    }
    std::map<std::string, std::shared_ptr<TNode>> TNodeEnd::GetLink()
    {
        return this->link;
    }

    void TNodeEnd::SetParent(const std::shared_ptr<TNode> &value)
    {
        this->parent = value;
    }
    std::shared_ptr<TNode> TNodeEnd::GetParent()
    {
        return this->parent;
    }

    void TNodeEnd::SetExit(const std::shared_ptr<TNode> &value)
    {
        this->exit = value;
    }
    std::shared_ptr<TNode> TNodeEnd::GetExit()
    {
        return this->exit;
    }

    void TNodeEnd::SetFail(const std::shared_ptr<TNode> &value)
    {
        this->fail = value;
    }
    std::shared_ptr<TNode> TNodeEnd::GetFail()
    {
        return this->fail;
    }

    bool TNodeEnd::IsEnd()
    {
        return this->isEnd;
    }

    void TNodeEnd::SetPattern(const int value)
    {
        this->pattern = value;
    }
    int TNodeEnd::GetPattern()
    {
        return this->pattern;
    }

    void TNodeEnd::SetSize(const int value)
    {
        this->size = value;
    }
    int TNodeEnd::GetSize()
    {
        return this->size;
    }
}
