#include "input_node.h"
#include "ref_node.h"
#include <iostream>
using namespace std;

ASTResult InputNode::apply(const ASTResult &lhs, const ASTResult &rhs) {
  return ASTResult();
}

ASTResult InputNode::eval(RefEnv *env) {
  ASTResult result;
  string input;
  result.type = ASTResult::REAL;
  RefNode *ref_node = (RefNode *)right();
  if (left()) {
    left()->eval(new RefEnv());
    cin >> input;
  } else {
    cout << ref_node->name() << "=";
    cin >> input;
  }
  result.value.r = stof(input);
  ref_node->assign(new RefEnv(), result);
  ASTResult res;
  res.type = ASTResult::VOID;
  return res;
}