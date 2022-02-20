// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_
#include <stdexcept>

template <typename T>
struct Element {
  T value;
  Element* link;
};

template <typename T>
class Stack {
 private:
  Element<T>* last;
  Element<T>* start;

 public:
  Stack() {
    this->last = new Element<T>;
    this->start = new Element<T>;
  };
  explicit Stack(T valueStart) {
    this->last = new Element<T>;
    this->start = new Element<T>;
    last->value = valueStart;
    last->link = NULL;
    this->start = this->last;
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
    //    temp = (Element<T>*)malloc(sizeof(Element<T>));
    temp = new Element<T>;
    oldlink = last->link;
    last->link = temp;
    temp->value = std::move(value);
    temp->link = oldlink;
    this->last = temp;
  };

  void push(const T& value) {
    if (!this->start->value) {
      last->value = value;
      last->link = NULL;
      this->start = this->last;
      return;
    }
    Element<T>* temp;
    Element<T>* oldlink;
    temp = new Element<T>;
    oldlink = last->link;
    last->link = temp;
    temp->value = value;
    temp->link = oldlink;
    this->last = temp;
  };
  void pop() {
    Element<T>* temp;
    temp = this->start;
    while (temp->link != this->last) {
      temp = temp->link;
    }
    temp->link = last->link;
    delete (last);
    this->last = temp;
  };
  const T& head() const { return this->last->value; };
  Stack<T>& operator=(const Stack<T>& right) = delete;
  Stack<T>& operator=(Stack<T>&& right) {
    if (this->last == this->start) {
      delete (this->last);
    } else {
      delete (this->last);
      delete (this->start);
    }

    this->last = std::move(right.last);
    this->start = std::move(right.start);
    right.last = nullptr;
    right.start = nullptr;
    return *this;
  }
  ~Stack() {
//    TODO
  }
};

auto example() -> void;

#endif  // INCLUDE_EXAMPLE_HPP_
