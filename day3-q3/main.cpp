#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class LinkedList {

public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void insertEnd(int data) {
        Node* node = new Node(data);

        if(head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        size++;
    }

    void bubbleSort() {
        if(head == nullptr || head->next == nullptr) {
            cout << "Empty or one item!" << endl;
            return;
        }

        bool swapped;
        Node* current;
        Node* lastSortedItem = nullptr;

        do {
            swapped = false;
            current = head;

            while(current-> next != lastSortedItem) {
                if(current->data > current->next->data) {
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }

                current = current->next;
            }
            lastSortedItem = current;
        } while(swapped);

    }



     void display() {
        Node* current = head;
        while(current != NULL) {
            cout << current->data << "\t";
            current = current->next;
        }
    }



};


int main()
{
     LinkedList list;

     list.bubbleSort();


     list.insertEnd(16);

     list.bubbleSort();


    list.insertEnd(64);
    list.insertEnd(324);
    list.insertEnd(25);
    list.insertEnd(1322);
    list.insertEnd(22);
    list.insertEnd(141);
    list.insertEnd(90);

    cout << "Before: \n";
    list.display();
    cout << " \n --------------------------------- \n" << endl;
    list.bubbleSort();
    cout << " \n After Bubble Sort: \n";
    list.display();

    return 0;
}
