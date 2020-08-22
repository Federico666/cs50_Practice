#include <stdio.h>
#include <cs50.h>

int n_digits();
int l_2digits();
int l_1digits();

int main(void)
{

    long input = 0, l_2d = 0, l_1d = 0;
    int counter = 0;

	input = get_long("Number: ");

	//Call function, if invalid print and end. If valid, return N° of digits and check credit card brand
	counter = n_digits(input);

	l_1d = l_1digits(input, counter);
	l_2d = l_2digits(input, counter);

	//Check for 16 digits number
	if ( counter == 16 )
	{
		//IF start with 4, its a Visa
		if( l_1d == 4 )
		{
			printf("VISA\n");
		}
		//Else if start with 51, 52, 53 ,54 or 55 its a Mastercard
		else if(l_2d == 51 || l_2d == 52 || l_2d == 53 || l_2d == 54 || l_2d == 55 )
		{
			printf("MASTERCARD\n");
		}
		else
		{
			printf("INVALID\n");
		}
	}
	//Check for 13 digits number
	else if (counter == 13)
	{
		//IF start with 4, its a Visa
		if( l_1d == 4 )
		{
			printf("VISA\n");
		}
	else
	{
		printf("INVALID\n");
	}
	}
	//Check for 15 digits number
	else if (counter == 15)
	{
		//If starts with 34 or 37 its AMEX
		if( l_2d == 34 || l_2d == 37 )
		{
			printf("AMEX\n");
		}
	else
	{
			printf("INVALID\n");
	}
	}

}


int n_digits(long b)
{

	int csum1 = 0, csum2 = 0, csum3 = 0, a, a_a, a_b, c = 0;

	while (b > 0)
	{
		//a is the digit itself
		a = b%10;
		//If digit is pair, do the checksum 1
		if(c%2 == 0)
		{
			csum1 = csum1 + a;
		}
		//Else, do the checksum 2
		else
		{
			//Multiply the digit by two
			a_a = a*2;
			a_b = a_a;
			//If the result is greater than 9, split it in two digits and add them
			if(a_a > 9)
			{
				while(a_b > 0)
				{
					a_a = a_b%10;
					csum2 = csum2 + a_a;
					a_b=a_b/10;
				}
			}
			//Else, add the digit to csum2
			else
			{
				csum2 = csum2 + a_a;
			}
		}
		//printf("%d\n",a);
		b=b/10;
		c++;
	}	
	//Do the final checksum
	csum3 = csum1 + csum2;
	//If last digit is different from zero, or the digits are less than 13 or more than 16 the card is invalid
	if ( csum3%10 != 0 || c < 13 || c > 16 )
	{
		printf("INVALID\n");
		return 0;
	}
	//Else, return de N° of digits for Type of card filtering
	else
	{
		return c;
	}
}

int l_1digits(long b, int c)
{
	int c1 = 0;
	while( b > 0 && c1 < (c-1))
	{
		b = b/10;
		c1++;
	}

	return b;
}

int l_2digits(long b, int c)
{
	int c1 = 0;
	while( b > 0 && c1 < (c-2))
	{
		b = b/10;
		c1++;
	}

	return b;
}