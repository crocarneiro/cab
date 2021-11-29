#include <stdio.h>
#include "requests.h"

size_t handle_result(void *buffer, size_t size, size_t nmemb, void *userp)
{
    char *responseBody = (char *) malloc(sizeof(char) * nmemb);
    strcpy(responseBody, (char *) buffer);
    fprintf(stdout, "%s", responseBody);
    free(responseBody);

    return nmemb;
}

void run_app()
{
    char *responseBody;
    init_libcurl();
    search_anime(handle_result);
    cleanup_libcurl();
}