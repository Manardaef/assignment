#include <iostream>
using namespace std;

template<class T>
struct Node {
    T value;
    Node* prev;
    Node* next;

};

template<class T>
class DoummyHeadDoublyLinkedList {

private:
    Node<T>* head;
    int counter = 0;
public:
    DoummyHeadDoublyLinkedList() {
        head = new Node<T>;
        head->next = head;
        head->prev = head;
        
    }

    bool IsEmpty() { return head->next == head; }


    void Print() {
        Node<T>* current = head->next;

        while (current != head) {
            cout << current->value << " ";
            current = current->next;
        }
    }

    void Insert(T target) {
        Node<T>* current = head->next;

        Node<T>* newNode = new Node<T>;
        newNode->value = target;

        while (current != head) {
            if (current->value < target)
                current = current->next;
            else
                break;
        }

        newNode->next = current;
        newNode->prev = current->prev;

        current->prev = newNode;
        newNode->prev->next = newNode;
        counter++;
    }
    int indexFromEnd(int index) {
        if (index > counter) {
            return -1;
        }
        Node<T>* curr = head->next;
        for (int i = 1; i <= counter - index; i++) {  
            curr = curr->next;

        }
        return curr->value;
        //O(counter-index)=O(n)-----> TC
        //O(1)-----------> SC
    }
    void inPlaceReverse() {
        Node<T>* first;
        Node<T>* second;
        first = head->next;
        second = head->next;

        for (int i = 1; i < counter ; i++) {
            second = second->next;
        }
        for (int i = 1; i <= counter / 2; i++) {
            swap(first->value, second->value);
            first = first->next;
            second = second->prev;
        }
    }

};



int main() {
    DoummyHeadDoublyLinkedList<int> list;

    // Insert some elements
    list.Insert(5);
    list.Insert(10);
    list.Insert(3);
    list.Insert(6);
    list.Insert(1);
    // Print the list
    cout << "Original List:" << endl;
    list.Print();

   cout<<endl<<"The index : "<< list.indexFromEnd(5) << endl;
    list.inPlaceReverse();
    cout  << "the InPlaceReverse: ";
    list.Print();
    return 0;
}