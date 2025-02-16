#include <iostream>
#include <stdexcept>
using namespace std;

class student {
public:
  string name;
  int age;

  student(string name, int age) {
    this->name = name;
    this->age = age;
  }
  void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
  T *value;
  Node<T> *next;
  Node(T *value) {
    this->value = value;
    this->next = NULL;
  }
  void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
  int length;
  Node<T> *head;

public:
  LinkedList(T *value) {
    this->length = 1;
    this->head = new Node<T>(value);
  }
  void add(T *value) {
    Node<T> *newNode = new Node<T>(value);
    Node<T> *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    length++;
  }

  void addhead(T *value) {
    Node<T> *newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
    length++;
  }

  void delfirst() {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    length--;
  }

  void dellast() {
    Node<T> *temp = head;
    while (temp->next != NULL)
      temp = temp->next;
    delete temp;
    length--;
  }

  void deleteNode(int index) {
    if (index == 0) {
      delfirst();
    } else if (index == length - 1) {
      dellast();
    } else if (index > 0 && index < length) {
      Node<T> *curr = head;
      Node<T> *temp = NULL;
      for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
      }
      temp = curr;
      curr = curr->next;
      temp->next = curr->next;
      length--;
    } else {
      throw std::runtime_error("Index out of bounds");
    }
  }

  void insert(int index, T *value) {
    // TODO:Write a function to insert a new node at a give index. Reuse the
    // pre-written functions for edge cases. Account for missing index
    Node<T> *newNode = new Node<T>(value);
    if (index == 0) {
      addhead(value);
    } else if (index > 0 && index < length) {
      Node<T> *curr = head;
      Node<T> *temp = NULL;
      for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
      }
      temp = curr;
      curr = curr->next;
      temp->next = newNode;
      newNode->next = curr;
      length++;
    } else {
      throw std::runtime_error("Index out of bounds");
    }
  }

  void reverselist() {
    // TODO:Write a function to reverse the list using the logic from the slide.
    Node<T> *prev = NULL;
    Node<T> *curr = head;
    Node<T> *next;
    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
  }

  void print() {
    cout << "Printing List.." << endl;
    Node<T> *temp = head;
    while (temp != NULL) {
      temp->print();
      temp = temp->next;
    }
  }
};

int main() {
  student *s1 = new student("A", 20);
  student *s2 = new student("B", 21);
  student *s3 = new student("C", 22);
  student *s4 = new student("D", 27);
  LinkedList<student> *ll = new LinkedList<student>(s1);
  ll->add(s2);
  ll->addhead(s3);
  cout << "BEFORE OPS: " << endl;
  ll->print();
  cout << endl;

  cout << "delnode tests:  " << endl;
  ll->deleteNode(1);
  ll->print();
  cout << endl;

  cout << "insert tests:  " << endl;
  ll->insert(1, s1);
  ll->print();
  ll->insert(2, s4);
  ll->print();
  cout << endl;

  cout << "reverse test: " << endl;
  ll->print();
  ll->reverselist();
  ll->print();
  cout << endl;
}
