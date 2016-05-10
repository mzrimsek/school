/**
 * Mike Zrimsek
 * Systems Programming
 * Homework 6 - lserv3
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <sys/errno.h>

#define	MSGLEN		128
#define RECLAIM_INTERVAL 5

int main(int ac, char *av[])
{
		struct sockaddr client_addr;
		socklen_t addrlen;
		char buf[MSGLEN];
		int	ret, sock;
		void ticket_reclaim();
		void show_ticket_array_up(int );
		void show_ticket_array_quit(int );
		unsigned time_left;

		sock = setup();
		signal(SIGALRM, ticket_reclaim);
		signal(SIGHUP, show_ticket_array_up);
		signal(SIGQUIT, show_ticket_array_quit);
		alarm(RECLAIM_INTERVAL);

		while(1){
				addrlen = sizeof(client_addr);
				ret = recvfrom(sock, buf, MSGLEN, 0, (struct sockaddr *)&client_addr, &addrlen);
				if (ret != -1){
						buf[ret] = '\0';
						narrate("GOT:", buf, &client_addr);
						time_left = alarm(0);
						handle_request(buf, &client_addr, addrlen);
						alarm(time_left);
				}
				else if (errno != EINTR){
						perror("recvfrom");
				}
		}
}
