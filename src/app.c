#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "requests.h"
#include "display.h"

char *responseBody = '\0';
size_t fullsize = 0;

size_t handle_result(void *buffer, size_t size, size_t nmemb, char *userp)
{
    fullsize += size * nmemb;
    responseBody = (char*) realloc(responseBody, fullsize * sizeof(char));
    strcat(responseBody, buffer);

    return size * nmemb;
}

void menu()
{
    char keyword[100];
    fprintf(stdout, "Type a keyword and press enter to search for an anime: ");
    fgets(keyword, 100, stdin);
    keyword[strlen(keyword) - 1] = '\0';

    printf("SEARCH RESULTS");
    printf("\nKeyword: %s", keyword);
    printf("\n\n");

    responseBody = (char *) malloc(sizeof(char));
    responseBody[0] = '\0';

    search_anime(keyword, handle_result);
    display_results(responseBody);

    free(responseBody);
}

void run_app()
{
    init_libcurl();
    menu();
    cleanup_libcurl();
}