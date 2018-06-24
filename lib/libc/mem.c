#include <stddef.h>

void *
memcpy (void *dst0,
	const void *src0,
	size_t length)
{
  char *dst = (char *) dst0;
  const char *src = (char *) src0;

  while (length--)
    {
      *dst++ = *src++;
    }

  return dst0;
}

void *
memset (void *buf0,
	int c,
	size_t len)
{
  char *buf = (char *) buf0;

  while (len--)
    *buf++ = (char) c;

  return buf0;
}

int
memcmp (const void *m1,
	const void *m2,
	size_t length)
{
  const unsigned char *s1 = (const unsigned char *) m1;
  const unsigned char *s2 = (const unsigned char *) m2;

  while (length--)
    {
      if (*s1 != *s2)
	{
	  return *s1 - *s2;
	}
      s1++;
      s2++;
    }
  return 0;
}

void *
memmove (void *dst0,
	const void *src0,
	size_t length)
{
  char *dst = dst0;
  const char *src = src0;

  if (src < dst && dst < src + length)
    {
      /* Have to copy backwards */
      src += length;
      dst += length;
      while (length--)
	{
	  *--dst = *--src;
	}
    }
  else
    {
      while (length--)
	{
	  *dst++ = *src++;
	}
    }

  return dst0;
}
