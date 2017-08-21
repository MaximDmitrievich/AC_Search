#include "node.h"

namespace ssn {
    TNode::TNode(TNode *parentvalue, const int sizevalue) : parent(parentvalue), exit(nullptr), fail(nullptr), pattern(-1), size(sizevalue)
    {
    
    }
    TNode::TNode(TNode *parentvalue, const int patternvalue, const int sizevalue) : parent(parentvalue), pattern(patternvalue), size(sizevalue)
    {
    
    }
    TNode::TNode() : parent(nullptr), exit(this), fail(this), pattern(-1), size(0)
    {
    
    }

    TNode::~TNode()
    {
        this->parent = nullptr;
        this->exit = nullptr;
        this->fail = nullptr;
        for (std::map<std::string, TNode *>::iterator it = this->link.begin(); it != this->link.end(); it++) {
            delete it->second;
        }
        this->link.clear();
    }

    TNode *TNode::SetLink(std::string word, TNode *nextlink) 
    {
        this->link.insert(std::pair<std::string, TNode *>(word, nextlink));
        TNode *result = this->link.find(word)->second;
        return result;
    }
    std::map<std::string, TNode *> &TNode::GetLink()
    {
        return this->link;
    }
    TNode *TNode::GetNode(std::string value)
    {
        TNode *result = this->link.find(value)->second;
        return result;
    }

    void TNode::SetParent(TNode *value)
    {
        this->parent = value;
    }
    TNode *TNode::GetParent() 
    {
        TNode *result = this->parent;
        return result;
    }

    void TNode::SetExit(TNode *value)
    {
        this->exit = value;
    }
    TNode *TNode::GetExit()
    {
        TNode *result = this->exit;
        return result;
    }

    void TNode::SetFail(TNode *value)
    {
        this->fail = value;
    }
    TNode *TNode::GetFail()
    {
        TNode *result = this->fail;
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

    bool TNode::IsLeaf()
    {
        bool result = false;
        if (this->link.empty()) {
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
