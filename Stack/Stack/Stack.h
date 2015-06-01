#ifndef STACK_H
#define STACK_H

enum ErrorCode
{
	SUCCESS, OVERFLOW, UNDERFLOW
};

template<class EntryType, int maxLen>
class Stack
{
public:
	Stack ();
	Stack (const Stack &src);
	~Stack ();
	bool empty ()const;
	bool full () const;
	int size () const;
	ErrorCode top (EntryType &item) const;
	ErrorCode push (const EntryType &item);
	ErrorCode pop ();
	ErrorCode clear ();
private:
	int count;
	EntryType entry[maxLen];
};

template<class EntryType, int maxLen>
Stack<EntryType, maxLen>::Stack ()
{
	count = 0;
}

template<class EntryType, int maxLen>
Stack<EntryType, maxLen>::Stack (const Stack &src)
{
	count = src.count;
	for (int i = 0; i < count; ++i)
		entry[i] = src.entry[i];
}

template<class EntryType, int maxLen>
Stack<EntryType, maxLen>::~Stack ()
{
}

template<class EntryType, int maxLen>
bool Stack<EntryType, maxLen>::empty () const
{
	return count <= 0;
}

template<class EntryType, int maxLen>
bool Stack<EntryType, maxLen>::full () const
{
	return count >= maxLen;
}

template<class EntryType, int maxLen>
int Stack<EntryType, maxLen>::size () const
{
	return count;
}

template<class EntryType, int maxLen>
ErrorCode Stack<EntryType, maxLen>::top (EntryType &item) const
{
	if (empty ())
		return UNDERFLOW;
	else {
		item = entry[count - 1];
		return SUCCESS;
	}
}

template<class EntryType, int maxLen>
ErrorCode Stack<EntryType, maxLen>::push (const EntryType &item)
{
	if (count >= maxLen)
		return OVERFLOW;
	else {
		entry[count++] = item;
		return SUCCESS;
	}
}

template<class EntryType, int maxLen>
ErrorCode Stack<EntryType, maxLen>::pop ()
{
	if (empty ())
		return UNDERFLOW;
	else {
		--count;
		return SUCCESS;
	}
}

template<class EntryType, int maxLen>
ErrorCode Stack<EntryType, maxLen>::clear ()
{
	count = 0;
	return SUCCESS;
}
#endif