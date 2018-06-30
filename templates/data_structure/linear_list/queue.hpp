/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: queue.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 18/06/2018
  * Description: The implementation of queue.
  *
  * Function List: 
	1. queue::queue(): construct a queue.
		- Params: none.
		- Return: none.
	2. queue::queue(queue& q): construct a queue by a exist queue.
		- Params: a valid queue.
		- Return: none.

	3. queue::~queue(): release a queue.
		- Params: none.
		- Return: none.

	4. queue::size(): get the number of items in the queue.
		- Params: none.
		- Return: the number of items in the queue.

	5. queue::empty(): test whether queue is empty.
		- Params: none.
		- Return: true if the queue's size is 0, false otherwise.

	6. queue::push(Type item): inserts a new element at the end of the queue.
		- Params: item to which the inserted element is initialized.
		- Return: none.

	7. queue::pop(): removes the next element in the queue.
		- Params: none.
		- Return: none.

	8. queue::front(): access next element in the queue.
		- Params: none.
		- Return: a reference to the next element in the queue.

	9. queue::operator= (queue& q): overload the copy operator.
		- Params: a valid queue.
		- Return: a copy of the exist queue.

	10. queue::copy(queue& q): copy a exist queue.
		- Params: a valid queue.
		- Return: none.

	11. queue::destroy(): destroy the queue.
		- Params: none.
		- Return: none.
  *
**********************************************************************************/

#ifndef _queue_h_
#define _queue_h_

template <typename Type>
class queue;

template<typename Type>
class queue_item {
	friend class queue<Type>;

	queue_item(const Type &item): item(item), next(NULL) {}
	
	Type item;
	queue_item *next;
};

template<typename Type>
class queue {
	public:
		queue(): sz(0), head(NULL), tail(NULL) {}
		queue(const queue<Type>& q): sz(0), head(NULL), tail(NULL) { copy(q); }
		~queue() { destroy(); }

		int size();
		bool empty();
		void push(const Type& item);
		void pop();
		Type front();
		queue& operator= (const queue<Type> &q);

	private:
		int sz;
		queue_item<Type> *head;
		queue_item<Type> *tail;

		void copy(const queue<Type>& q);
		void destroy();
};


template<typename Type>
int queue<Type>::size()
{
	return sz;
}

template<typename Type>
bool queue<Type>::empty()
{
	return sz == 0;
}

template<typename Type>
void queue<Type>::push(const Type& item)
{
	queue_item<Type> *temp = new queue_item<Type>(item);

	if (temp == NULL) {
		fprintf(stderr, "queue: Failed to apply for memory space.\n");
		exit(1);
	}

	if (empty()) {
		head = tail = temp;
	} else {
		tail->next = temp;
		tail = temp;
	}
	sz++;
}

	template<typename Type>
void queue<Type>::pop()
{
	if (head == NULL) {
		fprintf(stderr, "queue: the queue is empty.\n");
		exit(EXIT_FAILURE);
	}

	queue_item<Type> *temp = head;
	head = head->next;
	delete temp;
	sz--;
}

	template<typename Type>
Type queue<Type>::front()
{
	if (head == NULL) {
		fprintf(stderr, "queue: the queue is empty.\n");
		exit(EXIT_FAILURE);
	}

	return head->item;
}

	template<typename Type>
queue<Type>& queue<Type>::operator= (const queue &q)
{
	if (&q == this) return *this;

	destroy();
	copy(q);
	return *this;
}

	template<typename Type>
void queue<Type>::destroy()
{
	while(!empty()) pop();
}

	template<typename Type>
void queue<Type>::copy(const queue<Type>& q)
{
	queue_item<Type> *temp = q.head;
	while (temp != NULL)
	{
		push(temp->item);
		temp = temp->next;
	}
}

#endif
