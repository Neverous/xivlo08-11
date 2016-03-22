/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

struct Number
{
	long long unsigned int iNumber;
	int iLength;

	Number(long long unsigned int number = 0)
	{
		iNumber = number;
		iLength = 0;
	}
	
	Number operator*(const Number &B) const
	{
		Number C;
		unsigned int move = 0;
		for(long long unsigned int b = B.iNumber; b > 0; b >>= 1, ++ move)
			if(b%2)
				C.iNumber ^= iNumber << move;
		// mnożenie polega na "przesuwaniu" i xor`owaniu:
		/* np.: 1101 * 111:
		 * 1 111
		 * 1  111
		 * 0   111
		 * 1    111
		 * ----------
		 *   100011
		 */
		
		return C;
	}

	Number operator/(Number B)
	{
		Number C;
		long long unsigned int a = iNumber,
							   act = B.iNumber;
		int last = 0,
			max = length() - B.length() + 1;
		for(int move = 0; a > 0 && last < max; a >>= 1, ++ move)
		{
			if(a%2 == act%2)
			{
				last = move;
				C.iNumber += (long long unsigned int)1 << move; // PAMIĘTAJ O LONG LONGACH... SAMO SIĘ NIE ZRZUTUJE!!!!
			}
			
			else
				act ^= B.iNumber;

			act >>= 1;
			act ^= B.iNumber;
		} // dzielenie trochę podobnie
		/* np: 100011 : 111
		 * x 111 <- stwierdzam że muszę mieć tę pierwszą jednykę => x = 1
		 * y  111 <- stwierdzam że na drugim miejscu musi być zero => y = 1
		 * z   111 <- tu musze mieć zero żeby na trzecim też było zero => z = 0
		 * w    111 <- tu musze mieć jedynke żeby na czwartym było zero => w = 1 // po tym wychodzi mi że iloczyn ma być 0 i kończy się pętla...
		 * ---------------
		 *   100011 : 111 = 1101
		 */
		if(last >= max) // nie dzieli się!
			return Number(0);
		
		return C;
	}

	Number operator+=(const Number &B)
	{
		iNumber += B.iNumber;
		iLength = 0;
		return *this;
	}

	Number operator+(const Number &B) const
	{
		return Number(iNumber + B.iNumber);
	}
	

	int length(void)
	{
		static char lengths[262128];
		if(iNumber < 262128 && lengths[iNumber])
			return lengths[iNumber];

		if(!iLength)
		{
			long long unsigned int tmp = iNumber;
			while(tmp)
			{
				tmp >>= 1;
				iLength ++;
			}

			if(iNumber < 262128)
				lengths[iNumber] = iLength;
		}
		
		return iLength;
	}

	operator bool() const
	{
		return iNumber != 0;
	}

	bool operator!() const
	{
		return iNumber == 0;
	}

	bool operator==(const Number &B) const
	{
		return iNumber == B.iNumber;
	}

	bool operator!=(const Number &B) const
	{
		return iNumber != B.iNumber;
	}

	bool operator<(const Number &B) const
	{
		return iNumber < B.iNumber;
	}

	bool operator<=(const Number &B) const
	{
		return iNumber <= B.iNumber;
	}

	Number operator%(Number B) // jeśli się dzieli to zwraca jeśli nie to zwraca 0
	{
		Number C = *this / B;
		if(C && C.length() == length() - B.length() + 1)
			return C;

		return Number(0);
	}
};

static inline void preprocess(void);
inline int find(Number number);

int size,
	tests,
	primes,
	value;
bool prime;
Number primeT[17000];
long long unsigned int check;

int main(void)
{
	preprocess();
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		check = 0;
		scanf("%d", &size);
		for(int s = 0; s < size; ++ s)
		{
			scanf("%d", &value);
			if(value)
				check += (long long unsigned int)1 << s;
		}

		printf("%d\n", find(Number(check)));
	}

	return 0;
}

static inline void preprocess(void)
{
	for(Number p = 3; p < Number(262128); p += 2)
	{
		prime = true;
		for(int pos = 0; pos < primes && primeT[pos].length() * 2 <= p.length() + 1; ++ pos)
			if(p % primeT[pos])
			{
				prime = false;
				break;
			}

		if(prime)
			primeT[primes ++] = p;
	}
}

inline int find(Number number)
{
	int result = 1,
		count = 0,
		pos = 0;
	Number tmp;
	for(pos = 0; pos < primes && primeT[pos].length() * 2 <= number.length() + 1; ++ pos)
	{
		count = 0;
		while(tmp = number % primeT[pos])
		{
			++ count;
			number = tmp;
		}

		result *= count + 1;
	}

	if(primeT[pos] <= number && number != Number(0)) // musiałem o czymś zapomnieć ;/...
		result *= 2;

	return result - 2 > 0?result - 2:0; // za 1 której nie ma i za number
}


