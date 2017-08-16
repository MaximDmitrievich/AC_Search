#include "node.h"

namespace ssn {
    TNode::TNode(const std::shared_ptr<TNode> &parentvalue, const int sizevalue) : parent(parentvalue), exit(nullptr), fail(nullptr), pattern(-1), size(sizevalue)
    {
    
    }
    TNode::TNode(const std::shared_ptr<TNode> &parentvalue, const int patternvalue, const int sizevalue) : parent(parentvalue), pattern(patternvalue), size(sizevalue)
    {
    
    }
    TNode::TNode() : parent(nullptr), exit(nullptr), fail(nullptr), pattern(-1), size(0)
    {
    
    }

    TNode::~TNode()
    {
        this->parent = nullptr;
        this->exit = nullptr;
        this->fail = nullptr;
        this->link.clear();
    }

    const std::shared_ptr<TNode> &TNode::SetLink(std::string word, const std::shared_ptr<TNode> &&nextlink)
    {
        this->link.insert(std::pair<std::string, const std::shared_ptr<TNode>&>(word, nextlink));
        const std::shared_ptr<TNode> &result = this->link.find(word)->second;
        return result;
    }
    std::map<std::string, std::shared_ptr<TNode>> &TNode::GetLink()
    {
        return this->link;
    }
    const std::shared_ptr<TNode> &TNode::GetNode(std::string value)
    {
        std::shared_ptr<TNode> &result = this->link.find(value)->second;
        return result;
    }

    void TNode::SetParent(const std::shared_ptr<TNode> &value)
    {
        this->parent = value;
    }
    const std::shared_ptr<TNode> &TNode::GetParent() 
    {
        const std::shared_ptr<TNode> &result = this->parent;
        return result;
    }

    void TNode::SetExit(const std::shared_ptr<TNode> &value)
    {
        this->exit = value;
    }
    const std::shared_ptr<TNode> &TNode::GetExit()
    {
        const std::shared_ptr<TNode> &result = this->exit;
        return result;
    }

    void TNode::SetFail(const std::shared_ptr<TNode> &value)
    {
        this->fail = value;
    }
    const std::shared_ptr<TNode> &TNode::GetFail()
    {
        const std::shared_ptr<TNode> &result = this->fail;
        return result;
    }
    
    bool TNode::IsEnd()
    {
        bool result = false;
        if (this->pattern != -1) {
            result = true;
        }
        return result;
    }

    void TNode::SetPattern(const int value) 
    {
        this->pattern = value;
    }
    int TNode::GetPattern()
    {
        return this->pattern;
    }

    void TNode::SetSize(const int value)
    {
        this->size = value;
    }
    int TNode::GetSize()
    {
        return this->size;
    }

}
