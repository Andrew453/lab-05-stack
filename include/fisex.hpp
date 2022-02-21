// Copyright 2020 Andrew Prokushev <senior.prockuschev2017@yandex.ru>

#ifndef INCLUDE_FISEX_HPP_
#define INCLUDE_FISEX_HPP_
#include <stdexcept>
#include <utility>

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
  bool notDeleted;

 public:
  Stack() {
    start = new Element<T>;
    last = start;
    notDeleted = true;
  }

  explicit Stack(T&& valueStart) {
    notDeleted = true;
    start = new Element<T>;
    start->value = std::move(valueStart);
    start->link = nullptr;
    last = start;
  }
  Stack(Stack&& value){
    start = std::move(value.start);
    last = std::move(value.last);
  }

  explicit Stack(T& value) = delete;

  ~Stack() {
    Element<T>* temp;
    if (notDeleted) {
      while (start->link) {
        temp = start;
        while (temp->link != last) {
          temp = temp->link;
        }
        if (last) {
          delete (last);
          temp->link = nullptr;
        }
        last = temp;
      }
      if (last) {
        delete (last);
      }
      notDeleted = false;
    }
  }

  void push(T&& value) {
    if (!start->value) {
      start->value = std::move(value);
      start->link = nullptr;
      last = start;
      return;
    }
    Element<T>* temp = new Element<T>;
    last->link = temp;
    temp->value = std::move(value);
    temp->link = nullptr;
    last = temp;
  }

  void push(const T& value) {
    if (!start->value) {
      last->value = value;
      last->link = nullptr;
      start = last;
      return;
    }
    Element<T>* temp = new Element<T>;
    last->link = temp;
    temp->value = value;
    temp->link = nullptr;
    last = temp;
  }

  void pop() {
    if (!start->link) {
      return;
    } else {
      Element<T>* temp = start;
      while (temp->link != last) {
        temp = temp->link;
      }
      if (last) {
        delete (last);
        temp->link = nullptr;
      }
      last = temp;
      return;
    }
  }

  const T& head() const { return last->value; }

  Stack<T>& operator=(const Stack<T>& right) = delete;

  Stack<T>& operator=(Stack<T>&& right) noexcept {
    if ((start != right.start) || (last != right.last)) {
//      ~Stack();
      std::swap(start, right.start);
      std::swap(last, right.last);
//      start = std::move(right.start);
//      last = std::move(right.last);
      notDeleted = true;
    }
    return *this;
  }
};

auto example() -> void;

#endif  // INCLUDE_FISEX_HPP_
