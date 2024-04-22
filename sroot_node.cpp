
#include "sroot_node.h"
#include "ref_node.h"
#include <iostream>
#include "cmath"

// must have this to satisfy the pure virtual function
ASTResult SrootNode::apply(const ASTResult &lhs, const ASTResult &rhs) {
  // This function is never called
  return ASTResult();
}

ASTResult SrootNode::eval(RefEnv *env) {
  
  ASTResult result = right()->eval(env);

  if(result.type == ASTResult::REAL) {
      result.value.r = sqrt(result.value.r);
  } else if(result.type == ASTResult::INT) {
      result.value.r = sqrt(result.value.i);
  }
  result.type = ASTResult::REAL;
  return result;
}
