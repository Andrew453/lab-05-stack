//
// Created by prokiprok on 14.02.2022.
//

#ifndef TEMPLATE_SECEX_H
#define TEMPLATE_SECEX_H
#include <stdexcept>

#include "example.hpp"

template <typename T>
class StackSec {
 private:
  Element<T>* last;
  Element<T>* start;

 public:
  StackSec() {
    this->last = new Element<T>;
    this->start = new Element<T>;
  }
  explicit StackSec(T valueStart) {
    this->last = new Element<T>;
    this->start = new Element<T>;
    last->value = valueStart;
    last->link = NULL;
    this->start = this->last;
  }
  ~StackSec() {
    //  TODO
  }
  template <typename... Args>
  void push_emplace(Args&&... args) {
    if (!this->start->value) {
      last->value = std::move(T(std::forward<Args>(args)...));
      last->link = NULL;
      this->start = this->last;
      return;
    }
    Element<T>* temp;
    Element<T>* oldlink;
    temp = new Element<T>;
    oldlink = last->link;
    last->link = temp;
    temp->value = std::move(T(std::forward<Args>(args)...));
    temp->link = oldlink;
    this->last = temp;
  }
  void push(T&& value) {
    if (!this->start->value) {
      last->value = std::move(value);
      last->link = NULL;
      this->start = this->last;
      return;
    }
    Element<T>* temp;
    Element<T>* oldlink;
    temp = new Element<T>;
    oldlink = last->link;
    temp->value = std::move(value);
    temp->link = oldlink;
    this->last = temp;
  };
  const T& head() const { return this->last->value; };
  T pop() {
    Element<T>* temp;
    temp = this->start;
    while (temp->link != this->last) {
      temp = temp->link;
    }
    temp->link = last->link;
    T value = last->value;
    delete (last);
    this->last = temp;
    return value;
  };
 };

#endif  // TEMPLATE_SECEX_H
