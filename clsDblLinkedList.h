#pragma once
#include<iostream>
using namespace std;
template<class T>
class clsDblLinkedList
{
protected:
    int _Size = 0;
public:
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

    void InsertAtBeginning(T data) {
        Node* new_node = new Node();

        new_node->data = data;
        new_node->next = head;
        new_node->prev = NULL;

        if (head != NULL) {
            head->prev = new_node;
        }

        head = new_node;
        _Size++;
    }

    void PrintList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data <<"  "; 
            current = current->next;
        }
        cout << "\n";
    }

    Node* FindNode(T data) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == data) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    int Size() {
        return _Size;
    }

    bool IsEmpty() {
        return (head == NULL);
    }

    void InsertAfter(Node* prev_node, T data) {
        if (prev_node == NULL) {
            return;
        }
        Node* new_node = new Node();
        new_node->prev = prev_node;
        new_node->data = data;
        new_node->next = prev_node->next;
        if (prev_node->next != NULL) {
            prev_node->next->prev = new_node;
        }
        prev_node->next = new_node;
        _Size++;
    }

    Node* FindLastNode() {
        Node* current = head;
        while (current != NULL) {
            if (current->next == NULL) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    void InsertAtEnd(T data) {
        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = NULL;
        if (head == NULL) {
            new_node->prev = NULL;
            head = new_node;
            return;
        }
        Node* last_node = FindLastNode();
        new_node->prev = last_node;
        last_node->next = new_node;
        _Size++;
    }

    void DeleteNode(T data) {
        if (head == NULL) {
            return;
        }
        Node* Current = FindNode(data);
        if (Current != NULL) {
            if (Current->prev != NULL) {
                Current->prev->next = Current->next;
            }
            else {
                head = Current->next;
            }
            if (Current->next != NULL) {
                Current->next->prev = Current->prev;
            }
            delete Current;
            _Size--;
        }
    }

    void NodeToDelete(Node* Target) {
        if (head == NULL) {
            return;
        }
        if (Target != NULL) {
            if (Target->prev != NULL) {
                Target->prev->next = Target->next;
            }
            else {
                head = Target->next;
            }
            if (Target->next != NULL) {
                Target->next->prev = Target->prev;
            }
            delete Target;
            _Size--;
        }
    }

    void DeleteFirstNode() {
        NodeToDelete(head);
    }

    void DeleteLastNode() {
        Node* last_node = FindLastNode();
        NodeToDelete(last_node);
    }

    void Clear() {
        while (head != NULL) {
            DeleteFirstNode();
        }
    }

    void Reverse() {
        Node* current = head;
        Node* temp = nullptr;
        while (current !=nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp!=nullptr) {
            head = temp->prev;
        }
    }

    Node * GetNode(int index) {
        if ((_Size - 1) < index||index<0) {
            return NULL;
        }
        Node* current = head;
        int counter = 0;
        while (current != NULL&&current->next!=NULL) {
            if (counter==index) {
                return current;
            }
            current = current->next;
            counter++;
        }
    }

	T GetItem(int index) {
		Node* node =GetNode(index);
        if (node == NULL)
            return NULL;
		else
			return node->data;
	}

    bool UpdateItem(int index,T new_data) {
        Node* node = GetNode(index);
		if (node!= NULL)
        {
            node->data = new_data;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool InsertAfter(int index, T data) {
        if (index > (_Size - 1)) {
            return false;
        }
        Node* node = GetNode(index);
        if(node!=NULL)
        {
            InsertAfter(node, data);
            return true;
        }
        else {
            return false;
        }
    }
};