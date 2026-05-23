#pragma once
#include <iostream>
#include <limits>
#include <algorithm>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <stack>
#include <vector>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

class Trees {
private:
    Node* root; 
    void PrintTree(Node* node, int level) {
        if (!node) return;
        PrintTree(node->right, level + 1);
        for (int i = 0; i < level; i++) std::cout << "    ";
        std::cout << node->key << std::endl;
        PrintTree(node->left, level + 1);
    }

    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
    
    
    std::stack<Node*> s; //хранения путей

    void LKP(Node* node) {  
        while (node != nullptr) {
            s.push(node); //добавляем каждый узел в стек
            node = node->left; //идем влево до конца
        }
    }
   
    void findSum(Node* n, int s, std::vector<int>& p, bool& found) { //поиск суммы //3
        if (!n) return;
        p.push_back(n->key); //добавляем узел в путь
        int t = 0; //переменная для накапливания суммы элементов
        for (int i = p.size() - 1; i >= 0; i--) { //идем по вектору с конца к началу
            t += p[i]; //суммирование знач узлов текущей ветки
            if (t == s) {
                found = true; //флажок для ошибки, если нашли хоть какую-то сумму
                std::cout << "Путь: ";
                for (int j = i; j < p.size(); j++) 
                    std::cout << p[j] << " "; //выводим эти значения
                std::cout << std::endl;
            }
        }
        findSum(n->left, s, p, found); //переход в лево
        findSum(n->right, s, p, found); //переход вправо
        p.pop_back(); //когда вернулись удаляем узел
    }

public:
    Trees() : root(nullptr) {}
    ~Trees() { clear(root); }

    void CheckTree() {
        if (!root) std::cout << "Дерево пусто" << std::endl;
        else PrintTree(root, 0);
    }

    Node* task1() { //1
        if (!root) return nullptr;
        Node* head = nullptr; //ставим указатель голову на пустой элемент
        Node* prev = nullptr; //ставим указатель прев на пустой элемент
        TurnIntoList(root, prev, head); //вызов функции
        root = nullptr; //ставим корень на нулевой 
        return head; //возвращаем голову
    } 
    //-----------------------------------------------------------//2

    Trees(Node* root) {
        LKP(root);
    }

    bool CheckNext() { //2
        return !s.empty();
    }

    int next() { //заполнение элементов в стек по левым веткам //2
        Node* curr = s.top(); //просматриваем верхний узел из стека
        s.pop(); //удаляем его
        int result = curr->key; //запоминаем значение
        if (curr->right != nullptr) { //если есть правый элемент 
            LKP(curr->right); //записываем его в левую ветку
        }
        return result;
    }
    //----------------------------------------------//3
    void BeginFindSum(int s) { //создание списка и начало поиска //3
        if (!root) {
            std::cout << "Дерево пусто" << std::endl;
            return;
        }
        std::vector<int> p; //вектор для хранения путей
        bool found = false; //флажочек для ошибки
        findSum(root, s, p, found);
        if (!found) { 
            std::cout << "Ошибка: " << s << " не найдено" << std::endl;
        }
    }
    void setRoot(Node* r) { 
        if (root && root != r) clear(root); //если было старое дерево удаляем чтобы не запутаться и чтобы не было ошибки
        root = r; 
    }
};

void AddToTree(Node*& tree, int data);
Node* InputFromKeyboard();
void TurnIntoList(Node* curr, Node*& prev, Node*& head);

void TheFun1();
void TheFun3();
void PrintTree(Node* root, int level = 0);
void TheFun12();