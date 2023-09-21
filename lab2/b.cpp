#include <iostream>
using namespace std;

struct Node {
  string word;
  Node* next;

  Node() {}

  Node(string word) {
    this->word = word;
    this->next = NULL;
  }
};


Node* cyclicShift(Node* head, int k) {
    Node *cur = head;
    Node *tail;
    while (cur -> next != NULL) {
        cur = cur->next;
        tail = cur;
    }
    
    while (k--) {
        Node *tmp = head -> next;
        tail -> next = head;
        head -> next = NULL;
        head = tmp;
        tail = tail->next;
    }
    return head;
}

void print(Node* head) {
  Node* cur = head;
  while (cur != NULL) {
    cout << cur->word << " ";
    cur = cur->next;
  }
  cout << endl;
}

int main() {
  int n; cin >> n;
  int k; cin >> k;
  Node* head;
  Node* cur;
  for (int i = 0; i < n; i++) {
    string word; cin >> word;
    if (i == 0) {
      head = new Node(word);
      cur = head;
    } else {
      cur->next = new Node(word);
      cur = cur->next;
    }
  }

  head = cyclicShift(head, k);
  print(head);
}