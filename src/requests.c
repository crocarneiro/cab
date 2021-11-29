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

int search_anime(size_t (*f)(void *, size_t, size_t, void *))
{
    CURL *hnd = curl_easy_init();

    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(hnd, CURLOPT_URL, "https://jikan1.p.rapidapi.com/search/anime?q=Attack%20on%%20Titan");
    curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, f);

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "x-rapidapi-host: jikan1.p.rapidapi.com");
    headers = curl_slist_append(headers, "x-rapidapi-key: 6ea44ecb6bmshc9babab79bd5d63p154df5jsn297905bedb4c");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);

    CURLcode ret = curl_easy_perform(hnd);


    return 0;
}