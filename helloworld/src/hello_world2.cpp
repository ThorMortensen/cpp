#include "hello_world2.hpp"
#include <iostream>


hello_world2::hello_world2() {

}

hello_world2::~hello_world2() {

}

void hello_world2::print(){
  int foo = true;

  if(foo){
    std::cout << "hello world from hello world 2" << std::endl;
    foo++;

  }

}
