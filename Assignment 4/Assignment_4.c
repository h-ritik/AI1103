# include <stdio.h> 
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

int main()
{
	// define the factors
	char factors[] = "ABCD";
	int n = 4;
	
	int l = 1 << n;
	int columns[l];
	for (int i = 0; i < l; ++i)
	{
		columns[i] = i;
	}

	// define the effect to check whethers it's confounded
	char effect[] = "ABC";
	int e=3;

	char* pos[l/2];
	char* neg[l/2];
	
	int x=0,y=0;

	for (int i = 0; i < l; ++i)
	{
		
		int parity = 0;
		char head[n+1];
		for (int j = 0; j < n+1; ++j)
			head[j]='\0';
		int k=0;

		for (int j = 0; j < n; ++j)
		{
			if (i&(1<<j))
			{
				if (strchr(effect,factors[j]) != NULL)
				{
					parity++;
				}
				head[k] = tolower(factors[j]);
				k++;
			}
		}
		if ((e-parity)&1)
		{	
			if (*head == '\0')
			{
				neg[y] = "(1)";
				y++;
			}
			else
			{
				neg[y] = malloc(sizeof(head));
				strcpy(neg[y],head);
				y++;
			}
		}
		else
		{	
			if (*head=='\0')
			{
				pos[x] = "(1)";
				x++;
			}
			else
			{
				pos[x] = malloc(sizeof(head));
				strcpy(pos[x],head);
				x++;
			}
		}

	}
	printf("BLOCK1: ");
	for (int k = 0; k < l/2; ++k)
	{
		printf("%s ",pos[k]);
	}
	printf("\n");
	printf("BLOCK2: ");
	for (int k = 0; k < l/2; ++k)
	{
		printf("%s ",neg[k]);
	}
	printf("\n");
	return 0;
}