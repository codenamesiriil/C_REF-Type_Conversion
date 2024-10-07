#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int	cns_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	cns_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

double	cns_strtod(const char *nptr)
{
	int	base_sign = 1;

	while (cns_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			base_sign *= -1;
		nptr++;
	}
	double	base = 0.0;
	while (cns_isdigit(*nptr))
	{
		base = base * 10 + (*nptr - 48);
		nptr++;
	}
	if (*nptr == '.')
		nptr++;
	int	div = 1;
	while (cns_isdigit(*nptr))
	{
		base = base * 10 + (*nptr - 48);
		div *= 10;
		nptr++;
	}
	base /= div;
	base *= base_sign;
	if (*nptr == 'e' || *nptr == 'E')
		nptr++;
	int	expn_sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			expn_sign *= -1;
		nptr++;
	}
	double expn = 0.0;
	while (cns_isdigit(*nptr))
	{
		expn = expn * 10 + (*nptr -48);
		nptr++;
	}
	expn = pow(10, (expn * expn_sign));
	return (base * expn);
}

int main(void)
{
	char	flt[] = "125.9E-4";
	char	*ptr;

	printf("%lf\n", cns_strtod(flt));
	printf("%lf\n", strtod(flt, &ptr));

	return (0);
}