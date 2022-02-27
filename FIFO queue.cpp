#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
struct Node
{
	int data;
	Node* prev;
	Node* next;
};
void add_beg(Node** begin, Node** end, int n)
{
	Node* newn = new Node;
	newn->data = n;
	if (*begin)
	{
		newn->next = (*begin);
		newn->prev = *end;
		(*begin)->prev = newn;
		(*end)->next = newn;
		*begin = newn;
		return;
	}
	else
	{
		newn->next = newn;
		newn->prev = newn;
		*begin = newn;
		*end = newn;
		return;
	}
}

void add_end(Node** begin, Node** end, int n)
{
	Node* newn = new Node;
	newn->data = n;
	if (*begin)
	{
		newn->prev = (*end);
		newn->next = *begin;
		(*end)->next = newn;
		(*begin)->prev = newn;
		*end = newn;
	}
	else
	{
		newn->next = newn;
		newn->prev = newn;
		*begin = newn;
		*end = newn;
		return;
	}
}
int list_size(Node* begin, Node* end)
{
	if (!begin)
	{
		return 0;
	}
	else
	{
		int c = 1;
		Node* temp = begin;
		while (temp != end)
		{
			c++;
			temp = temp->next;
		}
		temp = nullptr;
		delete temp;
		return c;
	}
}
void print_fwd(Node* begin, Node* end)
{
	if (begin)
	{
		Node* temp = begin;
		while (temp!=end)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << end->data << "\n";
		temp = nullptr;
		delete temp;
		return;
	}
	else
	{
		cout << "NULL\n";
		return;
	}
}
void print_bkw(Node* begin, Node* end)
{
	if (begin)
	{
		Node* temp = end;
		while (temp != begin)
		{
			cout << temp->data << " ";
			temp = temp->prev;
		}
		cout << begin->data << "\n";
		temp = nullptr;
		delete temp;
		return;
	}
	else
	{
		cout << "NULL\n";
		return;
	}
}
void del_beg(Node** begin, Node** end,Node** qbegin,Node** qend)
{
	if (!begin)
	{
		return;
	}
	if (*begin == *end)
	{
		*begin = nullptr;
		*end = nullptr;
		*qbegin = nullptr;
		*qend = nullptr;
		return;
	}
	bool b = 0, e = 0;
	if (*qend == *begin)
	{
		e = 1;
	}
	if (*qbegin == *begin)
	{
		b = 1;
	}
	if (*qbegin == *begin && list_size(*qend, *qbegin) == 1)
	{
		e = 0;
		b = 0;
		*qbegin = nullptr;
		*qend = nullptr;
	}
	*begin = (*begin)->next;
	(*begin)->prev = *end;
	(*end)->next = *begin;
	if (e)
	{
		*qend = *begin;
	}
	else
	{
		if (b)
		{
			*qbegin = *end;
		}
	}
}
void del_end(Node** begin, Node** end,Node** qbegin, Node** qend)
{
	if (!begin)
	{
		return;
	}
	if (*begin == *end)
	{
		*begin = nullptr;
		*end = nullptr;
		*qend = nullptr;
		*qbegin = nullptr;
		return;
	}
	bool b = 0, e = 0;
	if (*qend == *end)
	{
		e = 1;
	}
	if (*qbegin == *end)
	{
		b = 1;
	}
	if (*qbegin == *end && list_size(*qend, *qbegin) == 1)
	{
		e = 0;
		b = 0;
		*qbegin = nullptr;
		*qend = nullptr;
	}
	(*end) = (*end)->prev;
	(*end)->next = *begin;
	(*begin)->prev = *end;
	if (e)
	{
		*qend = *begin;
	}
	else
	{
		if (b)
		{
			*qbegin = *end;
		}
	}
}
void push(Node** begin, Node** end, Node** qbegin, Node** qend, int n)
{
	int q = list_size(*qend, *qbegin);
	int l = list_size(*begin, *end);
	if (q == l)
	{
		if ((q==0) || *qend==*begin)
		{
			add_beg(begin, end, n);
			*qend = *begin;
			if(q==0)
			*qbegin = *qend;
		}
		else
		{
			Node* newn = new Node;
			newn->data = n;
			newn->prev = *qbegin;
			newn->next = *qend;
			(*qbegin)->next = newn;
			(*qend)->prev = newn;
			*qend = newn;

		}
		return;
	}
	if (q == 0)
	{
		(*end)->data = n;
		*qend = *end;
		*qbegin = *end;
		return;
	}
	(*qend)->prev->data = n;
	*qend = (*qend)->prev;
	return;
}
void pop(Node** begin, Node** end, Node** qbegin, Node** qend)
{
	if (*qbegin)
	{
		cout << (*qbegin)->data << "\n";
		if(*qbegin == *qend)
		{
			*qbegin = nullptr;
			*qend = nullptr;
			return;
		}
		*qbegin = (*qbegin)->prev;
		return;
	}
	else
	{
		cout << "NULL\n";
	}
}
void grb_soft(Node** begin, Node** end, Node** qbegin, Node** qend)
{
	if (!*qbegin)
	{
		if (*begin)
		{
			Node* temp = *begin;
			while (temp != *end)
			{
				temp->data = 0;
				temp = temp->next;
			}
			(*end)->data = 0;
			temp = nullptr;
			delete temp;
			return;
		}
		return;
	}
	Node* temp = (*qbegin)->next;
	while (temp != *qend)
	{
		temp->data = 0;
		temp = temp->next;
	}
	temp = nullptr;
	delete temp;
	
}
void grb_hard(Node** begin, Node** end, Node** qbegin, Node** qend)
{
	if (!*qbegin)
	{
		*begin = nullptr;
		*end = nullptr;
		return;
	}
	if (*qbegin != *qend)
	{
		Node* temp = (*qbegin)->next;
		while (temp != *qend)
		{
			if (temp == *begin)
			{
				*begin = (*begin)->next;
			}
			if (temp == *end)
			{
				*end = *qbegin;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			temp = temp->next;
		}
		temp = nullptr;
		delete temp;
	}
	else
	{
		*begin = *qbegin;
		*end = *qbegin;
	}
}
int main()
{
	Node* begin = nullptr;
	Node* end = nullptr;
	Node* qbegin = nullptr;
	Node* qend = nullptr;
	int n;
	string cmd;
	while (cin >> cmd)
	{
		if (cmd == "ADD_BEG")
		{
			cin >> n;
			add_beg(&begin, &end, n);
		}
		if (cmd == "ADD_END")
		{
			cin >> n;
			add_end(&begin, &end, n);
		}
		if (cmd == "DEL_BEG")
		{
			del_beg(&begin, &end, &qbegin, &qend);
		}
		if (cmd == "DEL_END")
		{
			del_end(&begin, &end, &qbegin, &qend);
		}
		if (cmd == "PRINT_FORWARD")
		{
			print_fwd(begin, end);
		}
		if (cmd == "PRINT_BACKWARD")
		{
			print_bkw(begin, end);
		}
		if (cmd == "SIZE")
		{
			cout << list_size(begin, end) << "\n";
		}
		if (cmd == "COUNT")
		{
			cout << list_size(qend, qbegin) << "\n";
		}
		if (cmd == "PUSH")
		{
			cin >> n;
			push(&begin, &end, &qbegin, &qend, n);
		}
		if (cmd == "POP")
		{
			pop(&begin, &end, &qbegin, &qend);
		}
		if (cmd == "PRINT_QUEUE")
		{
			print_bkw(qend, qbegin);
		}
		if (cmd == "GARBAGE_SOFT")
		{
			grb_soft(&begin, &end,&qbegin,&qend);
		}
		if (cmd == "GARBAGE_HARD")
		{
			grb_hard(&begin, &end,&qbegin,&qend);
		}
	}
	begin = nullptr;
	end = nullptr;
	qbegin = nullptr;
	qend = nullptr;
	delete begin;
	delete end;
	delete qbegin;
	delete end;
	return 0;
}