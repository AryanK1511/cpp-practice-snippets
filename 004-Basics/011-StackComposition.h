// Copmosition in stack
#ifndef SDDS_STACK_H
#define SDDS_STACK_H

#include <iostream>

namespace sdds {
    template <typename T>
    class Stack;

    template <typename T>
    class Node {
        Node<T>* m_next = nullptr;
        static size_t num;
        T m_data;

        Node(T data, Node<T>* next) {
            m_next = next;
            m_data = data;
            num++;
        }

        friend class Stack<T>;

        ~Node() {
            num--;
        }
    };

    template <typename T>
    size_t Node<T>::num = 0;

    template <typename T>
    class Stack {
        Node<T>* top {};
    public:
        Stack<T>& push(T data) {
            top = new Node<T>(data, top);
            return *this;
        }

        T pop() {
            T val;
            val  = top->m_data;
            Node<T>* todel = top;
            top = top->m_next;
            delete todel;
            return val;
        }

        bool isEmpty() {
            return top == nullptr;
        }

        operator bool() {
            return top != nullptr;
        }

        virtual ~Stack() {
            Node<T>* todel = top;
            while (top != nullptr) {
                top = top->m_next;
                delete todel;
                todel = top;
            }
        }

        size_t depth() {
            return Node<T>::num;
        }
    };
}

#endif // SDDS_STACK_H