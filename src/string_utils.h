#ifndef __DOCTRA_STRING_UTILS_H__
#define __DOCTRA_STRING_UTILS_H__

// Pattern
bool string_match_start (const char*, const char*);
bool string_match_end (const char*, const char*);

// Misc
char* string_recat (char*, const char*);

// Span
char* strspan_c (const char*, const char*);
char* strspan (const char*, const char*, const char*);

#endif /* __DOCTRA_STRING_UTILS_H__ */

