#include "nodeend.h"

namespace ssn
{
    TNodeEnd::TNodeEnd() : isEnd(true), pattern(0), size(0)
    {

    }

    TNodeEnd::~TNodeEnd()
    {

    }

    void TNodeEnd::SetLink(std::string value, std::shared_ptr<TNode> nextlink)
    {
        if (this->link.find(value) == this->link.end()) {
            this->link.insert(std::pair<std::string, std::shared_ptr<TNode>>(value, nextlink));
        }
    }
    std::map<std::string, std::shared_ptr<TNode>> TNodeEnd::GetLink()
    {
        return this->link;
    }

    void TNodeEnd::SetParent(std::shared_ptr<TNode> value)
    {
        this->parent = value;
    }
    std::shared_ptr<TNode> TNodeEnd::GetParent()
    {
        return this->parent;
    }

    void TNodeEnd::SetExit(std::shared_ptr<TNode> value)
    {
        this->exit = value;
    }
    std::shared_ptr<TNode> TNodeEnd::GetExit()
    {
        return this->exit;
    }

    void TNodeEnd::SetFail(std::shared_ptr<TNode> value)
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

    void TNodeEnd::SetPattern(int value)
    {
        this->pattern = value;
    }
    int TNodeEnd::GetPattern()
    {
        return this->pattern;
    }

    void TNodeEnd::SetSize(int value)
    {
        this->size = value;
    }
    int TNodeEnd::GetSize()
    {
        return this->size;
    }
}
