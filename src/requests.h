#ifndef REQUESTS_H_
#define REQUESTS_H_

int init_libcurl();
void cleanup_libcurl();
int search_anime(size_t (*f)(void *, size_t, size_t, void *));

#endif