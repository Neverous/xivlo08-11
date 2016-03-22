/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

class Tree
{
	private:
		static const int SIZE = 32768;
		int data[SIZE * 2];

	public:
		Tree(void);
		inline void clear(void);
		inline void propagate(void);
		inline void setNumber(int pos, int value);
		inline int getAnd(int start, int end, int iStart = 0, int iEnd = SIZE - 1, int pos = 1) const;
};

int tests,
	numbers,
	moves,
	number,
	res;
Tree tree;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		tree.clear();
		scanf("%d %d", &numbers, &moves);
		moves = numbers / 2 < moves?numbers / 2:moves;
		for(int n = 0; n < numbers; ++ n)
		{
			scanf("%d", &number);
			tree.setNumber(n, number);
		}

		tree.propagate();
		for(int n = 0; n < numbers; ++ n)
		{
			if(n < moves)
				res = tree.getAnd((numbers + n - moves) % numbers, numbers - 1) & tree.getAnd(0, n + moves);

			else if(n + moves >= numbers)
				res = tree.getAnd(n - moves, numbers - 1) & tree.getAnd(0, (n + moves) % numbers);

			else
				res = tree.getAnd(n - moves, n + moves);

			printf("%d%c", res, n + 1 == numbers?'\n':' ');
		}
	}

	return 0;
}

Tree::Tree(void)
{
	this->clear();
	return;
}

inline void Tree::clear(void)
{
	for(unsigned int s = 0; s < this->SIZE * 2; ++ s)
		this->data[s] = (1 << 30) - 1;

	return;
}

inline void Tree::propagate(void)
{
	for(unsigned int s = this->SIZE - 1; s; -- s)
		this->data[s] = this->data[s * 2] & this->data[s * 2 + 1];

	return;
}

inline void Tree::setNumber(int pos, int value)
{
	this->data[this->SIZE + pos] = value;
	return;
}

inline int Tree::getAnd(int start, int end, int iStart, int iEnd, int pos) const
{
	if(start == iStart && end == iEnd)
		return this->data[pos];

	int iMiddle = (iStart + iEnd) / 2;
	if(end <= iMiddle)
		return this->getAnd(start, end, iStart, iMiddle, pos * 2);

	if(start > iMiddle)
		return this->getAnd(start, end, iMiddle + 1, iEnd, pos * 2 + 1);

	return this->getAnd(start, iMiddle, iStart, iMiddle, pos * 2) & this->getAnd(iMiddle + 1, end, iMiddle + 1, iEnd, pos * 2 + 1);
}
