#ifndef PSTR
#define PSTR
#ifndef PSTR_MAXLEN
#define PSTR_MAXLEN 4096
#endif

typedef struct pstr
{
    char chars[PSTR_MAXLEN];
    int len;
    int (*size)(struct pstr *self);

} pstr;
 

int pstr_pnd(pstr *s, const char *toAdd);

int pstr_pndc(pstr *s, const char c);

int pstr_pndstr(pstr *s1, const pstr *s2);

int pstr_eq(const pstr *s1, const pstr *s2);
#endif /* PSTR */
