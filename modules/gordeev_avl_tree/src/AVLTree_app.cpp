// Copyright 2022 Ryabtsev Maksim

#include "include/AVLTree_app.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "include/AVLTree.h"

CLPApplication::CLPApplication() {}

std::string CLPApplication::operator()(int argc, const char** argv) {
  std::ostringstream os;

  if (argc == 1) {
    return this->argument_error();
  }
  if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
    return this->help();
  }
  int i = 1;

  if (std::string(argv[i]) == "--test1" || std::string(argv[i]) == "-t1") {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(atoi(argv[2]));
    AVLTree::node q = AVLTree::node(atoi(argv[3]));
    AVLTree::node c = AVLTree::node(atoi(argv[4]));
    AVLTree::node a = AVLTree::node(atoi(argv[5]));
    AVLTree::node b = AVLTree::node(atoi(argv[6]));
    p.left = &q;
    p.right = &c;
    q.left = &a;
    q.right = &b;
    avlTree.rotateright(&p);
    // ASSERT_EQ(p.left->key, 3);
    os << p.left->key;
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test2" || std::string(argv[i]) == "-t2") {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(4);
    avlTree.insert(&p, atoi(argv[2]));
    avlTree.insert(&p, atoi(argv[3]));
    avlTree.insert(&p, atoi(argv[4]));
    avlTree.insert(&p, atoi(argv[5]));
    avlTree.insert(&p, atoi(argv[6]));
    avlTree.balance(&p);

    // ASSERT_EQ(avlTree.bfactor(&p), 0);
    os << avlTree.bfactor(&p);
    std::cout << os.str() << std::endl;
    return "success";
  }
  if (std::string(argv[i]) == "--test3" || std::string(argv[i]) == "-t3") {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(4);
    avlTree.insert(&p, atoi(argv[2]));
    avlTree.insert(&p, atoi(argv[3]));
    avlTree.insert(&p, atoi(argv[4]));
    avlTree.insert(&p, atoi(argv[5]));
    avlTree.insert(&p, atoi(argv[6]));
    avlTree.balance(&p);

    // ASSERT_EQ(avlTree.findmin(&p)->key, 1);
    os << avlTree.findmin(&p)->key;
    std::cout << os.str() << std::endl;
    return "success";
  }
  return "success";
}

std::string CLPApplication::help() {
  std::string help = "This program considers the integral";
  return help;
}

std::string CLPApplication::argument_error() {
  std::string error = "Invalid argument amount, try --help or -h commands";
  return error;
}
