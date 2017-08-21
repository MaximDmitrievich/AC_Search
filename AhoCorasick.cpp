#include "AhoCorasick.h"

namespace ssn
{
    TAhoCorasick::TAhoCorasick()
    {
        this->root = new TNode();
        this->patterns = 0;
    }
    TAhoCorasick::~TAhoCorasick()
    {
        delete this->root;
        this->patterns = 0;
    }
    
    void TAhoCorasick::Add(std::vector<std::string> &value)
    {
        if (value.empty()) {
            return;
        }
        TNode *node = this->root;
        int i = 0;
        for (std::vector<std::string>::iterator it = value.begin(); it != value.end(); it++) {
            if (node->GetLink().find(*it) != node->GetLink().end()) {
                node = node->GetNode(*it);
                if (it + 1 == value.end()) {
                    node->SetPattern(++this->patterns);
                    node->SetSize(value.size());
                }
            } else {
                if (it + 1 == value.end()) {
                    node = node->SetLink(*it, new TNode(node, ++this->patterns, value.size()));
                } else {
                    node = node->SetLink(*it, new TNode(node, i));
                }
            }
            i++;
        }
    }
    void TAhoCorasick::Search(std::vector<std::pair<std::string, std::pair<int, int>>> &value)
    {
        if (value.empty()) {
            return;
        }   
        this->NVAlgoritm();
        TNode *curr = this->root;
        std::map<std::string, TNode *>::iterator it;
        int c = 0;
        do {
            while ((it = curr->GetLink().find(value[c].first)) != curr->GetLink().end()) {
                curr = it->second;
                TNode *exit = curr->GetExit();
                if (curr->IsEnd()) {
                    int str = value[c].second.second;
                    int pos = value[c].second.first - curr->GetSize() + 1;
                    if (pos <= 0) { 
                        pos += curr->GetSize();
                        str--;
                    }
                    std::cout << str << ", " << pos << ", " << curr->GetPattern() << std::endl;
                }
                while (exit && exit->IsEnd()) {
                    int str = value[c].second.second;
                    int pos = value[c].second.second - curr->GetSize() + 1;
                    if (pos <= 0) {
                        pos += curr->GetSize();
                        str--;
                    }
                    std::cout << str << ", " << pos << ", " << exit->GetPattern() << std::endl;
                    exit = exit->GetExit();
                }
                c++;
            }
            if (curr == this->root) {
                c++;
            } else {
                curr = curr->GetFail();
            }
        } while (c < value.size());
    }
    void TAhoCorasick::NVAlgoritm()
    {
        std::map<std::string, TNode *>::iterator it = this->root->GetLink().begin();
        for (; it != this->root->GetLink().end(); it++) {
            if (it->second->GetParent() == this->root) {
                it->second->SetFail(this->root);
            }
        }
        this->root->SetFail(this->root);
        std::queue<TNode *> qNode;
        qNode.push(this->root);
        while (!qNode.empty()) {
            TNode *node = qNode.front();
            if (node != this->root && !node->IsLeaf()) {
                for (it = node->GetLink().begin(); it != node->GetLink().end(); it++) {
                    TNode *w = node->GetFail();
                    TNode *nextnode = it->second;
                    while (w->GetLink().find(it->first) == w->GetLink().end() && w != this->root) {
                        w = w->GetFail();
                    }
                    if (w->GetLink().find(it->first) != w->GetLink().end()) {
                        nextnode->SetFail(w->GetNode(it->first));
                    } else {
                        nextnode->SetFail(this->root);
                    }
                    if (nextnode->GetFail()->IsEnd()) {
                        nextnode->SetExit(nextnode->GetFail());
                    } else {
                        nextnode->SetExit(nextnode->GetFail()->GetExit());
                    }
                }
            }
            qNode.pop();
            if (!node->IsLeaf()) {
                for (it = node->GetLink().begin(); it != node->GetLink().end(); it++) {
                    qNode.push(it->second);
                }
            }
        }
    }
}
