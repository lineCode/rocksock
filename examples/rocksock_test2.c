// gcc -Wall -g rocksock.c rocksock_test2.c -o rocksock_test2
/*
 * author: rofl0r
 *
 * License: LGPL 2.1+ with static linking exception
 */
#include <stdio.h>
#include <stdlib.h>
#include "../rocksock.h"

#define chk(X, ACTION) if(X) { rocksock_error_dprintf(2, psock); ACTION; }
#define checkerr chk(ret, exit(2))

char peer0_0[] = {
0x47, 0x45, 0x54, 0x20, 0x2f, 0x64, 0x66, 0x5f,
0x33, 0x31, 0x5f, 0x32, 0x35, 0x5f, 0x77, 0x69,
0x6e, 0x2e, 0x7a, 0x69, 0x70, 0x20, 0x48, 0x54,
0x54, 0x50, 0x2f, 0x31, 0x2e, 0x31, 0x0d, 0x0a,
0x55, 0x73, 0x65, 0x72, 0x2d, 0x41, 0x67, 0x65,
0x6e, 0x74, 0x3a, 0x20, 0x4f, 0x70, 0x65, 0x72,
0x61, 0x2f, 0x39, 0x2e, 0x38, 0x30, 0x20, 0x28,
0x58, 0x31, 0x31, 0x3b, 0x20, 0x4c, 0x69, 0x6e,
0x75, 0x78, 0x20, 0x78, 0x38, 0x36, 0x5f, 0x36,
0x34, 0x3b, 0x20, 0x55, 0x3b, 0x20, 0x65, 0x6e,
0x29, 0x20, 0x50, 0x72, 0x65, 0x73, 0x74, 0x6f,
0x2f, 0x32, 0x2e, 0x37, 0x2e, 0x36, 0x32, 0x20,
0x56, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x2f,
0x31, 0x31, 0x2e, 0x30, 0x31, 0x0d, 0x0a, 0x48,
0x6f, 0x73, 0x74, 0x3a, 0x20, 0x62, 0x31, 0x32,
0x2e, 0x77, 0x69, 0x6d, 0x62, 0x6c, 0x69, 0x2e,
0x63, 0x6f, 0x6d, 0x0d, 0x0a, 0x41, 0x63, 0x63,
0x65, 0x70, 0x74, 0x3a, 0x20, 0x74, 0x65, 0x78,
0x74, 0x2f, 0x68, 0x74, 0x6d, 0x6c, 0x2c, 0x20,
0x61, 0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74,
0x69, 0x6f, 0x6e, 0x2f, 0x78, 0x6d, 0x6c, 0x3b,
0x71, 0x3d, 0x30, 0x2e, 0x39, 0x2c, 0x20, 0x61,
0x70, 0x70, 0x6c, 0x69, 0x63, 0x61, 0x74, 0x69,
0x6f, 0x6e, 0x2f, 0x78, 0x68, 0x74, 0x6d, 0x6c,
0x2b, 0x78, 0x6d, 0x6c, 0x2c, 0x20, 0x69, 0x6d,
0x61, 0x67, 0x65, 0x2f, 0x70, 0x6e, 0x67, 0x2c,
0x20, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x2f, 0x6a,
0x70, 0x65, 0x67, 0x2c, 0x20, 0x69, 0x6d, 0x61,
0x67, 0x65, 0x2f, 0x67, 0x69, 0x66, 0x2c, 0x20,
0x69, 0x6d, 0x61, 0x67, 0x65, 0x2f, 0x78, 0x2d,
0x78, 0x62, 0x69, 0x74, 0x6d, 0x61, 0x70, 0x2c,
0x20, 0x2a, 0x2f, 0x2a, 0x3b, 0x71, 0x3d, 0x30,
0x2e, 0x31, 0x0d, 0x0a, 0x41, 0x63, 0x63, 0x65,
0x70, 0x74, 0x2d, 0x4c, 0x61, 0x6e, 0x67, 0x75,
0x61, 0x67, 0x65, 0x3a, 0x20, 0x65, 0x6e, 0x2d,
0x55, 0x53, 0x2c, 0x65, 0x6e, 0x3b, 0x71, 0x3d,
0x30, 0x2e, 0x39, 0x0d, 0x0a, 0x41, 0x63, 0x63,
0x65, 0x70, 0x74, 0x2d, 0x43, 0x68, 0x61, 0x72,
0x73, 0x65, 0x74, 0x3a, 0x20, 0x69, 0x73, 0x6f,
0x2d, 0x38, 0x38, 0x35, 0x39, 0x2d, 0x31, 0x2c,
0x20, 0x75, 0x74, 0x66, 0x2d, 0x38, 0x2c, 0x20,
0x75, 0x74, 0x66, 0x2d, 0x31, 0x36, 0x2c, 0x20,
0x2a, 0x3b, 0x71, 0x3d, 0x30, 0x2e, 0x31, 0x0d,
0x0a, 0x41, 0x63, 0x63, 0x65, 0x70, 0x74, 0x2d,
0x45, 0x6e, 0x63, 0x6f, 0x64, 0x69, 0x6e, 0x67,
0x3a, 0x20, 0x64, 0x65, 0x66, 0x6c, 0x61, 0x74,
0x65, 0x2c, 0x20, 0x67, 0x7a, 0x69, 0x70, 0x2c,
0x20, 0x78, 0x2d, 0x67, 0x7a, 0x69, 0x70, 0x2c,
0x20, 0x69, 0x64, 0x65, 0x6e, 0x74, 0x69, 0x74,
0x79, 0x2c, 0x20, 0x2a, 0x3b, 0x71, 0x3d, 0x30,
0x0d, 0x0a, 0x52, 0x65, 0x66, 0x65, 0x72, 0x65,
0x72, 0x3a, 0x20, 0x68, 0x74, 0x74, 0x70, 0x3a,
0x2f, 0x2f, 0x77, 0x77, 0x77, 0x2e, 0x62, 0x61,
0x79, 0x31, 0x32, 0x67, 0x61, 0x6d, 0x65, 0x73,
0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x64, 0x77, 0x61,
0x72, 0x76, 0x65, 0x73, 0x2f, 0x0d, 0x0a, 0x43,
0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x69, 0x6f,
0x6e, 0x3a, 0x20, 0x4b, 0x65, 0x65, 0x70, 0x2d,
0x41, 0x6c, 0x69, 0x76, 0x65, 0x0d, 0x0a, 0x0d,
0x0a };

