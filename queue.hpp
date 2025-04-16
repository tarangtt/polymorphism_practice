#include "_libs.hpp"
#include "list.hpp"

template< class NODETYPE >
class Queue : private List
{
public:	
	Queue() {};
	void enqueue(const NODETYPE& newData)
	{
		insertAtBack(newData);
	}
	void dequeue(NODETYPE& removedData)
	{
		removeFromFront(removedData);
	}
};