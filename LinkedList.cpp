#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

/*
1. Add//
2. Add first //
3. Add Last//
4. Remove first
5. Remove Last
6. Remove at slot I
7. Get first Node Data
8. Contains = innehålla (om det finns data i listans)
9. Edit node data at index
*/

struct Node
{
    int data_;
    Node* next_ = nullptr;

    Node(int data) //Konstruktor
    {
        data_ = data;
    }

    ~Node() //Destruktor, frigör minne här!
    {

    }
};

struct LinkedList
{
    Node* head_ = nullptr;

    LinkedList() //Konstruktor
    {

    }

    ~LinkedList() //Destruktor, frigör minne här!
    {
        Clear();
    }

    void Add(int data)
    {
        Node* current_ = head_;

        Node* newNode = CheckEmptyList(data);
        if (head_ != nullptr)
        {
            while (current_ != nullptr)
            {
                if (current_->next_ == nullptr)
                {
                    current_->next_ = newNode;
                    break;
                }
                else
                {
                    current_ = current_->next_;
                }
            }
        }
    }

    void AddAtIndex(int data, int index)
    {
        Node* current_ = head_;

        Node* newNode = CheckEmptyList(data);
        if (index == 0)
        {
            AddFirst(data);
        }
        else if (head_ != nullptr)
        {
            for (int i = 0; i < index-1; i++)
            {
                if (current_->next_ == nullptr)
                {
                    Node* nullNode = new Node(NULL);
                    current_->next_ = nullNode;
                    current_ = current_->next_;
                }
                else
                {
                    current_ = current_->next_;
                }
            }
            newNode->next_ = current_->next_;
            current_->next_ = newNode;
        }
    }

    void AddFirst(int data)
    {
        Node* newNode = new Node(data);

        newNode->next_ = head_;
        head_ = newNode;
    }

    void AddLast(int data)
    {
        Node* current_ = head_;
         

        Node* newNode = CheckEmptyList(data);
        while (current_ != nullptr)
        {
            if (current_->next_ == nullptr)
            {
                current_->next_ = newNode;
                current_ = current_->next_;
                break;
            }
            else
            {
                current_ = current_->next_;
            }
        }
    }
    
    Node* CheckEmptyList(int data)
    {
        Node* newNode = new Node(data);
        if (head_ == nullptr)
        {
            newNode->next_ = head_;
            head_ = newNode;
        }
        return newNode;
    }

    void PrintList()
    {
        Node* current_ = head_;

        while (current_ != nullptr)
        {
            cout << current_->data_ << endl;

            if (current_->next_ == nullptr)
            {
                break;
            }
            else
            {
                current_ = current_->next_;
            }
        }
    }

    void Clear()
    {

    }

};


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //Debug-flaggor för att upptäcka minnesläckor

    LinkedList linkedList;
    linkedList.AddLast(10);
    linkedList.Add(5);
    linkedList.Add(6);
    linkedList.Add(7);
    linkedList.AddAtIndex(8, 2);
    linkedList.AddAtIndex(9, 9);
    linkedList.AddFirst(12);
    linkedList.PrintList();

}
