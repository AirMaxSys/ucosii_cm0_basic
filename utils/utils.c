#include "utils.h"
#include "main.h"

extern UART_HandleTypeDef huart2;

size_t m_strlen(const char *s)
{
	assert_param(NULL == s);

	size_t len = 0;

	while (*s++ != '\0')
		len++;
	return len;
}

void *m_memcpy(void *dst, const void *src, size_t n)
{
	assert_param(NULL == dst);
	assert_param(NULL == src);

	size_t i = 0;
	char *pdst = (char *)dst;
	char *psrc = (char *)src;

	for (; i < n; ++i)
		*(pdst + i) = *(psrc + i);
	
	return dst;
}

char m_putc(char ch)
{
	if (HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY) != HAL_OK)
		return -1;

	return ch;
}

int m_puts(char *s)
{
	assert_param(NULL == s);

	uint16_t size = m_strlen(s);

	if (HAL_UART_Transmit(&huart2, (uint8_t *)s, size, HAL_MAX_DELAY) != HAL_OK)
		return -1;
	if (m_putc('\n') < 0)
		return -1;

	return 0;
}
