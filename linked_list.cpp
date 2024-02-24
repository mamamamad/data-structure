#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{

    node *head, *tail;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void add_to_end(int data)
    {
        node *tmp = new node;
        tmp->data = data;
        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void add_to_first(int data)
    {
        node *tmp = new node;
        tmp->data = data;
        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tmp->next = head;
            head = tmp;
        }
    }
    int count_number()
    {
        int count = 0;
        node *tmp = head;

        while (tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        }

        return count;
    }
    void add_location(int loc, int data)
    {
        int count = count_number();
        if (loc + 1 > count)
        {
            cout << "wrong!!!";
        }
        else
        {
            node *tmp = new node;
            tmp->data = data;
            node *count = head;
            for (int i = 0; i < loc && count != NULL; i++)
            {
                count = count->next;
            }
            tmp->next = count->next;
            count->next = tmp;
        }
    }
    void show()
    {
        node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
};

int main()
{

    linked_list a;
    a.add_to_end(1);

    a.add_to_end(2);
    a.add_location(1, 5);
    a.show();
    cout << "number: " << a.count_number();

    return 0;
}