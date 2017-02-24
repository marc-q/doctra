#ifndef __DOCTRA_CONFIG_H__
#define __DOCTRA_CONFIG_H__

// Not customizable once are defined here:
#define DOC_PATTERN_RETURN "Return: "
#define DOC_PATTERN_FUNCTION "()\n"
#define DOC_PATTERN_MEMBER '@'
#define DOC_PATTERN_MDELIM " - "
#define DOC_PATTERN_STRUCT "struct "

// Customizable once are define here:
enum doc_pattern
{
	DOC_PATTERN_ENTER = 0,
	DOC_PATTERN_EXIT,
	DOC_PATTERN_BLOCK,
	DOC_PATTERN_LAST
};

/**
 * struct doc_config
 * @len_return - Length of the return pattern.
 * @len_mdelim - Length of the mdelim pattern.
 * @len_struct - Length of the struct pattern.
 * @pattern - Customizable patterns.
 *
 * Holds the configuration.
 */
struct doc_config
{
	size_t len_return;
	size_t len_mdelim;
	size_t len_struct;
	char *pattern[DOC_PATTERN_LAST];
};

void config_init (struct doc_config*);
void config_free (struct doc_config*);

#endif /* __DOCTRA_CONFIG_H__ */
