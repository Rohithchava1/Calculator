#include "squareroot_node.h"
#include "ref_node.h"
#include <cmath>
#include <iostream>

ASTResult SquarerootNode::apply(const ASTResult &lhs, const ASTResult &rhs) {
  return ASTResult();
}

ASTResult SquarerootNode::eval(RefEnv *env) {
  ASTResult result = right()->eval(env);
  if (result.type == ASTResult::REAL) {
    result.value.r = sqrt(result.value.r);
  } else if (result.type == ASTResult::INT) {
    result.value.r = sqrt(result.value.i);
  }
  result.type = ASTResult::REAL;
  return result;
}
