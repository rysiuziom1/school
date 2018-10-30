#include <stdio.h>
#include <string.h>
#include <ctype.h>

//int (*f)(double*, const int* const);

char* my_strcat(char*, const char*);
char* my_strncat(char*, const char*, size_t);
int my_strcmp(const char*, const char*);
int my_strncmp(const char*, const char*, size_t);
char* my_strcpy(char*, const char*);
char* my_strncpy(char*, const char*, size_t);
char* my_strchr(const char*, int);
char* my_strrchr(const char*, int);

int my_isalpha(int);
int my_isupper(int);
int my_islower(int);
int my_isdigit(int);
int my_isalnum(int);
int my_tolower(int);
int my_toupper(int);


int main()
{
	char s1[10] = "Ala";
	char s2[20] = "Kot";
	char s3[10] = "Alamaw";
	printf("My strchr: %s\nstrchr: %s", my_strrchr(s1, 'a'), strrchr(s1, 'a'));
	
	return 0;
}

char* my_strcat(char* s1, const char* s2)
{
	if(!s1 || !s2)
		return s1;
	int i = strlen(s1), j = 0;
	while(*(s2+j))
	{
		*(s1+i) = *(s2+j);
		i++;
		j++;
	}
	return s1;
}

char* my_strncat(char* s1, const char* s2, size_t num)
{
	if(!s1 || !s2)
		return s1;
	int i = strlen(s1), j = 0;
	while(*(s2+j) && j < num)
	{
		*(s1+i) = *(s2+j);
		i++;
		j++;
	}
	return s1;
}

int my_strcmp(const char* s1, const char* s2)
{
	if(!s1 || !s2)
		return 0;
	int i = 0;
	while(*(s1+i) && *(s2+i))
	{
		if(*(s1+i) != *(s2+i))
			return *(s1+i) - *(s2+i);
		i++;
	}
	if(*(s1+i) == *(s2+i))
		return 0;
	else
		return *(s1+i) - *(s2+i);
}

int my_strncmp(const char* s1, const char* s2, size_t num)
{
	if(!s1 || !s2)
		return 0;
	int i = 0;
	while(*(s1+i) && *(s2+i) && i < num)
	{
		if(*(s1+i) != *(s2+i))
			return *(s1+i) - *(s2+i);
		i++;
	}
	if(*(s1+i) == *(s2+i) || i == num)
		return 0;
	else
		return *(s1+i) - *(s2+i);
}

char* my_strcpy(char* s1, const char* s2)
{
	if(!s1 || !s2)
		return s1;
	int i = 0;
	while(*(s2+i))
	{
		*(s1+i) = *(s2+i);
		i++;
	}
	*(s1+i) = '\0';
	return s1;
}

char* my_strncpy(char* s1, const char* s2, size_t num)
{
	if(!s1 || !s2)
		return s1;
	int i = 0;
	while(*(s2+i) && i < num)
	{
		*(s1+i) = *(s2+i);
		i++;
	}
	while(i < num)
		*(s1+i++) = '\0';
	return s1;
}

char* my_strchr(const char* s, int c)
{
	if(!s)
		return NULL;
	int i = 0;
	while(*(s+i))
	{
		if(*(s+i) == c)
			return (char*)(s+i);
		i++;
	}
	return NULL;
}

char* my_strrchr(const char* s, int c)
{
	if(!s)
		return NULL;
	int i = strlen(s);
	while(i >= 0)
	{
		if(*(s+i) == c)
			return (char*)(s+i);
		i--;
	}
	return NULL;
}

int my_isalpha(int c)
{
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

int my_isupper(int c)
{
	if(c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

int my_islower(int c)
{
	if(c >= 'a' && c <= 'z')
		return 1;
	return 0;
}

int my_isdigit(int c)
{
	if(c >= '0' && c <= '9')
		return 1;
	return 0;
}

int my_isalnum(int c)
{
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return 1;
	return 0;
}

int my_tolower(int c)
{
	if(c >= 'A' && c <= 'Z')
		return c - ('A' - 'a');
	return c;
}

int my_toupper(int c)
{
	if(c >= 'a' && c <= 'z')
		return c + ('A' - 'a');
	return c;
}
