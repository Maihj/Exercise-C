What the program do
1.Use a secure channel SSL to transfer message during the server and the client.
2.The server(process A) sends a secret message to process B and C, while others can't get this secret message.
3.The client(B and C) know the password so that can get the secret message.
4.The certificate(server.pem) makes the client(B and C) know whether the server is A or not.

Steps
1.sudo apt-get install openssl libssl libssl-dev.
2.Run "make", regardless of the warnings.
3.Run "./secure_server".
4.Run "./secure_client IP_address", and then enter the password.
