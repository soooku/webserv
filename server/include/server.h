#ifndef	SERVER_H
#define	SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

//echo_server.c
void	echo_server(char *server_address, unsigned short port_number);
//tcp_receiver_socket.c
int		tcp_receiver_socket(char *server_address, unsigned short port_number);
//cho_receive_request_and_send_reply.c
ssize_t	echo_receive_request_and_send_reply(int connection_socket);
//echo_select_server.c
void	echo_select_server(char *server_address, unsigned short port_number);
//echo_handle_request_and_reply.c
void	echo_handle_request_and_reply(int socket, int maxfds, int *next_maxfds, fd_set *readfds_save);
#endif
