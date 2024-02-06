#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
struct Node {
    string data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void insertAtPosition(string value, int position) {
        if (position <= 0) {
            cout << "Неправильный номер\n";
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
            return;
        }
        if (position == 1) {
            newNode->prev = NULL;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else {
            Node* temp = head;
            int currentPosition = 1;
            while (currentPosition < position - 1 && temp != NULL) {
                temp = temp->next;
                currentPosition++;
            }
            if (temp == NULL) {
                cout << "Неправильный номер\n";
                delete newNode;
                return;
            }
            newNode->prev = temp;
            newNode->next = temp->next;

            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;

            if (temp == tail) {
                tail = newNode;
            }
        }
    }

    void display() {
        if (head == NULL) {
            cout << "Список пуст\n";
            return;
        }

        Node* temp = head;
        cout << "Ваш список: ";
        while (temp != NULL) {
            cout << "\"" << temp->data << "\" ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DoublyLinkedList List;
    string value;
    int position, size;
    cout << "Введите количество строк: ";
    cin >> size;
    cin.ignore();

    for (int i = 1; i < size + 1; i++) {
        cout << "Введите строку для добавления: ";
        getline(cin, value);
        List.insertAtPosition(value, i);
    }
    List.display();

    cout << "\nВведите новую строку для добавления: ";
    getline(cin, value);
    do {
        cout << "Введите номер: ";
        cin >> position;
        if (position < 1 || position > size + 1) {
            cout << "Ошибка. Неверный номер\n";
        }
    } while (position < 1 || position > size + 1);

    List.insertAtPosition(value, position);
    List.display();
}
