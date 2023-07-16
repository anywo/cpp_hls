#include "FLVClient.h"

FLVClient::FLVClient() :newClient(true)
{
	pthread_mutex_init(&m_queueLock, NULL);
	// InitializeConditionVariable(&m_queueCondition);
}

FLVClient::~FLVClient()
{
	pthread_mutex_destroy(&m_queueLock);
}

void  FLVClient::HasNewFLVTag(const std::basic_string<std::uint8_t>& data)
{
	pthread_mutex_lock(&m_queueLock);
	tagQueue.push(data);
	pthread_mutex_unlock(&m_queueLock);

	pthread_cond_broadcast(&m_queueCondition);
}

std::basic_string<std::uint8_t> FLVClient::GetTagData()
{
	std::basic_string<std::uint8_t> s;
	pthread_mutex_lock(&m_queueLock);
	if (tagQueue.empty())
	{
		struct timespec timeout;
		clock_gettime(CLOCK_REALTIME, &timeout);
		timeout.tv_sec += 2; // 设置等待超时时间为2秒
		pthread_cond_timedwait(&m_queueCondition, &m_queueLock, &timeout);
	}

	if (!tagQueue.empty())
	{
		s = tagQueue.front();
		tagQueue.pop();
	}
	pthread_mutex_unlock(&m_queueLock);
	return s;
}