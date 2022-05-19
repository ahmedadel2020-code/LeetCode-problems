#include <iostream>
#include <vector>

using namespace std;

class Queue
{
private:
	int front;
	int rear;
	int *arr;
	int size = 0;
public:
	Queue(int s)
	{
		front = -1;
		rear = -1;
		size = s;
		arr = new int[size];
		for (int i = 0; i < size - 1; i++)
		{
			arr[i] = 0;
		}
	}
	bool isEmpty()
	{
		if (front == -1 && rear == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()
	{
		if (rear == (size - 1))
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	void enqueue(int val)
	{
		if (isFull())
		{
			cout << "Queue is Full" << endl;
			return;
		}
		else if (isEmpty())
		{
			rear = 0;
			front = 0;
			arr[rear] = val;
		}
		else
		{
			rear++;
			arr[rear] = val;
		}
	}
	int dequeue()
	{
		int temp;
		if (isEmpty())
		{
			cout << "Queue if Empty" << endl;
			return 0;
		}
		else if (front == rear)
		{
			temp = arr[front];
			arr[front] = 0;
			rear = -1;
			front = -1;
			return temp;
		}
		else
		{
			temp = arr[front];
			arr[front] = 0;
			front++;
			return temp;
		}
	}
	int frontOfQueue()
	{
		int temp;
		if (!isEmpty())
		{
			temp = arr[front];
			return temp;
		}
		else
		{
			cout << "Queue if Empty" << endl;
			return 0;
		}
	}
	int backOfQueue()
	{
		if (!isEmpty())
		{
			int temp = arr[rear];
			return temp;
		}
		else
		{
			cout << "Queue if Empty" << endl;
			return 0;
		}
	}
	int count()
	{
		return (rear - front + 1);
	}
};
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int time = 0;
	    Queue q(10000);
        for (int i = 0; i < tickets.size(); i++)
        {
            q.enqueue(i);
        }
        while (!q.isEmpty()) 
        {
            ++time;
            int temp = q.frontOfQueue();
            q.dequeue();
            if (tickets[temp] >= 1)
            {
                tickets[temp] -= 1;
            }
            if (temp != k && tickets[temp] == 0)
            {
                continue;
            }
            if (temp == k && tickets[temp] == 0)
            {
                break;
            }
            q.enqueue(temp);
        }
        return time;
    }
};