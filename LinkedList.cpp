#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

/*
1. Add//
2. Add first //
3. Add Last//
3.5 Edit At index//
4. Remove first//
5. Remove Last//
6. Remove at slot I//
7. Remove All//
8. Get Data at index//
9. Contains = innehålla (om det finns data i listans)
10. Edit node data at index
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

    void EditAtIndex(int data, int index)
    {
        Node* current_ = head_;
        bool outOfBound = true;
        if (head_ == nullptr)
        {
            cout << "noob" << endl;
        }
        else
        {
            for (int i = 0; i < index; i++)
            {
                if (current_->next_ == nullptr)
                {
                    cout << "Index out of bound";
                    outOfBound = false;
                    break;
                }
                else
                {
                    current_ = current_->next_;
                }
            }
            if(outOfBound)
            {
                current_->data_ = data;
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
        else
        {
            for (int i = 0; i <index-1; i++) 
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
    void RemoveData(int data)
    {
        Node* current_ = head_;
        Node* prev_;

        if (head_ == nullptr)
        {
            cout << "List Empty";
        }
        else if (head_->data_ == data)
        {
            head_ = current_->next_;
            delete current_;
        }
        else
        {
            while (current_->next_ != nullptr) 
            {
                prev_ = current_;
                current_ = current_->next_;

                if (current_->data_ == data)
                {
                    prev_->next_ = current_->next_;
                    delete current_;
                    break;
                }
            }
        }
    }
    void RemoveFirst()
    {
        Node* current_ = head_;

        if (head_ == nullptr)
        {
            cout << "List Empty";
        }
        else
        {
            head_ = current_->next_;
            delete current_;
        }
    }

    void RemoveLast ()
    {
        Node* current_ = head_;
        Node* prev_;

        while (current_->next_ != nullptr)
        {
            prev_ = current_;
            current_ = current_->next_;

            if (current_->next_ == nullptr)
            {
                prev_->next_ = current_->next_;
                delete current_;
                break;
            }
        }
    }

    void RemoveAll ()
    {
        Node* current_ = head_;
        while (head_->next_ != nullptr)
        {
            Node* prev_;
            prev_ = current_;
            current_ = current_->next_;
            delete prev_;
            if (current_->next_ == nullptr)
            {
                head_ = nullptr;
                break;
            }
        }
    }

    void GetDataAtIndex(int index)
    {
        Node* current_ = head_;

        if (index == 0)
        {
            cout << "Data at index " << index << " is " << current_->data_ << endl;
        }
        else
        {
            for (int i = 0; i <= index; i++)
            {
                if (i == index)
                {
                    cout << "Data at index " << index << " is " << current_->data_ << endl;
                }
                else
                {
                    current_ = current_->next_;
                }
            }
        }
    }

    void Contains(int data)
    {
        Node* current_ = head_;
        int i = 0;

        while (head_ != nullptr)
        {
            if (current_->data_ == data)
            {
                if (current_->next_ != nullptr)
                {
                    cout << "Data " << current_->data_ << " found at slot " << i << endl;
                    i = i + 1;
                    current_ = current_->next_;
                }
                else if (current_->data_ == data)
                {
                    cout << "Data " << current_->data_ << " found at slot " << i << endl;
                    break;
                }
            }
            else if (current_->next_ == nullptr)
            {
                if (current_->data_ != data)
                { 
                    cout << "Data not found";
                    break;
                }
            }
            else if (current_->data_ != data)
            {
                if (current_->next_ != nullptr)
                {
                    i = i + 1;
                    current_ = current_->next_;
                }
                else
                {
                    break;
                }
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
            if (current_ == nullptr)
            {
                cout << "List empty";
            }
            else
            {
                while (head_ != nullptr)
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
    }

    void Clear()
    {

    }

};


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //Debug-flaggor för att upptäcka minnesläckor

    LinkedList linkedList;
    linkedList.Add(5);
    linkedList.Add(0);
    linkedList.Add(0);
    linkedList.Add(0);
    linkedList.Add(9);
    linkedList.PrintList();
    linkedList.Contains(5);
}
