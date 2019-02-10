[...]

bool CreateItemTableFromRes(MYSQL_RES * res, std::vector<TPlayerItem> * pVec, DWORD dwPID)
{
	[...]

	for (int i = 0; i < rows; ++i)
	{
		MYSQL_ROW row = mysql_fetch_row(res);
		TPlayerItem & item = pVec->at(i);

		int cur = 0;

		[...]
		str_to_number(item.alSockets[0], row[cur++]);
		str_to_number(item.alSockets[1], row[cur++]);
		str_to_number(item.alSockets[2], row[cur++]);
#ifdef ENABLE_EXTENDED_SOCKETS
		str_to_number(item.alSockets[3], row[cur++]);
		str_to_number(item.alSockets[4], row[cur++]);
		str_to_number(item.alSockets[5], row[cur++]);		
#endif

		[...]
	}

	return true;
}

[...]

/*
 * PLAYER LOAD
 */
void CClientManager::QUERY_PLAYER_LOAD(CPeer * peer, DWORD dwHandle, TPlayerLoadPacket * packet)
{
	[...]
	
	if ((c = GetPlayerCache(packet->player_id)))
	{
		[...]
		
		if (pSet)
		{
			[...]
		}
		else
		{
#ifndef ENABLE_EXTENDED_SOCKETS
			snprintf(szQuery, sizeof(szQuery),
					"SELECT id,window+0,pos,count,vnum,socket0,socket1,socket2,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 "
					"FROM item%s WHERE owner_id=%d AND (window in ('INVENTORY','EQUIPMENT','DRAGON_SOUL_INVENTORY','BELT_INVENTORY'))",
					GetTablePostfix(), pTab->id);
#else
			snprintf(szQuery, sizeof(szQuery),
					"SELECT id,window+0,pos,count,vnum,socket0,socket1,socket2,socket3,socket4,socket5,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 "
					"FROM item%s WHERE owner_id=%d AND (window in ('INVENTORY','EQUIPMENT','DRAGON_SOUL_INVENTORY','BELT_INVENTORY'))",
					GetTablePostfix(), pTab->id);	
#endif
			
			[...]
		}
	}
	else
	{
		[...]

#ifndef ENABLE_EXTENDED_SOCKETS
		snprintf(queryStr, sizeof(queryStr),
				"SELECT id,window+0,pos,count,vnum,socket0,socket1,socket2,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 "
				"FROM item%s WHERE owner_id=%d AND (window in ('INVENTORY','EQUIPMENT','DRAGON_SOUL_INVENTORY','BELT_INVENTORY'))",
				GetTablePostfix(), packet->player_id);
		CDBManager::instance().ReturnQuery(queryStr, QID_ITEM, peer->GetHandle(), new ClientHandleInfo(dwHandle, packet->player_id));
#else
		snprintf(queryStr, sizeof(queryStr),
				"SELECT id,window+0,pos,count,vnum,socket0,socket1,socket2,socket3,socket4,socket5,attrtype0,attrvalue0,attrtype1,attrvalue1,attrtype2,attrvalue2,attrtype3,attrvalue3,attrtype4,attrvalue4,attrtype5,attrvalue5,attrtype6,attrvalue6 "
				"FROM item%s WHERE owner_id=%d AND (window in ('INVENTORY','EQUIPMENT','DRAGON_SOUL_INVENTORY','BELT_INVENTORY'))",
				GetTablePostfix(), packet->player_id);
		CDBManager::instance().ReturnQuery(queryStr, QID_ITEM, peer->GetHandle(), new ClientHandleInfo(dwHandle, packet->player_id));	
#endif

		[...]
	}


}

[...]