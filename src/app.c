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

void menu()
{
    char keyword[100];
    fprintf(stdout, "Type a keyword to search for an anime, manga, etc: ");
    fgets(keyword, 100, stdin);
    search_anime(keyword, handle_result);
}

void run_app()
{
    init_libcurl();
    menu();
    cleanup_libcurl();
}