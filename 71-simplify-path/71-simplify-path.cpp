#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Node
{
    string data;
    Node* next;
};

class Stack
{
private:
    Node* top;
public:
    Stack();
    void push(string data);
    string pop();
    string peek();
    string displayStack();
    bool isEmpty();
    ~Stack();
};

Stack::Stack()
{
    top = NULL;
}

Stack::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}
void Stack::push(string d)
{
    Node* temp = new Node();
    temp->data = d;
    temp->next = top;
    top = temp;
}
string Stack::pop()
{
    if (!isEmpty())
    {
        string value = top->data;
        Node* oldTop = top;
        top = oldTop->next;
        delete oldTop;
        return value;
    }
    else
    {
        cout << "You can't pop from empty stack" << endl;
        exit(1);
    }
   
}
string Stack::peek()
{
    if (!isEmpty())
    {
        string value = top->data;
        return value;
    }
    else
    {
        cout << "You can't pop from empty stack" << endl;
        exit(1);
    }
}
string Stack::displayStack()
{
    string result = "/";
    if (isEmpty())
    {
        result = result + "NULL";
        return result;
    }
    else
    {
        Node* current = top;
        while (current != NULL)
        {
            result = result + current->data + "/";
            current = current->next;
        }
        return result;
    }
}
bool Stack::isEmpty()
{
    return (top == NULL);
}

class Solution {
public:
    string simplifyPath(string path) {
            Stack* s = new Stack();
    string result;
    vector<string> pathData;
    vector<string> returnedPath;

    stringstream ss(path);

    while (ss.good()) {
        string substr;
        getline(ss, substr, '/');
        pathData.push_back(substr);
    }
    if (pathData[0] == "")
    {
        result = "/";
        for (int i = 1; i < pathData.size(); i++)
        {
            if (pathData[i] == "")
            {
                continue;
            }
            else if (pathData[i] == "..")
            {
                if (!s->isEmpty())
                {
                    s->pop();
                    returnedPath.pop_back();
                }
            }
            else if (pathData[i] != ".")
            {
                s->push(pathData[i]);
                returnedPath.push_back(pathData[i]);
            }
        }
        for (int i = 0; i < returnedPath.size(); i++)
        {
            if (i != returnedPath.size() - 1)
            {
                result = result + returnedPath[i].append("/");
            }
            else
            {
                result = result + returnedPath[i];
            }
        }
    }
    else if (pathData[0] != "")
    {
        int counter = 0;
        for (int i = 0; i < pathData.size(); i++)
        {
            if (pathData[i] == "" || pathData[i] == ".")
            {
                continue;
            }
            else if (pathData[i] == "..")
            {
                if (!s->isEmpty())
                {
                    string value = s->peek();
                    if (value == "..")
                    {
                        s->push(pathData[i]);
                        returnedPath.push_back(pathData[i]);

                    }
                    else
                    {
                        s->pop();
                        returnedPath.pop_back();
                    }
                }
                else
                {
                    s->push(pathData[i]);
                    returnedPath.push_back(pathData[i]);
                }
            }
            else if (pathData[i] != ".")
            {
                s->push(pathData[i]);
                returnedPath.push_back(pathData[i]);
            }
        }
        for (int i = 0; i < returnedPath.size(); i++)
        {
            if (i != returnedPath.size() - 1)
            {
                result += returnedPath[i].append("/");
            }
            else
            {
                result += returnedPath[i];
            }
        }
    }
    return result;
    }
   
};