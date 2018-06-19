/*********************************************************************************
  * Copyright (c) 2018 Shuai Ke. All rights reserved.
  *
  * FileName: stack.hpp
  * Author: jerakrs
  * Version: 1.0
  * Date: 19/06/2018
  * Description: The implementation of stack.
  *
  * Function List: 
	1. stack::stack(): construct a stack.
		- Params: none.
		- Return: none.
	2. stack::stack(stack& s): construct a stack by a exist stack.
		- Params: a valid stack.
		- Return: none.
	3. stack::~stack(): release a stack.
		- Params: none.
		- Return: none.
	4. stack::size(): get the number of items in the stack.
		- Params: none.
		- Return: the number of items in the stack.
	5. stack::empty(): test whether stack is empty.
		- Params: none.
		- Return: true if the stack's size is 0, false otherwise.
	6. stack::push(Type item): inserts a new element at the head of the stack.
		- Params: item to which the inserted element is initialized.
		- Return: none.
	7. stack::pop(): removes the first element in the stack.
		- Params: none.
		- Return: none.
	8. stack::top(): access the first element in the stack.
		- Params: none.
		- Return: a reference to the first element in the stack.
	9. stack::operator= (stack& s): overload the copy operator.
		- Params: a valid stack.
		- Return: a copy of the exist stack.
	10. stack::copy(stack& s): copy a exist stack.
		- Params: a valid stack.
		- Return: none.
	11. stack::destroy(): destroy the stack.
		- Params: none.
		- Return: none.
  *
**********************************************************************************/

#ifndef _stack_h_
#define _stack_h_


template <typename Type>
class stack;

template<typename Type>
class stack_item {
	friend class stack<Type>;

	stack_item(const Type &item): item(item), next(NULL) {}
	
	Type item;
	stack_item *next;
};

template<typename Type>
class stack {
	public:
		stack(): sz(0), head(NULL) {}
		stack(const stack<Type>& s): sz(0), head(NULL) { copy(s); }
		~stack() { destroy(); }

		int size();
		bool empty();
		void push(const Type& item);
		void pop();
		Type top();
		stack& operator= (const stack<Type> &s);

	private:
		int sz;
		stack_item<Type> *head;

		void copy(const stack<Type>& s);
		void destroy();
};


template<typename Type>
int stack<Type>::size()
{
	return sz;
}

template<typename Type>
bool stack<Type>::empty()
{
	return sz == 0;
}

template<typename Type>
void stack<Type>::push(const Type& item)
{
	stack_item<Type> *temp = new stack_item<Type>(item);
	temp->next = head;
	head = temp;
	sz++;
}

template<typename Type>
void stack<Type>::pop()
{
	if (head == NULL) {
        fprintf(stderr, "stack: the stack is empty.\n");
		exit(EXIT_FAILURE);
	}

	stack_item<Type> *temp = head;
	head = head->next;
	delete temp;
	sz--;
}

template<typename Type>
Type stack<Type>::top()
{
	if (head == NULL) {
        fprintf(stderr, "stack: the stack is empty.\n");
		exit(EXIT_FAILURE);
	}

	return head->item;
}

template<typename Type>
stack<Type>& stack<Type>::operator= (const stack &s)
{
	if (&s == this) return *this;

	destroy();
	copy(s);
	return *this;
}

template<typename Type>
void stack<Type>::destroy()
{
	while(!empty()) pop();
}

template<typename Type>
void stack<Type>::copy(const stack<Type>& s)
{
	sz = s.sz;
	if (sz == 0) return;

	head = new stack_item<Type>(s.head->item);
	stack_item<Type> *move = head;
	stack_item<Type> *temp = s.head->next;

	while (temp != NULL)
	{
		move->next = new stack_item<Type>(temp->item);
		temp = temp->next;
		move = move->next;
	}
}

#endif
