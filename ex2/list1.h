#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//doubly linked list

template <typename T>
struct Node
{
    T info;
    Node <T> *next;
    Node <T> *prev;
};

template <typename T>
class LinkedList
{
    public:
        Node <T> *pfirst;
        Node <T> *plast;

    void addFirst(T x)
    {
        Node <T> *paux = new Node<T>;

        paux->info = x;
        paux->prev = NULL;
        paux->next = pfirst;

        if (pfirst != NULL)
            pfirst->prev = paux;

        pfirst = paux;

        if (plast==NULL)
            plast=pfirst;
    }

    void addLast(T x)
    {
        Node<T> *paux = new Node <T>;

        paux->info = x;
        paux->prev = plast;
        paux->next = NULL;

        if (plast != NULL)
            plast->next = paux;

        plast = paux;

        if (pfirst == NULL)
            pfirst = plast;
    }

    T getInfo (Node<T>* p)
    {
        return p->info;
    }

    void removeFirst()
    {
        Node<T>* paux;

        if (pfirst != NULL)
        {
            paux = pfirst->next;

            if (pfirst == plast)
                plast = NULL;

            delete pfirst;

            pfirst = paux;

            if (pfirst != NULL)
                pfirst->prev = NULL;
        }
        else
            cout<<"The list is empty"<<endl;
    }

    void removeLast()
    {
        Node <T> *paux;

        if (plast != NULL)
        {
            paux = plast->prev;

            if (pfirst == plast)
                pfirst = NULL;

            delete plast;

            plast = paux;
            if (plast != NULL)
                plast->next = NULL;
        }
        else
            cout<<"The list is empty"<<endl;
    }

    Node <T>* findFirstOccurrence(T x)
    {
        Node <T> *paux = pfirst;

        while (paux != NULL)
        {
            if (paux->info == x)
                return paux;
            paux = paux->next;
        }
        return NULL;
    }

    Node <T>* findLastOccurrence(T x)
    {
        Node <T> *paux;

        paux = plast;
        while (paux != NULL) {
            if (paux->info == x)
                return paux;
            paux = paux->prev;
        }

        return NULL;
    }

    void removeFirstOccurrence(T x)
    {
        Node <T> *px;

        px = findFirstOccurrence(x);

        if (px != NULL)
        {
            if (px->prev != NULL)
                px->prev->next = px->next;

            if (px->next != NULL)
                px->next->prev = px->prev;

            if (px->prev == NULL)
                pfirst = px->next;

            if (px->next == NULL)
                plast = px->prev;

            delete px;
        }
    }

    void removeLastOccurrence(T x)
    {
        Node <T> *px;

        px = findLastOccurrence(x);

        if (px != NULL)
        {
            if (px->prev != NULL)
                px->prev->next = px->next;

            if (px->next != NULL)
                px->next->prev = px->prev;

            if (px->prev == NULL)
                pfirst = px->next;

            if (px->next == NULL)
                plast = px->prev;

            delete px;
        }
    }

    void removeAt(int index) {
        if (index < 0 || pfirst == NULL) return;

        Node<T>* current = pfirst;
        for (int i = 0; current != NULL && i < index; i++) {
            current = current->next;
        }
        if (current == NULL) return; // Invalid index

        // Update neighbors' pointers
        if (current->prev != NULL)
            current->prev->next = current->next;
        else
            pfirst = current->next; // Removing the first node

        if (current->next != NULL)
            current->next->prev = current->prev;
        else
            plast = current->prev; // Removing the last node

        delete current;
    }

    void insertAt(int index, T x) {
        if (index <= 0) {
            addFirst(x);
            return;
        }

        // Find the node before the target index
        Node<T>* current = pfirst;
        int i;
        for (i = 0; current != NULL && i < index - 1; i++) {
            current = current->next;
        }

        if (current == NULL) { // Index exceeds list size
            addLast(x);
            return;
        }

        // Create new node
        Node<T>* newNode = new Node<T>;
        newNode->info = x;
        newNode->prev = current;
        newNode->next = current->next;

        if (current->next != NULL)
            current->next->prev = newNode;
        else
            plast = newNode; // Inserting at the end

        current->next = newNode;
    }


    int isEmpty()
    {
        return (pfirst == NULL);
    }



        LinkedList()
    {
        pfirst = plast = NULL;
    }
};
