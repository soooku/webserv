#include "client.h"
#define BUFFER_SIZE 1024

int echo_client(char *server_address, unsigned short port_number)
{
	int		socketfd;
	char	read_buffer[BUFFER_SIZE];
	char	write_buffer[BUFFER_SIZE];
	int		response;

// open socketfdet
	socketfd = tcp_connect(server_address, port_number);
	if (socketfd < 0)
	{
		fprintf(stderr, "socketfdet error %d\n", socketfd);
		return (1);
	}
// send request to server
	while(1)
	{
		scanf("%s", write_buffer);
		if (write_buffer[0] == EOF)
			break;
		response = echo_send_request(socketfd, write_buffer);
		if (response < 0)
		{
			fprintf(stderr, "echo_send_request()\n");
			close(socketfd);
			return (1);
		}
		printf("send: %d bytes message: [%s]\n", response, write_buffer);

// receive reply from server
		response = echo_receive_reply(socketfd, read_buffer, BUFFER_SIZE);
		if (response < 0)
		{
			fprintf(stderr, "echo_receive_reply()\n");
			close(socketfd);
			return (1);
		}
		printf("received: %d bytes message: [%s]\n", response, read_buffer);
	}
	close(socketfd);
	return (0);
}
