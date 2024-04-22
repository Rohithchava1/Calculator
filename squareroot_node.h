#ifndef SQUAREROOT_NODE_H
#define SQUAREROOT_NODE_H
#include "binop_node.h"
class SquarerootNode : public BinopNode{
public:
 virtual ASTResult eval(RefEnv *env);
 virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs);
};

#endif