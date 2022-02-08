// Copyright 2021 Your Name <your_email>

#include <stdexcept>

#include <example.hpp>

auto example() -> void { throw std::runtime_error("not implemented"); }

//template <typename T>
//Stack<T>::Stack() {
//  start->value = NULL;
//  start->link = nullptr;
//}
//template<typename T>
//void Stack<T>::push(T &&value) {
//  if (start->value == NULL){
//    start->value = std::move(*value);
//    start->link = nullptr;
//    return;
//  } else {
//    Element<T>* goElem;
//    auto newElem = new Element<T>(std::move(*value), nullptr);
//    goElem = start;
//    while (goElem->link != nullptr) {
//      goElem = goElem->link;
//    }
//    *goElem->link = newElem;
//    last = newElem;
//    return;
//  }
//}
//
//template <typename T>
//void Stack<T>::push(const T &value) {
//  if (start->value == NULL){
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
//}

//template<typename T>
//void Stack<T>::pop() {
//  Element<T> goElem(NULL,this->start->link);
//  Element<T>* tempElem = nullptr;
//  while (goElem.link != this->last) {
//    tempElem = goElem.link;
//    goElem = goElem.link;
//  }
//  if (this->last != nullptr){
//    delete[](this->last);
//    this->last = tempElem;
//  }
//  return;
//}
//template<typename T>
//const T& Stack<T>::head() const {
//  return this->last;
//}

//template <typename T>
//Stack<T>::

