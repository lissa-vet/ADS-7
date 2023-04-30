// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <iostream>
#include <string>

template<typename T>
class TPQueue {
  private: 
      struct Queue {
        T val;
        Queue* next;
      };
      Queue* head;

  public: 
    TPQueue() {
      head = nullptr;
    }

    bool Empty() {
      return head == nullptr;
    }

    T pop() {
      if (Empty()) {
        throw std::string("Queue is Empty((");
      } else {
        Queue* Queue = head->next;
        T value = head->val;
        delete head;
        head = Queue;
        return value;
      }
    }

    void push(const T& value) {
      Queue* Queue_ = new Queue;
      Queue_->val = value;
      Queue_->next = nullptr;
      if (Empty()) {
        head = Queue_;
        return;
      } else if (value.prior <= head->val.prior) {
        Queue* temp = head;
        while (temp->next != nullptr && temp->next->val.prior > value.prior)
          temp = temp->next;
        Queue_->next = temp->next;
        temp->next = Queue_;
      } else {
        Queue_->next = head;
        head = Queue_;
      }
    }

    ~TPQueue() {
      while (head) {
        Queue* temp = head->next;
        delete head;
        head = temp;
      }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
