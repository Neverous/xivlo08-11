/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

class Heap
{
	private:
		int data[65536];
		unsigned int size;
		inline void pushup(void);
		inline void pushdown(void);

	public:
		Heap(void);
		inline bool empty(void) const;
		inline void pop(void);
		inline void push(int num);
		inline int top(void) const;
};

int number;
unsigned int actions;
char action[8];
Heap heap;

int main(void)
{
	scanf("%u", &actions);
	for(unsigned int a = 0; a < actions; ++ a)
	{
		scanf("%s", action);
		if(action[0] == 't')
		{
			if(!heap.empty())
				printf("%d\n", heap.top());

			continue;
		}

		if(action[1] == 'u')
		{
			scanf("%d", &number);
			heap.push(number);
			continue;
		}

		heap.pop();
	}

	puts("all done");
	return 0;
}

Heap::Heap(void)
{
	this->data[0] = 0;
	this->size = 0;
	return;
}

inline bool Heap::empty(void) const
{
	return !this->size;
}

inline int Heap::top(void) const
{
	if(this->empty())
		return 0;

	return this->data[0];
}

inline void Heap::push(int num)
{
	this->data[this->size ++] = num;
	this->pushup();
	return;
}

inline void Heap::pop(void)
{
	if(this->empty())
		return;

	if(this->size == 1)
	{
		this->data[0] = 0;
		-- this->size;
		return;
	}

	std::swap(this->data[0], this->data[-- this->size]);
	this->pushdown();
	return;
}

inline void Heap::pushup(void)
{
	unsigned int p = this->size - 1;
	while(p && this->data[p] > this->data[p / 2])
	{
		std::swap(this->data[p], this->data[p / 2]);
		p /= 2;
	}

	return;
}

inline void Heap::pushdown(void)
{
	unsigned int p = 0;
	while(true)
	{
		if(p * 2 + 1 < size && this->data[p] < this->data[p * 2 + 1] &&
			this->data[p * 2 + 1] > this->data[p * 2])
		{
			std::swap(this->data[p], this->data[p * 2 + 1]);
			p = p * 2 + 1;
		}

		else if(p * 2 < size && this->data[p * 2] > this->data[p])
		{
			std::swap(this->data[p], this->data[p * 2]);
			p *= 2;
		}

		else
			break;
	}

	return;
}
