#include <stdio.h>

#include "cJSON/cJSON.h"

void display_results(char *body)
{
    cJSON *json = NULL;
    json = cJSON_Parse(body);
    if(json == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", error_ptr);
            printf("\n\n\n\n\n");
            printf("%s", body);
        }
    }
    cJSON *results = cJSON_GetObjectItemCaseSensitive(json, "results");
    cJSON *result = NULL;

    cJSON_ArrayForEach(result, results)
    {
        cJSON *mal_url = cJSON_GetObjectItemCaseSensitive(result, "url"),
        *title = cJSON_GetObjectItemCaseSensitive(result, "title"),
        *synopsis = cJSON_GetObjectItemCaseSensitive(result, "synopsis"),
        *episodes = cJSON_GetObjectItemCaseSensitive(result, "episodes"),
        *score = cJSON_GetObjectItemCaseSensitive(result, "score");

        printf("Title: %s\tEpisodes: %d\tScore: %lf",
            cJSON_GetStringValue(title),
            (int)cJSON_GetNumberValue(episodes),
            cJSON_GetNumberValue(score)
        );
        printf("\nMAL URL: %s", cJSON_GetStringValue(mal_url));
        printf("\nSynopsis: %s", cJSON_GetStringValue(synopsis));
        printf("\n\n");
    }
}