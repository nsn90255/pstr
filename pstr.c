#include "pstr.h"

typedef struct pstr
{
    char chars[PSTR_MAXLEN];
    int len;
    int (*size)(struct pstr *self);
} pstr;

int get_size(pstr *self)
{
    return (self->len + 1) * sizeof(char);
}
    
int pstr_pnd(pstr *s, const char *toAdd)
{
    int i = 0;
    while (toAdd[i])
    {
        if (s->len >= sizeof(s->chars)-1)
	    return (1);

        s->chars[s->len] = toAdd[i];
        s->len++;
        i++;
    }
    return (0);
}
int pstr_pndstr(pstr *s1, const pstr *s2)
{
    return pstr_pnd(s1, s2->chars);
}
int pstr_pndc(pstr *s, const char c)
{
    if (s->len >= sizeof(s->chars)-1)
	return (1);

    s->chars[s->len] = c;
    s->len++;
    return (0);
}

int pstr_eq(const pstr *s1, const pstr *s2)
{
    char *p1 = (char *)s1->chars;
    char *p2 = (char *)s2->chars;
    while (*p1 == *p2++)
	if (*p1++ == 0)
	    return (0);
    return (*(unsigned char *)p1 - *(unsigned char *)--p2);
}
