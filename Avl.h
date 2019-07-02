/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T>
class Avl {
private:
  class Node {
  private:
    Node *left = nullptr;
    Node *right = nullptr; 
    T mElem;
    
    int getWeight() const {
      int leftWeight = 1;
      int rightWeight = 1;
      if (left != nullptr) {
        leftWeight = left->getWeight() + 1;
      }
      if (right != nullptr) {
        rightWeight = right->getWeight() + 1;
      }
      
      if (leftWeight > rightWeight) {
        return leftWeight;
      } else {
        return rightWeight;
      }
    }
    
    Node* rotate() {
      int leftWeight = (left == nullptr) ? 0 : left->getWeight();
      int rightWeight = (right == nullptr) ? 0 : right->getWeight();
      
      if (leftWeight - rightWeight > 1) {
        int leftLeftWeight = (left->left == nullptr) ? 0 : left->left->getWeight();
        int rightLeftWeight = (left->right == nullptr) ? 0 : left->right->getWeight();
        
        if (leftLeftWeight >= rightLeftWeight) {
          return simpleRotateRight();
        }
        else {
          return doubleRotateRight();
        }
      } 
      else if (rightWeight - leftWeight > 1) {
        int leftRightWeight = (right->left == nullptr) ? 0 : right->left->getWeight();
        int rightRightWeight = (right->right == nullptr) ? 0 : right->right->getWeight();
        
        if (rightRightWeight >= leftRightWeight) {
          return simpleRotateLeft();
        }
        else {
          return doubleRotateLeft();
        }
      }
      
      return this;
    }
    
    Node* simpleRotateLeft() {
      Node* newRoot = right;
      right = newRoot->left;
      newRoot->left = this;
      
      return newRoot;
    }
    
    Node* simpleRotateRight() {
      Node* newRoot = left;
      left = newRoot->right;
      newRoot->right = this;
      
      return newRoot;
    }
    
    Node* doubleRotateLeft() {
      right = right->simpleRotateRight();
      return simpleRotateLeft();
    }
    
    Node* doubleRotateRight() {
      left = left->simpleRotateLeft();
      return simpleRotateRight();  
    }
    
  public:
    Node(T Elem) : mElem(Elem) {}
    ~Node() {
      if (left != nullptr)
        delete left;
      if (right != nullptr)
        delete right;
    }
    
    Node* insert(T& Elem) {
      if (Elem < mElem) {
        if (left == nullptr) {
          left = new Node(Elem);
        } else {
          left = left->insert(Elem);
        }
      } else {
        if (right == nullptr) {
          right = new Node(Elem);
        } else {
          right = right->insert(Elem);
        }
      }
      
      return rotate();
    }
    
    void print(unsigned indentation = 1) const {
      cout << std::string(indentation, ' ') << "elem: " << mElem << ", weight: " << getWeight() << endl;
      cout << std::string(indentation, ' ') << "left:" << endl;
      if (left == nullptr) {
        cout << std::string(indentation + 1, ' ') << "empty" << endl;
      } else {
        left->print(indentation+1);
      }
      
      cout << std::string(indentation, ' ') << "right:" << endl;
      if (right == nullptr) {
        cout << std::string(indentation + 1, ' ') << "empty" << endl;
      } else {
        right->print(indentation+1);
      }
    }
  };
  Node *root = nullptr;
public:
  Avl() {}
  ~Avl() {
    if (root != nullptr) {
      delete root;
    }
  }
  
  void insert(T Elem) {
    if (root == nullptr) {
      root = new Node(Elem);
    }
    else {
      root = root->insert(Elem);
    }
  }
  
  void print() const {
    if (root == nullptr) {
      cout << "AVL empty" << endl;
    } else {
      cout << "Printing AVL" << endl;
      cout << "root:" << endl;
      root->print();
    }
  }
};

int main()
{
    Avl<unsigned> avl;
    //avl.insert(10);
    //avl.insert(5);
    //avl.insert(3);
    //avl.insert(2);
    //avl.insert(1);
    //avl.insert(12);
    //avl.insert(13);
    //avl.insert(14);
    
    avl.insert(4);
    avl.insert(3);
    avl.insert(8);
    avl.insert(9);
    // avl.insert(2);
    avl.insert(5);
    avl.insert(6);
    avl.insert(7);
    avl.print();

    return 0;
}
