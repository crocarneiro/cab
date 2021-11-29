#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    init_libcurl();

    search_anime("Trigun", handle_result);

    cleanup_libcurl();
}