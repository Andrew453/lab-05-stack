#include <example.hpp>
#include "iostream"
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
int main() {
  Stack<int> stack(1);
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.push(40);
  std::cout << stack.head()<< std::endl;
  stack.pop();
  std::cout << stack.head()<< std::endl;
  stack.pop();
  std::cout << stack.head()<< std::endl;
 stack.pop();
  std::cout << stack.head()<< std::endl;
//  stack.
}