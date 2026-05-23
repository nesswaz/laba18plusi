#include "h18.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <limits>

void AddToTree(Node*& tree, int data) { 
    if (!tree) {
        tree = new Node(data);
        return;
    }
    if (data < tree->key) AddToTree(tree->left, data);
    else AddToTree(tree->right, data);
}

Node* InputFromKeyboard() {
    Node* root = nullptr;
    int n, val;
    std::cout << "Введите количество элементов: ";
    if (!(std::cin >> n)) return nullptr;
    std::cout << "Введите " << n << " элементов: ";
    for (int i = 0; i < n; i++) {
        std::cin >> val;
        AddToTree(root, val);
    }
    return root;
}

void PrintTree(Node* root, int level) {
    if (!root) return;
    PrintTree(root->right, level + 1);
    for (int i = 0; i < level; i++) std::cout << "    ";
    std::cout << root->key << std::endl;
    PrintTree(root->left, level + 1);
}
//-------------------------------------------------------------

void TurnIntoList(Node* curr, Node*& prev, Node*& head) { //1
        if (!curr) return;
        TurnIntoList(curr->left, prev, head); //рекурсивно идем влево к самому маленькому значению
        if (!prev) head = curr; //если это самый первый - левый узел, то делаем его головой списка
        else {
            prev->right = curr; //соединяем предыдущий узел с текущим
            curr->left = prev; //соединяем текущий узел с предыдущим
        }
        prev = curr;
        TurnIntoList(curr->right, prev, head); //рекурсивно идем вправо до конца
}

void TheFun1() {
    Node* root = InputFromKeyboard();
    if (!root) return;

    std::cout << "\nДерево:\n";
    PrintTree(root, 0); 

    Node *head = nullptr, *prev = nullptr; //ставим указатели на пустые значения
    TurnIntoList(root, prev, head);
    
    std::cout << "Результат: ";
    while(head) { //проход по получ списку
        std::cout << head->key << (head->right ? " " : ""); //печатаем ключи
        head = head->right; //переход к следующему элементу
    }
    std::cout << std::endl;
}
//--------------------------------------------------

void TheFun3() {
    Node* root = InputFromKeyboard();
    if (!root) return;
    std::cout << "\nДерево:\n";
    PrintTree(root, 0);
    Trees it(root); //создаем объект итератор и передаем ему дерево
    std::cout << "Обход: ";
    while(it.CheckNext()) {  //пока в итераторе есть элементы
        std::cout << it.next() << " "; //получаем следующий элемент и печатаем
    }
    std::cout << std::endl;
}
//------------------------------------------
void TheFun12() {
    Node* root = InputFromKeyboard();
    if (!root) return;

    std::cout << "\nДерево:\n";
    PrintTree(root, 0);

    Trees tree;
    tree.setRoot(root);

    int s;
    std::cout << "Введите сумму S: ";
    std::cin >> s;

    std::cout << "\nРезультаты:\n";
    tree.BeginFindSum(s); 
}
