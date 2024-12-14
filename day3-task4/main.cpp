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
            cout << "Empty or single item!" << endl;
            return;
        }

        bool swapped;
        Node *current;

        do {
            swapped = false;
            current = head;

            while (current->next) {
                if (current->data > current->next->data) {

                    Node* nextNode = current->next;

                    current->next = nextNode->next;
                    if(nextNode->next) {
                        nextNode->next->prev = current;
                    }

                    nextNode->prev = current->prev;
                    if(current->prev) {
                        current->prev->next = nextNode;
                    }

                    current->prev = nextNode;
                    nextNode->next = current;

                     if (current == head) {
                        head = nextNode;
                    }

                     if (current->next == nullptr) {
                        tail = current;
                    }

                    current = nextNode;
                    swapped = true;

                } else {
                    current = current->next;
                }
            }
        } while (swapped);
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
