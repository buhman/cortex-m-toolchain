/* original atoi implementation, by me. All of the others are way too obtuse for
   what this actually needs to do */

int
atoi(const char *nptr)
{
  int acc = 0;

  while(*nptr) {
    acc *= 10;
    acc += *nptr - '0';

    nptr++;
  }

  return acc;
}
