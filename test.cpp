#include <iostream>
#include <iomanip>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        next = NULL;
        prev = NULL;
        data = 0;
    }
    Node(int data)
    {
        next = NULL;
        prev = NULL;
        this->data = data;
    }
    // ~Node()
    // {
    //     delete next;
    //     delete prev;
    // }
};
class DoubleList
{
    Node *head;

public:
    DoubleList(Node *n)
    {
        head = n;
    }
    DoubleList()
    {
        head = NULL;
    }
    void insertAtEnd(int data)
    {
        Node *temp = head;
        Node *ptr = new Node(data);
        if(head==NULL)
        {
            head=ptr;
            return;
        }
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = ptr;
        ptr->next = NULL;
        ptr->prev = temp;
    }
    void insertAtBeg(int data)
    {
        Node *temp = head;
        Node *ptr = new Node(data);
        if(head==NULL)
        {
            head=ptr;
            return;
        }
        temp->prev = ptr;
        ptr->next = temp;
        ptr->prev = NULL;
        head = ptr;
    }
    void insertAtKey(int data, int key)
    {
        Node *temp = head;
        Node *ptr = new Node(data);
        if(head==NULL)
        {
            head=ptr;
            return;
        }
        int i = 0;
        if (key == 0)
        {
            this->insertAtBeg(data);
            return;
        }
        while (temp != NULL)
        {
            if ((i + 1) == key)
                break;

            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            this->insertAtEnd(data);
            return;
        }
        ptr->next = temp->next;
        temp->next->prev = ptr;
        temp->next = ptr;
        ptr->prev = temp;
    }
    void delHead()
    {
        Node *temp = head;
        Node *ptr = head;
        temp = temp->next;
        temp->prev = NULL;
        delete (ptr);
        head = temp;
    }
    void delTail()
    {
        Node *temp = head;
        Node *ptr = head;
        temp = temp->next;

        while (temp->next != NULL)
        {
            temp = temp->next;
            ptr = ptr->next;
        }
        ptr->next = NULL;
        delete temp;
    }
    void delAtindex(int index)
    {
        if (head == NULL)
            return;
        if (index == 0)
        {
            this->delHead();
            return;
        }
        Node *temp = head;
        Node *ptr = head;
        temp = temp->next;
        int i = 0;
        while (temp != NULL)
        {
            if ((i + 1) == index)
                break;
            temp = temp->next;
            ptr = ptr->next;
            i++;
        }
        if (temp->next == NULL)
        {
            this->delTail();
            return;
        }
        if ((i + 1) == index)
        {
            temp->next->prev = ptr;
            ptr->next = temp->next;
            delete (temp);
            return;
        }

        {
            cout << "Unvalid index" << endl;
        }
    }
    void triversal()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printrev()
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp != NULL)
        {
            cout << temp->data<<" ";
            temp = temp->prev;
        }
        cout<<endl;
    }
};

int main()
{
    DoubleList *l=new DoubleList[4];
    l[0].insertAtBeg(1);
    l[0].insertAtBeg(2);
    l[0].insertAtBeg(3);

    l[0].triversal();
    DoubleList *temp=l;
    temp[0].triversal();
    l=new DoubleList[6];
    for (int i = 0; i < 4; i++)
    {
        l[i]=temp[i];
    }
    l[0].triversal();
    l[5].insertAtBeg(99);
    l[5].insertAtBeg(99);
    l[5].insertAtBeg(99);
    l[5].triversal();
    

    
    return 0;
}