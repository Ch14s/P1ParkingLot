#if !defined(C_LOG)
#define C_LOG

/**
 * @brief Function for logging to file
 * 
 * @param path Pointer to path
 * @param prefix char[10] prefix for the log entry
 * @param message string message
 * 
 * @return  Returns 0 for successfull operation
 */
int customLog(const char *path, const char* prefix, const char* message);

/**
 * @brief Clears log file
 * 
 * @param path to log file
 */
void clearLogFile(const char* path);

#endif // C_LOG
