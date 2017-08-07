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
        TNodeLink(const std::shared_ptr<TNode> &parentvalue);
        TNodeLink();
        virtual ~TNodeLink() override;

        std::shared_ptr<TNode> SetLink(std::string word, const std::shared_ptr<TNode> &nextlink) override;
        std::map<std::string, std::shared_ptr<TNode>> GetLink() override;

        void SetParent(const std::shared_ptr<TNode> &value) override;
        std::shared_ptr<TNode> GetParent() override;

        void SetExit(const std::shared_ptr<TNode> &value) override;
        std::shared_ptr<TNode> GetExit() override;

        void SetFail(const std::shared_ptr<TNode> &value) override;
        std::shared_ptr<TNode> GetFail() override;

        bool IsEnd() override;

        void SetPattern(const int value) override;
        int GetPattern() override;

        void SetSize(const int value) override;
        int GetSize() override;
    };
}

#endif
