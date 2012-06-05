#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* The server sends the secret message. */
int main(int argc, char* argv[]){
    int my_fd, client_fd;
    int client_len;
    struct sockaddr_in server, client;
    int i;
    char buffer1[] = "This is a secret message.\n";
    char buffer2[] = "Wrong password.\n";
    char buffer3[20];
    char passwd[] = "123456";

    /* use a secure channel: SSL */    
    SSL_METHOD *my_ssl_method;
    SSL_CTX *my_ssl_ctx;
    SSL *my_ssl;

    SSL_library_init();    
    /* initialize the internal state of the library */
    OpenSSL_add_all_algorithms();
    /* initialize the library's error handling capabilities */
    SSL_load_error_strings();
    
    /* choose an encryption method */
    my_ssl_method = TLSv1_server_method();
    
    my_ssl_ctx = SSL_CTX_new(my_ssl_method);
    if (my_ssl_ctx == NULL){
	ERR_print_errors_fp(stderr);
	exit(-1);
    }
    
    /* the client authenticates the server by the certificate */
    SSL_CTX_use_certificate_file(my_ssl_ctx, "server.pem", SSL_FILETYPE_PEM);
    SSL_CTX_use_PrivateKey_file(my_ssl_ctx, "server.pem", SSL_FILETYPE_PEM);
    
    if (!SSL_CTX_check_private_key(my_ssl_ctx)){
	fprintf(stderr, "Private key does not match certificate.\n");
	exit(-1);
    }

    my_fd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(6666);
    server.sin_addr.s_addr = INADDR_ANY;
    bind(my_fd, (struct sockaddr *)&server, sizeof(server));
    listen(my_fd, 5);
    
    while (1){
	client_len = sizeof(client);
	bzero(&client, client_len);
	client_fd = accept(my_fd, (struct sockaddr *)&client, (socklen_t *)&client_len);
	
	my_ssl = SSL_new(my_ssl_ctx);
	if (my_ssl == NULL){
	    ERR_print_errors_fp(stderr);
	    exit(-1);
	}

	/* associate the SSL structure with the client socket */
	SSL_set_fd(my_ssl, client_fd);
	if (SSL_accept(my_ssl) <= 0){
	    ERR_print_errors_fp(stderr);
	    exit(-1);
	}
	//printf("[%s, %s]\n", SSL_get_version(my_ssl), SSL_get_cipher(my_ssl));

	memset(buffer3, '\0', sizeof(buffer3));
	
	/* read the password passed by the client */
	SSL_read(my_ssl, buffer3, sizeof(buffer3));
	
	/* compare the real password with that passed by the client */
	for (i = 0; i < strlen(buffer3); i++){
	    if (buffer3[i] != passwd[i] || strlen(buffer3) != strlen(passwd)){
		SSL_write(my_ssl, buffer2, strlen(buffer2));
		break;
	    }
	}

	/* the password passed by the client is true */
	if (i == strlen(passwd))
	    SSL_write(my_ssl, buffer1, strlen(buffer1));
	
	SSL_shutdown(my_ssl);
	SSL_free(my_ssl);
	close(client_fd);
    }
    
    SSL_CTX_free(my_ssl_ctx);

    return 0;
}
