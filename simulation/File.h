#if !defined(FILE_)
#define FILE_

char *read_file(const char *path);
char **tokensFromFile(const char *path);
long sizeOfFile(const char *path);
#endif // FILE_
