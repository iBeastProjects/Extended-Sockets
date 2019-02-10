[...]
void CItemCache::OnFlush()
{
	if (m_data.vnum == 0) // vnum이 0이면 삭제하라고 표시된 것이다.
	[...]
	else
	{
		[...]

#ifndef ENABLE_EXTENDED_SOCKETS
		if (isSocket)
		{
			iLen += snprintf(szColumns + iLen, sizeof(szColumns) - iLen, ", socket0, socket1, socket2");
			iValueLen += snprintf(szValues + iValueLen, sizeof(szValues) - iValueLen,
					", %lu, %lu, %lu", p->alSockets[0], p->alSockets[1], p->alSockets[2]);
			iUpdateLen += snprintf(szUpdate + iUpdateLen, sizeof(szUpdate) - iUpdateLen,
					", socket0=%lu, socket1=%lu, socket2=%lu", p->alSockets[0], p->alSockets[1], p->alSockets[2]);
		}
#else
		if (isSocket)
		{
			iLen += snprintf(szColumns + iLen, sizeof(szColumns) - iLen, ", socket0, socket1, socket2, socket3, socket4, socket5");
			iValueLen += snprintf(szValues + iValueLen, sizeof(szValues) - iValueLen,
					", %lu, %lu, %lu, %lu, %lu, %lu", p->alSockets[0], p->alSockets[1], p->alSockets[2], p->alSockets[3], p->alSockets[4], p->alSockets[5]);
			iUpdateLen += snprintf(szUpdate + iUpdateLen, sizeof(szUpdate) - iUpdateLen,
					", socket0=%lu, socket1=%lu, socket2=%lu, socket3=%lu, socket4=%lu, socket5=%lu", p->alSockets[0], p->alSockets[1], p->alSockets[2], p->alSockets[3], p->alSockets[4], p->alSockets[5]);
		}
#endif
		[...]
	}

	m_bNeedQuery = false;
}
[...]
