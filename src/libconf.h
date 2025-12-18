#if !defined(LIBCONF_H)
#define LIBCONF_H
#define CONF_VALUE_LENGTH 50
#define CONF_KEY_LENGTH 50
typedef struct _config_i
{
    char key[CONF_KEY_LENGTH];
    char value[CONF_VALUE_LENGTH];
} _config_i;
typedef struct _config_c
{
    _config_i *_config_a; // points to an array of _config_a
    size_t count;
} _config_c;

/**
 * @brief Function for initializing the config file
 * 
 * @param path path to config file
 */
void initializeConfigFile(const char *path);

/**
 * @brief Get the Config Value object
 * 
 * @param key 
 * @return char* value
 */
char *getConfigValue(const char *key);

/**
 * @brief Frees the memory allocated for config
 * 
 */
void freeConfig();

#endif // LIBCONF_H
