#include<stdio.h>

ssize_t signum(ssize_t input);

int main()
{
		ssize_t  ip = -10;
		printf("signum of (%ld) = %ld\n", ip, signum(ip));
		return 0;
}
