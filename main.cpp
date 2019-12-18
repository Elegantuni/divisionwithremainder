#include <ncurses.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		cout << argv[0] << " <number> <divisor>" << endl;

		return 1;
	}

	const int maxlength = 100;
	char *data1 = argv[2];
	char *data2 = argv[1];
	int number1 = atoi(argv[1]);
	int divisor1 = atoi(argv[2]);
	int thenumber1[maxlength];
	int counter = 0;
	int stepper = 1;
	int ch;
	int data1size = strlen(data1);
	int data2size = strlen(data2);
	int buffernumber1;

	if(strlen(data1) > 8)
	{
		cout << "99999999 is the max value of divisor" << endl;

		return 1;
	}

	if(strlen(data2) > 8)
	{
		cout << "99999999 is the max value of number" << endl;
		
		return 1;
	}

	if(divisor1 == 0)
	{
		cout << "divisor must not be 0" << endl;

		return 1;
	}

	for(int i = 0; i < maxlength; i++)
	{
		thenumber1[i] = -1;
	}
	
	while(number1 / stepper != 0)
	{
		counter += 1;
		stepper *= 10;
	}

	stepper /= 10;

	if(number1 >= divisor1)
  	{
		thenumber1[0] = number1 / stepper;

		for(int i = counter - 1, j = 1; i > 0; i--, j *= 10)
		{
			thenumber1[i] = number1 / j % 10;
		}
	}
	else
	{
		thenumber1[0] = atoi(argv[1]);
	}
	
	initscr();
	noecho();
	cbreak();

	int x = 0;
	int y = 2;
	int ansx = 5;
	int ansy = 0;
	int cordx = 0;
	int cordy = 0;
	int width = 80;
	int height = 50;

	resizeterm(height, width);

	while((ch = getch()) != 'q')
	{
		clear();
		x = 0;
		y = 2;
	
		for(int i = 0; i <= data2size; i++)
		{
			if(((cordy / 24) == (1 / 24)))
			{
				mvprintw(1 % 24, data1size + 2 + i, "%c", '_');
		
			}
		}
		
		if(((cordy / 24) == (y / 24)))
		{
			mvprintw(y % 24, x, "%d | %d", divisor1, number1);
		}

		y++;

		int index1 = 0;
		int bufferanswer1 = data1size + 3;
		int theproduct1;
		int thequotient1;
		int theanswer1;

		if(divisor1 <= thenumber1[index1])
		{
			buffernumber1 = thenumber1[index1];
			index1++;
		}
		else if(number1 >= divisor1)
		{
			buffernumber1 = thenumber1[index1] * 10;
			index1++;
			buffernumber1 += thenumber1[index1];
			index1++;
		}
		else if(number1 == 0)
		{
			buffernumber1 = 0;
		}
		else
		{
			buffernumber1 = thenumber1[index1];

			if(thenumber1[index1] <= counter)
			{
				index1++;
			}
		}
	
		while(index1 <= counter)
		{
			thequotient1 = buffernumber1 / divisor1;
			if(number1 >= divisor1)
			{
				if(((cordy / 24) == (0 / 24)))
				{
					mvprintw(0 % 24, data1size+3+index1-1, "%d", thequotient1);
				}
			}
			else
			{
				if(((cordy / 24) == (0 / 24)))
				{
					mvprintw(0 % 24, data1size+2+data2size, "%d", thequotient1);
				}
			}
			bufferanswer1++;
			theproduct1 = thequotient1 * divisor1;
			theanswer1 = buffernumber1 - theproduct1;
			if(number1 >= divisor1)
			{
				if(thenumber1[index1] != -1)
				{
					if(theproduct1 < 100)
					{
						if(((cordy / 24) == (y / 24)))
						{
							mvprintw(y % 24, data1size+2+index1-1, "%2d", theproduct1);
						}
					
					}
					else
					{
						if(((cordy / 24) == (y / 24)))
						{
							mvprintw(y % 24, data1size+2+index1-2, "%2d", theproduct1);
						}
					}
				}
				else
				{
					if(((cordy / 24) == (y / 24)))
					{
						mvprintw(y % 24, data1size+2+index1-1, "%2d", theproduct1);
					}	
				}
				if(((cordy / 24) == (y / 24)))
				{
					mvprintw(y % 24, data1size+1, "%c", '-');
				}
				y++;
				for(int i = 0; i <= data2size; i++)
				{
					if(((cordy / 24) == (y / 24)))
					{
						mvprintw(y % 24, data1size+2+i, "%c", '-');
					}
				}
				y++;
				if(thenumber1[index1] != -1)
				{
					if(((cordy / 24) == (y / 24)))
					{
						mvprintw(y % 24, data1size+2+index1-1, "%2d%d", theanswer1, thenumber1[index1]);
					}
				}
				else
				{
					if(((cordy / 24) == (y / 24)))
					{
						mvprintw(y % 24, data1size+2+index1-1, "%2d", theanswer1);
					}
				}
				y++;
				buffernumber1 = theanswer1 * 10 + thenumber1[index1];
				index1++;
			}
			else
			{
					if(((cordy / 24) == (y / 24)))
					{
						mvprintw(y % 24, data1size+2+data2size, "%d", theproduct1);
					}
					if(((cordy / 24) == (y / 24)))
					{
						mvprintw(y % 24, data1size+1, "%c", '-');
					}
					y++;
					for(int i = 0; i <= data2size; i++)
					{
						if(((cordy / 24) == (y / 24)))
						{
							mvprintw(y % 24, data1size+2+i, "%c", '-');
						}
					}
					y++;
					if(((cordy / 24) == (y / 24)))
					{
						mvprintw(y % 24, data1size+3, "%d", theanswer1);
					}
					break;
			}
		}

		if(ch == 'w')
		{
			cordy--;

			if(cordy < 0)
			{
				cordy = 0;
			}
		}
		else if(ch == 's')
		{
			cordy++;

			if(cordy > height - 1)
			{
				cordy = height - 1;
			}
		}
	
		move(cordy, cordx);

		refresh();
	}
	
	endwin();
	
	return 0;
}