int main(int argc, char** argv) {
	rocksock sock;
	rocksock* psock = &sock;
	int ret;
	char inbuf[1024];
	size_t bytesread;
	size_t chunksize = 512;

	if(argc < 2) {
		puts("need ip or dns name of a webserver as argv1");
		exit(1);
	}
#ifdef USE_SSL
	rocksock_init_ssl();
#endif

	rocksock_init(psock);
	rocksock_set_timeout(psock, 10000);
	//ret = rocksock_connect(psock, "b12.wimbli.com", 80, 0);
	rocksock_add_proxy(psock, RS_PT_SOCKS4, "127.0.0.1", 9050, NULL, NULL);
	//rocksock_add_proxy(psock, RS_PT_SOCKS5, "127.0.0.1", 31337, NULL, NULL);
	//rocksock_add_proxy(psock, RS_PT_SOCKS5, "98.216.80.12", 5639, NULL, NULL);


	ret = rocksock_connect(psock, argv[1],
#ifndef USE_SSL
		80, 0
#else
		443, 1
#endif
		);

	checkerr;
	ret = rocksock_send(psock, "GET / HTTP/1.0\r\n\r\n", 0, 0, &bytesread);
	//ret = rocksock_send(psock, peer0_0, 0, 0, &bytesread);
	checkerr;
	do {
		puts("loop");
		ret = rocksock_recv(psock, inbuf, sizeof(inbuf)-1, chunksize, &bytesread);
		checkerr;
		if(bytesread) {
			inbuf[bytesread] = '\0';
			puts(inbuf);
		}
		printf("bytesread %zu\n", bytesread);
	} while (bytesread == chunksize);
	do {

		ret = rocksock_recv(psock, inbuf, sizeof(inbuf)-1, chunksize, &bytesread);
		checkerr;
		if(bytesread) {
			inbuf[bytesread] = '\0';
			puts(inbuf);
		}
		printf("bytesread %zu\n", bytesread);
	} while (bytesread);
	rocksock_disconnect(psock);
	rocksock_clear(psock);
#ifdef USE_SSL
	rocksock_free_ssl();
#endif
	return 0;
}
