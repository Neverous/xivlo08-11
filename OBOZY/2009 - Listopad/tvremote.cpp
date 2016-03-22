/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

int channel,
	newchannel,
	working[16],
	best;
char action[8];

int main(void)
{
	for(int w = 1; w <= 3; ++ w)
		scanf("%d", &working[w]);
	
	scanf("%d", &working[10]);
	for(int w = 4; w <= 6; ++ w)
		scanf("%d", &working[w]);

	scanf("%d", &working[11]);
	for(int w = 7; w <= 9; ++ w)
		scanf("%d", &working[w]);

	scanf("%d %d ", &working[12], &working[0]);

	/* KONIEC WEJŚCIA NIEDZIAŁAJĄCYCH PRZYCISKÓW */

	while(scanf("%s", action) != -1 && action[0] != 'K')
		if(action[1] == 'E')
		{
			scanf("%d ", &channel);
			working[channel] = false;
		} // PSUJ

		else
		{
			scanf("%d %d ", &channel, &newchannel);
			best = 300;
			if(working[10] && best > (100 + newchannel - channel) % 100)
				best = (100 + newchannel - channel) % 100; // Działa UP

			if(working[11] && best > (100 + channel - newchannel) % 100)
				best = (100 + channel - newchannel) % 100; // Działa DOWN

			if(channel == newchannel)
				best = 0;

			for(int v = 0; v < 10; ++ v)
			{
				if(!working[v])
					continue;

				if(working[10] && best > 1 + (100 + newchannel - v) % 100)
					best = 1 + (100 + newchannel - v) % 100;

				if(working[11] && best > 1 + (100 - newchannel + v) % 100)
					best = 1 + (100 - newchannel + v) % 100;

			} // pojedynczo

			if(working[12])
				for(int w = 1; w < 10; ++ w)
				{
					if(!working[w])
						continue;

					for(int v = 0; v < 10; ++ v)
					{
						if(!working[v])
							continue;

						if(working[10] && best > 3 + (100 + newchannel - w * 10 - v) % 100)
							best = 3 + (100 + newchannel - w * 10 - v) % 100;

						if(working[11] && best > 3 + (100 - newchannel + w * 10 + v) % 100)
							best = 3 + (100 - newchannel + w * 10 + v) % 100;

					}
				} // podwojne

			if(newchannel < 10 && working[newchannel] && best > 1)
				best = 1;

			if(working[12] && newchannel >= 10 && working[newchannel % 10] && working[newchannel / 10] && best > 3)
				best = 3;
				

			printf("%d\n", best==300?-1:best);
		} // ZMIEN KANAŁ

	return 0;
}
