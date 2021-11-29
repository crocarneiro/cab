#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

void init_libcurl()
{
    curl_global_init(CURL_GLOBAL_ALL);
}

void cleanup_libcurl()
{
    curl_global_cleanup();
}

int search_anime(char *keyword, size_t (*callback_function)(void *, size_t, size_t, void *))
{
    CURL *hnd = curl_easy_init();

    char *final_keyword = NULL;
    final_keyword = curl_easy_escape(hnd, keyword, strlen(keyword));

    char *default_url = "https://jikan1.p.rapidapi.com/search/anime?q=%s";
    char *final_url = (char *) malloc(sizeof(char) * (strlen(final_keyword) + strlen(default_url) + 1));
    sprintf(final_url, default_url, final_keyword);

    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(hnd, CURLOPT_URL, final_url);
    curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, callback_function);

    free(final_url);
    free(final_keyword);

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "x-rapidapi-host: jikan1.p.rapidapi.com");
    headers = curl_slist_append(headers, "x-rapidapi-key: 6ea44ecb6bmshc9babab79bd5d63p154df5jsn297905bedb4c");
    //headers = curl_slist_append(headers, "Content-Type: application/json; charset=utf-8");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

    CURLcode ret = curl_easy_perform(hnd);
    if(ret != CURLE_OK)
    {
        fprintf(stderr, "Error making request: %s.", curl_easy_strerror(ret));
    }

    return 0;
}