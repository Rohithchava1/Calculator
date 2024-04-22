#include "input_node.h"
#include "ref_node.h"
#include <iostream>

// must have this to satisfy the pure virtual function
ASTResult InputNode::apply(const ASTResult &lhs, const ASTResult &rhs) {
  // This function is never called
  return ASTResult();
}
// evaluate the assignment
ASTResult InputNode::eval(RefEnv *env) {
 
  ASTResult obj;
  std::string input;
  obj.type = ASTResult::REAL;
  RefNode *ref = (RefNode *) right();



  if(left()){
    left()->eval(env);
    getline(std::cin, input);
  } else {
    std::cout << ref->name() <<"=";
    getline(std::cin, input);
  }
  
  
  obj.value.r = std::stof(input);
  ref->assign(env, obj);
  ASTResult resultn;
  resultn.type = ASTResult::VOID;
  return resultn;
}
