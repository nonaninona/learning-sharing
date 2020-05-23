#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next_Node;
};

class list {
private:
    Node* Head;
    Node* Tail;
public:
    int* result;
    list(int n);
    ~list();
    void Insert(int x);
    int* Delete(int N, int K);
};
void list::Insert(int x) {
    Node* new_Node = new Node();
    new_Node->data = x;
    if (Head == NULL) {
        Head=new_Node;
        Tail = Head;
    }
    else if (Tail==Head) {
        Tail = new_Node;
        Tail->next_Node = Head;
        Head->next_Node = Tail;
    }
    else {
        Tail->next_Node = new_Node;
        Tail = new_Node;
        Tail->next_Node = Head;
    }
}
int* list::Delete(int N, int K) {
    static Node* start = Head;
    static Node* before = NULL;
    if (K == 1) {
        for (int i = 0; i < N; i++) {
            result[i] = i + 1;
        }
        return result;
    }
    for (int j = 0; j < N-1; j++) {
        for (int i = 1; i < K; i++) {
            before = start;
            start = start->next_Node;
        }
        result[j] = start->data;
        before->next_Node = start->next_Node;
        start = start->next_Node;
    }
    result[N - 1] = start->data;
    return result;
}
list::list(int n) {
    Head = NULL;
    Tail = NULL;
    result = new int[n];
}
list::~list() {
    Node* p = Head;
    Node* q;
    while (p != Head) {
        q = p->next_Node;
        delete p;
        p = q;
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    list list1(N);
    for (int i = 0; i < N; i++) {
        list1.Insert(i + 1);
    }
    int* result = list1.Delete(N, K);
    cout << "<";
    for (int i = 0; i < N; i++) {
        cout << result[i];
        if (i != N - 1) {
            cout << ", ";
        }
        else {
            cout << ">" << endl;
        }
    }
    return 0;
}