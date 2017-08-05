#ifndef NODELINK_H
#define NODELINK_H
#include "node.h"

namespace ssn
{
    class TNodeLink : public TNode {
    private:
        std::map<std::string, std::shared_ptr<TNode>> link;
        std::shared_ptr<TNode> parent;
        std::shared_ptr<TNode> exit;
        std::shared_ptr<TNode> fail;
        bool isEnd;
    public:
        TNodeLink();
        virtual ~TNodeLink() override;

        void SetLink(std::string word, std::shared_ptr<TNode> nextlink) override;
        std::map<std::string, std::shared_ptr<TNode>> GetLink() override;

        void SetParent(std::shared_ptr<TNode> value) override;
        std::shared_ptr<TNode> GetParent() override;

        void SetExit(std::shared_ptr<TNode> value) override;
        std::shared_ptr<TNode> GetExit() override;

        void SetFail(std::shared_ptr<TNode> value) override;
        std::shared_ptr<TNode> GetFail() override;

        bool IsEnd() override;

        void SetPattern(int value) override;
        int GetPattern() override;

        void SetSize(int value) override;
        int GetSize() override;
    };
}

#endif
