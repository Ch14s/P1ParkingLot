#if !defined(C_LOG)
#define C_LOG

/**
 * @brief Function for logging to file
 * 
 * @param path Pointer to path
 * @param message string message
 * 
 * @return  Returns 0 for successfull operation
 */
void clog(const char *path, const char* message);

#endif // C_LOG
