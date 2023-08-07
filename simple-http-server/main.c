#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <regex.h>
#include <string.h>

int BUFFER_SIZE = 1000;

char *get_file_extension(char filename[100]){
    char *extension;

    extension = strchr(filename, '.');
    return extension;
}

void *handle_client(void *arg){
    int client_fd = *((int *)arg);
    char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));

    ssize_t received_bytes = recv(client_fd, buffer, BUFFER_SIZE, 0);
    if(received_bytes > 0){
        regex_t regex;
        regcomp(&regex, "^GET /([^ ]*) HTTP/1", REG_EXTENDED);
        regmatch_t matches[2];

        if(regexec(&regex, buffer, 2, matches, 0) == 0) {
            buffer[matches[1].rm_eo] = '\0';
            char *file_name = buffer + matches[1].rm_so;
            // char *file_name = url_decode(url_encoded_file_name);

            char file_ext[32];
            strcpy(file_ext, get_file_extension(file_name));

            char *response = (char *)malloc(BUFFER_SIZE * 2 * sizeof(char));
            size_t response_len;
            build_http_response(file_name, file_ext, response, &response_len);

            send(client_fd, response, response_len, 0);

            free(response);
            free(file_name);
        }
        regfree(&regex);
    }
    close(client_fd);
    free(arg);
    free(buffer);
    return NULL;
}

int main(){
    int server_fd;
    struct sockaddr_in server_addr;
    
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Socket failed.");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8082);

    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket bind failed.");
        exit(EXIT_FAILURE);
    }

    if(listen(server_fd, 10) < 0) {
        perror("Listen failed.");
        exit(EXIT_FAILURE);
    }

    while(1){
        struct socketaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int *client_fd = malloc(sizeof(int));

        if((*client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0){
            perror("Error on accepting the connection.");
            continue;
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)client_fd);
        pthread_detach(thread_id);
    }

    return 0;
}