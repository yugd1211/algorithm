#include <iostream>
#include <algorithm>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x)
{
    int curr = sz++;
    heap[curr] = x;
    while (curr > 0 && heap[curr] < heap[(curr - 1) / 2])
    {
        swap(heap[curr], heap[(curr - 1) / 2]);
        curr = (curr - 1) / 2;
    }
}

int top()
{
    return heap[0];
}

void pop()
{
    if (sz == 1)
    {
        --sz;
        return;
    }
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

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        if (n != 0)
            push(n);
        else
        {
            if (sz == 0)
            {
                cout << "0\n";
                continue;
            }
            cout << top() << "\n";
            pop();
        }
    }
}