#include <iostream>
#include <stack>

int _stack[10001] = {};
int pos = 0;


void push(int x) {
    _stack[pos++] = x;
}

int pop() {
    if (pos)
        return _stack[--pos];
    else
        return -1;
}

int size() {
    return pos;
}

bool empty() {
    return !pos;
}

int top() {
    if (pos)
        return _stack[pos - 1];
    else
        return -1;
}

using namespace std;

int main()
{
    int inputSize = 0;
    cin >> inputSize;
    cin.ignore();
    for (int i = 0; i < inputSize; i++)
    {
        string line;
        getline(cin, line);
        if (!line.compare("top")) 
            std::cout << top() << "\n";
        else if (!line.compare("size")) 
            std::cout << size() << "\n";
        else if (!line.compare("empty")) 
            std::cout << empty() << "\n";
        else if (!line.compare("pop")) 
            std::cout << pop() << "\n";
        else {
            line = line.substr(5 ,100000);
            push(atoi(line.c_str()));
        }
    }
}