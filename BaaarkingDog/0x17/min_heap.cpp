#include <iostream>
#include <algorithm>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x)
{
    heap[sz] = x;
    if (sz > 0)
    {
        int curr = sz;
        while (heap[curr] < heap[(curr - 1) / 2])
            swap(heap[curr], heap[(curr - 1) / 2]);
    }
    ++sz;
}

int top()
{
    return heap[0];
}

void pop()
{
    swap(heap[0], heap[sz - 1]);
    --sz;
    int curr = 0;
    int child;
    while (1)
    {
        if ((curr * 2) + 2 < sz)
        {
            if (heap[(curr * 2) + 1] < heap[(curr * 2) + 2])
                child = (curr * 2) + 1;
            else
                child = (curr * 2) + 2;
        }
        else if ((curr * 2) + 1 < sz)
            child = (curr * 2) + 1;
        else
            return;
        if (heap[curr] > heap[child])
        {
            swap(heap[curr], heap[child]);
            curr = child;
        }
        else
            return;
    }
}

void printHeap()
{
    cout << "curr heap = ";
    for (int i = 0; i < sz; i++)
        cout << heap[i] << " ";
    cout << "\n";
}

void test()
{
    push(10);
    push(2);
    push(5);
    push(9);               // {10, 2, 5, 9}
    cout << top() << '\n'; // 2
    pop();                 // {10, 5, 9}
    pop();                 // {10, 9}
    cout << top() << '\n'; // 9
    push(5);
    push(15);              // {10, 9, 5, 15}
    cout << top() << '\n'; // 5
    pop();                 // {10, 9, 15}
    cout << top() << '\n'; // 9
}

int main()
{
    test();
}