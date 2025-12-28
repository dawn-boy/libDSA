#include <iostream>

template <typename T>
struct Node{
    T data;
    Node* next;
};

template <typename T>
class LinkedList{
private:
    Node<T>* head;
public:
    LinkedList(){
        head = nullptr;
    }

    void push_front(const T value){
        Node<T>* node = new Node<T>{value, nullptr};
        node->next = head;
        head = node;
    }

    void push_back(const T value){
        Node<T>* node = new Node<T>{value, nullptr};

        if(head == nullptr) {
            head->next = node;
            return;
        }

        Node<T>* temp = head;
        while(temp->next != nullptr) temp = temp->next;
        temp->next = node;
    }
    void push_middle(const T value, const T addAfter){
        Node<T>* temp = head;
        while(temp->next != nullptr){
            if(temp->data == addAfter){
                Node<T>* newNode = new Node<T>{value, temp->next};
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }
    void remove(const T value){
        // 1. The Whole list is empty
        if(head == nullptr) return;

        // 2. the node to delete is HEAD
        if(head->data == value){
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // 3. searching for the node 
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        while(current != nullptr && current->data != value){
            prev = current;
            current = current->next;
        }


        // if nothing is found
        if(current == nullptr) {
            std::cout << "Element " << value << " was not found in the linked List." << std::endl;
            return;
        }

        // if found
        prev->next = current->next;
        delete current;
    }

    void show() const {
        Node<T>* temp;
        temp = head;
        while(temp != nullptr){
            std::cout << temp->data << ", " << temp->next << std::endl;
            temp = temp->next;
        }
    }
};

int main(){

    LinkedList<int> list;
    list.push_front(40);
    list.push_front(80);
    list.push_back(400);
    list.push_middle(34,40);
    list.remove(40);
    list.show();

    return 0;
}