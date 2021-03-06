#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

int main() {
    CURL *curl = curl_easy_init();
    if (curl) {
        char *string = "hello world";
        printf("%lu\n", strlen(string)); // 11

        char *output = curl_easy_escape(curl, string, strlen(string));
        if (output) {
            printf("Encoded: %s\n", output); // Encoded: hello%20world
            curl_free(output);
        }
    }
    return 0;
}