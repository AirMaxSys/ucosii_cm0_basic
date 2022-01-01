#ifndef	_UTILS_H
#define	_UTILS_H

#include <stdint.h>

uint32_t m_strlen(const char *s);
void *m_memcpy(void *dst, const void *src, uint32_t n);
char m_putc(char ch);
int m_puts(char *s);

#endif
