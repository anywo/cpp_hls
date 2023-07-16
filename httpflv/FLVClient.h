#pragma once
#include <string>
#include <queue>
// #include <WinSock2.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

class FLVClient
{
public:
	FLVClient();
	~FLVClient();

	void HasNewFLVTag(const std::basic_string<std::uint8_t>& data);
	std::basic_string<std::uint8_t> GetTagData();

	bool newClient;
private:
	std::queue< std::basic_string<std::uint8_t>> tagQueue;
    pthread_mutex_t m_queueLock;
    pthread_cond_t m_queueCondition;
};