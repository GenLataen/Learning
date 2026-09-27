#include <stdio.h>



int my_strcmp(const char *s1, const char *s2)
{
	while(*s1 != '\0' && *s2 != '\0')
	{
		if(*s1 != *s2)
		{
			return 0;
		}
		s1++;
		s2++;
		
	}
	return (*s1 == '\0' && *s2 == '\0')?1:0;
	
}

int main()
{
	printf( " 比较结果是%d\n",my_strcmp("abc","abcd"));
	printf( " 比较结果是%d\n",my_strcmp("abcd","abcd"));
	
}
