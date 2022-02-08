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
  Stack(){
      //    this->start = new Element<T>(NULL, nullptr);
      //      start->value = NULL;
      //      start->link = nullptr;
      this->last = (Element<T>*)malloc(sizeof(Element<T>));
      this->start = (Element<T>*)malloc(sizeof(Element<T>));
  };
  Stack(T valueStart) {
    this->last = (Element<T>*)malloc(sizeof(Element<T>));
    this->start = (Element<T>*)malloc(sizeof(Element<T>));
    last->value = valueStart;
    last->link = NULL;
    this->start = this->last;
  }
  void push(T&& value) {
//    if (this->start->value == NULL) {
//      last->value = std::move(value);
//      last->link = NULL;
//      this->start = this->last;
//      return;
//    }
    Element<T>* temp;
    Element<T>* oldlink;
    temp = (Element<T>*)malloc(sizeof(Element<T>));
    oldlink = last->link;
    last->link = temp;
    temp->value = std::move(value);
    temp->link = oldlink;
    this->last = temp;
    //    if (start->link == NULL) {
    //      start->value = std::move(*value);
    //      start->link = nullptr;
    //      return;
    //    } else {
    //      Element<T>* goElem;
    //      auto newElem = new Element<T>(std::move(*value), nullptr);
    //      goElem = start;
    //      while (goElem->link != nullptr) {
    //        goElem = goElem->link;
    //      }
    //      *goElem->link = newElem;
    //      last = newElem;
    //      return;
  };

  void push(const T& value) {
    Element<T>* temp;
    Element<T>* oldlink;
    temp = (Element<T>*)malloc(sizeof(Element<T>));
    oldlink = last->link;
    last->link = temp;
    temp->value = *value;
    temp->link = oldlink;
    this->last = temp;
    //  if (start->value == NULL) {
    //    start->value = *value;
    //    start->link = nullptr;
    //    return;
    //  } else {
    //    Element<T>* goElem;
    //    auto newElem = new Element<T>(*value, nullptr);
    //    goElem = start;
    //    while (goElem->link != nullptr) {
    //      goElem = goElem->link;
    //    }
    //    *goElem->link = newElem;
    //    last = newElem;
    //    return;
    //  }
  };
  void pop() {
    Element<T>* temp;
    temp = this->start;
    while (temp->link != this->last) {
      temp = temp->link;
    }
    temp->link = last->link;
    free(last->link);
    this->last = temp;
    //    Element<T> goElem(NULL, this->start->link);
    //    Element<T>* tempElem = nullptr;
    //    while (goElem.link != this->last) {
    //      tempElem = goElem.link;
    //      goElem = goElem.link;
    //    }
    //    if (this->last != nullptr) {
    //      delete[](this->last);
    //      this->last = tempElem;
    //    }
    //    return;
  };
  const T& head() const { return this->last->value; };
};

auto example() -> void;

#endif  // INCLUDE_EXAMPLE_HPP_
