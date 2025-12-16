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

/**
 * @brief Function for logging data into csv file. Initiaplize by calling with colum names
 * 
 * @param path path to file
 * @param data csv line
 * @return int 1=success, 0 = failure
 */
int logData(const char *path, const char *data);

#endif // C_LOG
