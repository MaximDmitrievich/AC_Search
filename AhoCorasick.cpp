#include "AhoCorasick.h"

namespace ssn
{
    TAhoCorasick::TAhoCorasick()
    {
        std::shared_ptr<TNode> temp (new TNodeLink());
        this->root = temp;
        this->patterns = 0;
    }
    TAhoCorasick::~TAhoCorasick()
    {
        this->patterns = 0;
    }

    void TAhoCorasick::Add(std::vector<std::string> &value)
    {
        if (value.empty()) {
            return;
        }
        std::shared_ptr<TNode> node = this->root;
        for (std::vector<std::string>::iterator it = value.begin(); it != value.end(); it++) {
            if (node->GetLink().find(*it) != node->GetLink().end()) {
                node = node->GetLink().find(*it)->second;
            } else {
                if (*it == value.back()) {
                    node = node->SetLink(*it, std::make_shared<TNodeEnd>(node, ++this->patterns, value.size()));
                } else {
                    node = node->SetLink(*it, std::make_shared<TNodeLink>(node));
                }
            }
        }
        node = nullptr;
    }
    void TAhoCorasick::Print(std::vector<std::pair<std::string, std::pair<int, int>>> &value)
    {
        if (value.empty()) {
            return;
        }   
        this->BuildAutomat();
        int ind = 0;
        std::shared_ptr<TNode> curr = this->root;
        int size = value.size();
        std::map<std::string, std::shared_ptr<TNode>>::iterator it;
        for (int i = 0; i < size; i++) {
            if (curr == nullptr) {
                curr = this->root;
                ind = i + 1;
            }
    		it = curr->GetLink().find(value[i].first);
            if (it != curr->GetLink().end()) {
    			curr = it->second;
            } else {
                curr = curr->GetFail();
                if (curr) {
                    it = curr->GetLink().find(value[i].first);
                    while (curr->GetFail() != this->root && it == curr->GetLink().end()) {
                        curr = curr->GetFail();
                        if (curr == nullptr) {
                            curr = this->root;
                            break;
                        }
                        it = curr->GetLink().find(value[i].first);
                    }
                    if (it != curr->GetLink().end()) {
                        curr = it->second;
                    } else {
                        curr = this->root;
                        ind = i + 1;

                    }
                } else {
                    curr = this->root;
                    ind = i + 1;
                }
            }
            if (!curr->GetLink().empty()) {
                if (curr->GetExit()) {
                    curr = curr->GetExit();
                } else {
                    curr = curr->GetFail();
                }
            }
            if (curr->IsEnd()) {
                std::cout << value[ind].second.second << ", " << value[ind].second.first << ", " << curr->GetPattern() << std::endl;
                ind++;
            }
        }
    }
    void TAhoCorasick::BuildAutomat()
    {
        std::shared_ptr<TNode> node = nullptr;
        std::map<std::string, std::shared_ptr<TNode>>::iterator it = this->root->GetLink().begin();
        for (; it != this->root->GetLink().end(); it++) {
            if (it->second->GetParent() == this->root) {
                it->second->SetFail(this->root);
            }
        }
        std::queue<std::shared_ptr<TNode>> qNode;
        qNode.push(this->root);
        while (!qNode.empty()) {
            node = qNode.front();
            if (node != this->root && !node->IsEnd()) {
                for (it = node->GetLink().begin(); it != node->GetLink().end(); it++) {
                    std::shared_ptr<TNode> w = node->GetFail();
                    std::shared_ptr<TNode> nextnode = it->second;
                    std::string c = it->first;
                    while (w->GetLink().find(c) == w->GetLink().end() && w != this->root) {
                        w = w->GetFail();
                    }
                    if (w->GetLink().find(c) != w->GetLink().end()) {
                        nextnode->SetFail(w->GetLink().find(c)->second);
                    } else {
                        nextnode->SetFail(this->root);
                    }
                    if (!nextnode->GetFail()->IsEnd()) {
                        nextnode->SetExit(nextnode->GetFail());
                    } else {
                        nextnode->SetFail(nextnode->GetFail()->GetExit());
                    }
                }
            }
            qNode.pop();
            if (!node->IsEnd()) {
                for (it = node->GetLink().begin(); it != node->GetLink().end(); it++) {
                    qNode.push(it->second);
                }
            }
        }
    }
}
