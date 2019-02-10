[...]

enum EItemMisc
{
	[...]
	ITEM_APPLY_MAX_NUM			= 3,
#ifdef ENABLE_EXTENDED_SOCKETS
	ITEM_SOCKET_MAX_NUM			= 6,
#else
	ITEM_SOCKET_MAX_NUM			= 3,
#endif
	[...]
};

[...]