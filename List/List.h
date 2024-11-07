//  Header file: List.h


#ifndef LIST_H
#define LIST_H


#include <iostream>
#include <stdexcept>


template <typename T>
class List
{
private:
    struct Node 
    {
        T data;
        Node* next;
        Node* prev;

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;
    size_t size;

public:

    // Конструктор
	List() : head(nullptr), tail(nullptr), size(0) {}


    // Деструктор
    ~List()
    {
        while (head) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }


    // Добавление элемента в лист
    void append(const T& value) 
    {
        Node* newNode = new Node(value);
        if (!head) 
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    

    // добавление элемента вперед листа
    void push(const T& value)
    {
        Node* newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }


    // Удалить первый элемент из списка
    void popf()
    {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        size--;
    }


    // Удалить последний элемент из списка
    void pop()
    {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        size--;
    }


    // Получить первый элемент списка
    T& front()
    {
        if (!head) throw std::out_of_range("List is empty");
        return head->data;
    }


    // Получить последний элемент списка
    T& back()
    {
        if (!tail) throw std::out_of_range("List is empty");
        return tail->data;
    }


    // Проверить, пуст ли список
    bool empty() const
    {
        return size == 0;
    }


    // Получить размер списка
    size_t getSize() const
    {
        return size;
    }


    // Вывести список
    void print() const 
    {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }


    // Оператор индексации
    T& operator[](const int index) 
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        Node* t = head;
        for (int i = 0; i < index; i++)
        {
            t = t->next;
        }
        return t->data;
    }
};

#endif