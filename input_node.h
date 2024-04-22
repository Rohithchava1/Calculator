#ifndef INPUT_NODE_H
#define INPUT_NODE_H
#include "binop_node.h"

class InputNode : public BinopNode{
public:
    virtual ASTResult eval(RefEnv *env);
    virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs);
};
#endif