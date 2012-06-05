#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* The client receives the secret message safely or be rejected. */
int main(int argc, char* argv[]){
    int my_fd;
    struct sockaddr_in server;
    int i;
    char c;
    char buffer[100];
    /* use a secure channel: SSL */
    SSL_METHOD *my_ssl_method;
    SSL_CTX *my_ssl_ctx;
    SSL *my_ssl;
    char *passwd;
    
    /* enter the IP address */
    if (argc < 1){
	fprintf(stderr, "Usage: %s <ip address>\n", argv[0]);
	exit(1);
    }

    memset(buffer, '\0', sizeof(buffer));

    SSL_library_init();
    /* initialize the internal state of the library */
    OpenSSL_add_all_algorithms();
    /* initialize the library's error handling capabilities */
    SSL_load_error_strings();

    /* choose an encrypted method */    
    my_ssl_method = TLSv1_client_method();
    
    my_ssl_ctx = SSL_CTX_new(my_ssl_method);
    if (my_ssl_ctx == NULL){
	ERR_print_errors_fp(stderr);
	exit(-1);
    }

    my_ssl = SSL_new(my_ssl_ctx);
    if (my_ssl == NULL){
	ERR_print_errors_fp(stderr);
	exit(-1);
    }
    
    my_fd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(6666);
    server.sin_addr.s_addr = inet_addr(argv[1]);
    
    bind(my_fd, (struct sockaddr *)&server, sizeof(server));
    connect(my_fd, (struct sockaddr *)&server, sizeof(server));

    /* associate the SSL structure with the client socket */    
    SSL_set_fd(my_ssl, my_fd);
    
    if (SSL_connect(my_ssl) <= 0){
	ERR_print_errors_fp(stderr);
	exit(-1);
    }

    //printf("[%s, %s]\n", SSL_get_version(my_ssl), SSL_get_cipher(my_ssl));
   
    /* the client enter the paaword */
    passwd = getpass("Please enter the password: ");
    
    /* send the password to the server */
    SSL_write(my_ssl, passwd, strlen(passwd));

    /* receive a message from the server, a secret message or a rejection */
    SSL_read(my_ssl, buffer, sizeof(buffer));
    printf("%s", buffer);

    SSL_shutdown(my_ssl);
    SSL_free(my_ssl);
    SSL_CTX_free(my_ssl_ctx);
    close(my_fd);
    
    return 0;
}
