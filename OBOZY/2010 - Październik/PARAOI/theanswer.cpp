/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int questions,
			 number,
			 money;
char question[10000010];
char answer[16][128] =
{
	"Nie wiem",
	"Naprawde nie mam zielonego pojecia",
	"Kasa sama plynie",
	"Nalezy wziac trzy tabletki Apapu i skoczyc z pierwszego pietra na materac wypchany pierzem",
	"Odpowiem moze kawalem: Co to jest: okragle, niebieskie i nienawidzi czarnych? Swiat",
	"Miej wyje*ane a bedzie Ci dane",
	"Lewa noga to jest ta gdzie duzy palec z prawej strony... w butach g*wno widac ;/",
	"Jamnik może zostawiac za sobą bruzde zaoranej gleby",
	"Elektrodynamika kwantowa wyjasnia takie zjawiska jak rozszczepianie poziomow energetycznych atomu",
	"A w ktorym się z dwoch kwarkow dolnych d i staja sie z operatorem casimira dla grupy poincarego",
	"Biale jest biale, czarne jest czarne a czerwone jest wredne",
	"Nie bedzie niczego",
	"To dla mnie moj pierwszy raz",
	"Jesli nie osiagniemy sukcesu, grozi nam ryzyko porazki",
	"Ja jestem kompetentny",
	"Twoja stara",
};

inline static unsigned int count(unsigned int quest, unsigned int ans);
inline static unsigned int len(unsigned int number);

int main(void)
{
	srand(time(0));
	scanf("%u", &questions);
	for(unsigned int q = 0; q < questions; ++ q)
	{
		getchar();
		scanf("%[^\n]s", question);
		number = rand() % 16;
		money = count(strlen(question), strlen(answer[number]));
		printf("%s. To bedzie kosztowalo %u$.\n", answer[number], money);
	}

	return 0;
}

inline static unsigned int count(unsigned int quest, unsigned int ans)
{
	unsigned int result = (quest + ans + 25) * 42,
				 orig = len(result);
	result += len(result) * 42;

	if(orig < len(result))
	{
		result -= orig * 42;
		orig = len(result);
		result += orig * 42;
	}

	return result;
}

inline static unsigned int len(unsigned int num)
{
	unsigned int result = 1;
	num /= 10;
	while(num > 0)
	{
		++ result;
		num /= 10;
	}

	return result;
}
