#ifndef __DOCTRA_CONFIG_H__
#define __DOCTRA_CONFIG_H__

enum doc_pattern
{

	DOC_PATTERN_ENTER = 0,
	DOC_PATTERN_EXIT,
	DOC_PATTERN_BLOCK,
	DOC_PATTERN_RETURN,
	DOC_PATTERN_FUNCTION,
	DOC_PATTERN_LAST
};

struct doc_config
{
	char *pattern[DOC_PATTERN_LAST];
};

void config_init (struct doc_config*);
void config_free (struct doc_config*);

#endif /* __DOCTRA_CONFIG_H__ */
