#include <iostream>
struct Node{
  int data;
  Node* next;
  explicit Node(int d, Node *n = nullptr) : data{d}, next{n} {}
};

void reverse(Node* curr, Node* prev){
  if (curr->next == nullptr){
    curr->next = prev;
    return;
  } else{
    reverse(curr->next, curr);
    curr->next = prev;
  }
}

int main(){
  Node *head = new Node(0);
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  head->next = n1;
  n1->next = n2;
  n2->next = n3;
  reverse(head, nullptr);
  std::cout << head->next << ' ' << n1->next->data << ' ' << n2->next->data << ' ' << n3->next->data;
  delete head;
  delete n1;
  delete n2;
  delete n3;
}
