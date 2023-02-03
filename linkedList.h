#include <iostream> 
#include <assert.h> 
using namespace std;

template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type>* link;
};
template<class Type>
class linkedListType
{
private:
	nodeType<Type>* first;
	nodeType<Type>* last;
	int count;

public:
	void initializeList();

	bool isEmptyList();

	bool isFullList();

	void print();

	int length();

	void destroyList();

	void retrieveFirst(Type& firstElement);

	void retrieveLast(Type& lastElement);

	void search(const Type& searchItem);

	void insertFirst(const Type& newItem);

	void insertLast(const Type& newItem);

	void deleteNode(const Type& deleteItem);

	linkedListType();
	~linkedListType();

	linkedListType(const linkedListType<Type>& otherList);

	const linkedListType<Type>& operator= (const linkedListType<Type>&);

};
template<class Type>
bool linkedListType<Type>::isEmptyList()
{
	return(first == NULL);
}

template<class Type>
bool linkedListType<Type>::isFullList()
{
	return false;
}
template<class Type>
linkedListType<Type>::linkedListType()
{
	first = NULL;
	last = NULL;
	count = 0;
}

template<class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type>* temp;
	while (first != NULL)
	{
		temp = first;
		first = first->link; delete temp;
	}
	last = NULL;
	count = 0;
}

template<class Type>
void linkedListType<Type>::initializeList()
{
	destroyList();
}

template<class Type>
void linkedListType<Type>::print()
{
	nodeType<Type>* current;

	current = first;
	while (current != NULL)
	{
		cout << current->info << " ";
		current = current->link;
	}
}

template<class Type>
int linkedListType<Type>::length()
{
	int count = 0;
	nodeType<Type>* current;
	current = first;
	while (current != NULL)
	{
		count++;
		current = current->link;
	}

	return count;
}

template<class Type>
void linkedListType<Type>::retrieveFirst(Type& firstElement)
{
	assert(first != NULL);
	firstElement = first->info;
}

template<class Type>
void linkedListType<Type>::retrieveLast(Type& lastElement)
{
	assert(last != NULL);
	lastElement = last->info;
}

template<class Type>
void linkedListType<Type>::search(const Type& item)
{
	nodeType<Type>* current;
	bool found;

	if (first == NULL)
		cout << "Cannot search an empty list. " << endl;

	else
	{

		current = first;


		found = false;

		while (!found && current != NULL)
			if (current->info == item)
				found = true;

			else
				current = current->link;

		if (found)
			cout << "Item is found in the list." << endl;

		else
			cout << "Item is not in the list." << endl;

	}
}
template<class Type>
void linkedListType<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type>* newNode;
	newNode = new nodeType<Type>;
	newNode->info = newItem;
	newNode->link = first;
	first = newNode;

	if (last == NULL)
		last = newNode;
}

template<class Type>
void linkedListType<Type>::insertLast(const Type& newItem)
{
	nodeType<Type>* newNode;

	newNode = new nodeType<Type>;
	newNode->info = newItem;
	newNode->link = NULL;

	if (first == NULL)
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		last->link = newNode;
		last = newNode;
	}
}

template<class Type>
void linkedListType<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type>* current;
	nodeType<Type>* trailCurrent;
	bool found;

	if (first == NULL)
		cout << "Can not delete from an empty list.\n";

	else
	{

		if (first->info == deleteItem)
		{

			current = first;
			first = first->link;
			if (first == NULL)
				last = NULL;
			delete current;

		}
		else
		{

			found = false;
			trailCurrent = first;
			current = first->link;

			while ((!found) && (current != NULL))
			{
				if (current->info != deleteItem)
				{

					trailCurrent = current;
					current = current->link;


				}
				else
					found = true;
			}

			if (found)
			{
				trailCurrent->link = current->link;

				if (last == current)
					last = trailCurrent;
				delete current;
			}

			else
				cout << "Item to be deleted is not in the list." << endl;
		}
	}
}
template<class Type>
linkedListType<Type>::~linkedListType()
{
	nodeType<Type>* temp;

	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}

	last = NULL;
}

template<class Type> linkedListType<Type>::linkedListType(
	const linkedListType<Type>& otherList)
{
	nodeType<Type>* newNode;
	nodeType<Type>* current;

	if (otherList.first == NULL)
	{

		first = NULL;
		last = NULL;

	}
	else
	{

		current = otherList.first;

		first = new nodeType<Type>;
		first->info = current->info;
		first->link = NULL;
		last = first;
		current = current->link;

		while (current != NULL)
		{
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->link = NULL;

			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
}

template<class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(
	const linkedListType<Type>& otherList)
{
	nodeType<Type>* newNode;
	nodeType<Type>* current;

	if (this != &otherList)
	{
		if (first != NULL)
			destroyList();

		if (otherList.first == NULL)
		{
			first = NULL;
			last = NULL;
		}
		else
		{

			current = otherList.first;
			first = new nodeType<Type>;
			first->info = current->info;
			first->link = NULL;

			last = first;
			current = current->link;
			while (current != NULL)
			{

				newNode = new nodeType<Type>;
				newNode->info = current->info;
				newNode->link = NULL;
				last->link = newNode;
				last = newNode;
				current = current->link;
			}
		}
	}

	return *this;
}
