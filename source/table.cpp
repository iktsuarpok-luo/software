#include "table.h"

int Char_to_Int(char* str)
{
	const char* p = str;
	bool neg = false;
	int res = 0;
	if (*str == '-' || *str == '+') {
		str++;
	}

	while (*str != 0) {
		if (*str < '0' || *str > '9') {
			break;
		}
		res = res * 10 + *str - '0';
		str++;
	}

	if (*p == '-') {
		res = -res;
	}
	return res;
}
