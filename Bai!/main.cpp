#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct List {
	Node* head;
	Node* tail;
};

Node* CreateNode(int data)
{
	Node* p = new Node;
	p->data = data;
	p->next = NULL;
	return p;
}

void CreateList(List& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void addHead(List& l, Node* p)
{
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = l.head;
	}
	else {
		p->next = l.head;
		l.head = p;
	}
}

void addTail(List& l, Node* p)
{
	if (l.head == NULL)
	{
		l.head = p;
		l.tail = l.head;
	}
	else {
		l.tail->next = p;
		l.tail = p;
	}
}

void printList(List& l)
{
	for (Node* p = l.head; p != NULL; p = p->next)
		cout << p->data << " ";
}

Node* Reverse(Node* p)
{
	Node* prev = NULL;
	Node* cur = p, * next = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

void ReverseKhoang(List& l, int h, int k)
{
	if (h == k) return;
	Node* start = NULL, * end = NULL;
	Node* s_pre = NULL, *e_next = NULL;
	Node* cur = l.head;
	int i = 1;
	while (cur != NULL && i <= k)
	{
		if (i < h) s_pre = cur;
		if (i == h) start = cur;
		if (i == k)
		{
			end = cur;
			e_next = cur->next;
		}
		cur = cur->next;
		i++;
	}
	end->next = NULL;
	end = Reverse(start);
	if (s_pre != NULL)
	{
		s_pre->next = end;

	}
	else {
		l.head = end;
	}
	start->next = e_next;
}

int main()
{
	int n, x;
	
	Node* p;
	List l;
	CreateList(l);

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		
		addTail(l, CreateNode(x));
	}
	int h, k;
	cin >> h >> k;

	ReverseKhoang(l, h, k);
	printList(l);
	return 0;
}