#include <iostream>

template <class T>
class List
{
public:
	void push_back(T data)
	{
		if(head == nullptr)
		{
			head = new node;
			head->m_data = data;
			tail = head;
			
		}
		else
		{
			node* tmp = new node;
			tmp->m_data = data;
			tmp->m_prev = tail;
			tail->m_next = tmp;
			tail = tmp;
			tail->m_next = nullptr;
			//std::cout << "ok1";
		}
	}
	void push_front(T data)
	{
		if (head == nullptr)
		{
			head = new node;
			head->m_data = data;
			head->m_next = nullptr;
			head->m_prev = nullptr;
		}
		else
		{
			node* tmp = new node;
			tmp->m_data = data;
			tmp->m_prev = nullptr;
			tmp->m_next = head;
			head->m_prev = tmp;
			head = tmp;
		}
	}
	void pop_back()
	{
		node* tmp = tail;
		tail = tail->m_prev;
		tail->m_next = nullptr;
		delete tmp;
	}
	void pop_front()
	{
		node* tmp = head;
		head = head->m_next;
		head->m_prev = nullptr;
		delete tmp;
	}
	T front() const
	{
		return head->m_data; 
	}
	T back() const
	{
		return tail->m_data;
	}
	int getSize()
	{
		int size = 0;
		node* curr = head;
		while (curr != nullptr)
		{
			curr = curr->m_next;
			size++;
		}
		return size;
	}
	void insert(int id, T data)
	{
		if (id < 0 || id > getSize())
		{
			throw std::invalid_argument("throw");
		}
		else if (id == 0)
		{
			push_front(data);
		}
		else if (id == getSize())
		{
			push_back(data);
		}
		else
		{
			node* curr = head;
			while (id--)
			{
				curr = curr->m_next;
			}
			node* currPrev = curr->m_prev;
			node* tmp = new node;
			tmp->m_data = data;
			tmp->m_next = curr;
			curr->m_prev = tmp;
			currPrev->m_next = tmp;
			tmp->m_prev = currPrev;
		}
	}
private:
	struct node
	{
		T m_data;
		node* m_next{};
		node* m_prev{};
	};
	node* head{};
	node* tail{};
};