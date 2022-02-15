#include <example.hpp>

#include "iostream"
#include "secex.h"
// стивен прат 10 глава
// копирование - реализуем оператор копирования, в конце надо писать delete
// 1. конструктор по умолчанию
// 2. конструктор с одним параметром (explicit)
// 3. во всех конструкторах список инициализации
// 4. move swap forward!
// 5. конструкторы копирования - операторы копирования
// 6. конструкторы перемещения - оператор перемещения
// 7. основные операции. 1-ый через копирование, 2-ой через перемещение.
// 8. pop() просто выкинуть элемент
// 9. head() должен выдать верх стека
//
// 2 задание
// 1. push_emplace  - надо использовать (std::forward!!!!!!)
// 2.Обрабатывает все типы данных
// Шаблон с переменным количеством параметров.
//
// Оформлять как Stack1  Stack2
// 2 хедера hpp
//

class Item {
 private:
  int f;
  double ft;

 public:
  Item() {
    f = -1;
    ft = -1;
  }
  Item(int fi) {
    this->f = fi;
    this->ft = 0;
  }
  Item(int fi, double fth) {
    this->f = fi;
    this->ft = fth;
  }
  bool operator!() const {
    if (this->f != -1) {
      return false;
    }
    if (this->ft != -1) {
      return false;
    }
    return true;
  };
  Item& operator=(Item* right) noexcept {
    f = right->f;
    ft = right->ft;
    return *this;
  }
  Item& operator=(const Item& right) = default;
  //  Item operator*(Item* item){
  //    this->f = item->f;
  //    this->ft = item->ft;
  //  }
  void print() const {
    std::cout << f << std::endl;
    std::cout << ft << std::endl;
  }
};

int main() {
  //  TODO 1 ex
  Stack<int> stack;
  const int& left = 50;
  stack.push(10);
  std::cout << stack.head() << std::endl;

  stack.push(20);
  std::cout << stack.head() << std::endl;
  stack.push(30);
  std::cout << stack.head() << std::endl;
  stack.push(40);
  std::cout << stack.head() << std::endl;
  stack.push(left);
  std::cout << stack.head() << std::endl;
  stack.pop();
  std::cout << stack.head() << std::endl;
  stack.pop();
  std::cout << stack.head() << std::endl;
  stack.pop();
  std::cout << stack.head() << std::endl;
  std::cout << "Stack " << stack.head() << std::endl;
  Stack<int> stack1;
  stack1.push(333);
  //   Оператор перемещения.
  stack1 = Stack<int>(444);
  std::cout << "Stack " << stack.head() << std::endl;
  std::cout << "Stack1 " << stack1.head() << std::endl;
  //  TODO 1 ex END
  //  TODO 2 ex
  //  StackSec<Item> stackSec(Item{11});
  //  stackSec.head().print();
  //  stackSec.push_emplace(22, 22.0);
  //  stackSec.head().print();
  //  stackSec.push_emplace(33, 33.0);
  //  stackSec.head().print();
  //  stackSec.push_emplace(44, 44.0);
  //  stackSec.head().print();
  //  Item val = stackSec.pop();
  //  val.print();
  //  stackSec.head().print();
  //  stackSec.push_emplace(55);
  //  stackSec.head().print();
}
