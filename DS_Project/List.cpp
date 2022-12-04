#include "List.h"

List::List()
{
	head = new Node();
	this->elementCount = 0;
	this->capacity = 0;
}

List::List(int elementCount, int capacity)
{
	head = new Node();
	this->elementCount = elementCount;
	this->capacity = capacity;
}

void List::setCapacity(int _capacity)
{
	this->capacity = _capacity;
}

int List::getElementCount() const
{
	return elementCount;
}

bool List::insert(const Patient& newElement)
{
	Node* newNode = new Node(newElement);
	if (elementCount == 0) {
		head->set_next(newNode);
		elementCount++;
		return true;
	}

	Node* node = head;
	Patient patient;
	while (node->get_next())
	{
		patient = node->get_next()->get_data();
		if (patient == newElement)
			return false;
		if (patient < newElement)
			break;
		node = node->get_next();
	}
	newNode->set_next(node->get_next());
	node->set_next(newNode);
	elementCount++;
	return true;

}

bool List::remove(const Patient& toBeRemoved)
{
	Node* node = head;
	bool found = false;
	while (node->get_next())
	{
		if (node->get_next()->get_data() == toBeRemoved) {
			found = true;
			break;
		}
		node = node->get_next();
	}
	if (!found)
		return false;
	Node* next = node->get_next();
	node->set_next(next->get_next());
	delete next;
	elementCount--;
	return true;
}

void List::removeAll()
{
	if (elementCount>=2)
	{
		Node* temp = head->get_next();
		Node* temp2 = head->get_next()->get_next();
		while (temp2)
		{
			delete temp;
			temp = nullptr;
			Node* temp = temp2;
			temp2 = temp2->get_next();
		}
		delete temp;
		temp = nullptr;
		elementCount = 0;
	}
}

Patient* List::search(const Patient& target)
{
	if (elementCount == 0)
	{
		return NULL;
	}
	else
	{
		Node* temp = head->get_next();
		while ((temp->get_data() > target) or (temp->get_data() == target)) //O(n) But Fasssssster
		{
			if (temp->get_data() == target)
			{
				Patient result = temp->get_data();
				return &result;
				
			}
			else
			{
				temp = temp->get_next();
			}
		}
		return NULL;
	}
}

void List::printList() 
{
	if (elementCount != 0)
	{
		Node* node = head;
		while (node->get_next())
		{
			//cout << node->get_next()->get_data();
			node->get_next()->printNode();
			node = node->get_next();
		}
	}

}
