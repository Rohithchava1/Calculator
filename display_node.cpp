#include "display_node.h"
#include "ast_node.h"
#include "iostream"

using namespace std;
ASTResult DisplayNode::apply(const ASTResult &left, const ASTResult &right) {
  return ASTResult();
}

ASTResult DisplayNode::eval(RefEnv *env) {
  ASTResult result = right()->eval(env);

  if(result.type == ASTResult::INT) {
      std::cout << result.value.i << std::endl;
    } else if(result.type == ASTResult::REAL) {
      std::cout << result.value.r << std::endl;
    }
  result.type = ASTResult::VOID;
  return result;
}

