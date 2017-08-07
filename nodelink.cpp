#include "nodelink.h"

namespace ssn
{
    TNodeLink::TNodeLink(const std::shared_ptr<TNode> &parentvalue)
    {
        this->link.clear();
        this->parent = parentvalue;
        this->exit = nullptr;
        this->fail = nullptr;
        this->isEnd = false;
    }
    TNodeLink::TNodeLink() : parent(nullptr)
    {
        
    }
    TNodeLink::~TNodeLink()
    {
        this->link.clear();
        this->parent = nullptr;
        this->exit = nullptr;
        this->fail = nullptr;
    }

    std::shared_ptr<TNode> TNodeLink::SetLink(std::string value, const std::shared_ptr<TNode> &nextlink)
    {
        if (this->link.find(value) == this->link.end()) {
            this->link.insert(std::pair<std::string, std::shared_ptr<TNode>>(value, nextlink));
        }
        return nextlink;
    }
    std::map<std::string, std::shared_ptr<TNode>> TNodeLink::GetLink()
    {
        return this->link;
    }

    void TNodeLink::SetParent(const std::shared_ptr<TNode> &value)
    {
        this->parent = value;
    }
    std::shared_ptr<TNode> TNodeLink::GetParent()
    {
        return this->parent;
    }

    void TNodeLink::SetExit(const std::shared_ptr<TNode> &value)
    {
        this->exit = value;
    }
    std::shared_ptr<TNode> TNodeLink::GetExit()
    {
        return this->exit;
    }

    void TNodeLink::SetFail(const std::shared_ptr<TNode> &value)
    {
        this->fail = value;
    }
    std::shared_ptr<TNode> TNodeLink::GetFail()
    {
        return this->fail;
    }

    bool TNodeLink::IsEnd()
    {
        return this->isEnd;
    }

    void TNodeLink::SetPattern(const int value)
    {

    }
    int TNodeLink::GetPattern()
    {
        return 0;
    }

    void TNodeLink::SetSize(const int value)
    {

    }
    int TNodeLink::GetSize()
    {
        return 0;
    }
}
