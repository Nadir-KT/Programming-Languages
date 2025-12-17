#include <stdio.h>

void *my_memcpy(void *dest, const void *src, size_t num) {
  // Cast for pointer arithmetic
  char *d = (char *)dest;
  const char *s = (const char *)src;

  // Loop to copy each byte
  for (size_t i = 0; i < num; i++) {
    d[i] = s[i];
  }

  // Return destination pointer
  return dest;
}

int main() {
  char source[] = "Hello, world!";
  char destination[20];

  // Copy using our function
  my_memcpy(destination, source, sizeof(source));

  printf("Copied string: %s\n", destination);
  return 0;
}

/*
#include <string.h>

void *memcpy(void *dest, const void *src, size_t n) {
    char *d = (char *) dest;
    const char *s = (const char *) src;

    while (n--) {
        *d++ = *s++;
    }

    return dest;
}
*/