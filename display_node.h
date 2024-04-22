#ifndef CALCULATOR_DISPLAY_NODE_H
#define CALCULATOR_DISPLAY_NODE_H

#include "binop_node.h" // Assuming you have an BinopNode class

class DisplayNode : public BinopNode {
public:
  virtual ASTResult eval(RefEnv *env);
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs);
};

#endif // CALCULATOR_DISPLAY_NODE_H
