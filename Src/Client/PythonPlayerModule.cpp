//Find:
PyObject * playerGetItemLink(PyObject * poSelf, PyObject * poArgs)

//Replace for:
PyObject * playerGetItemLink(PyObject * poSelf, PyObject * poArgs)
{
	TItemPos Cell;

	switch (PyTuple_Size(poArgs))
	{
	case 1:
		if (!PyTuple_GetInteger(poArgs, 0, &Cell.cell))
			return Py_BuildException();
		break;
	case 2:
		if (!PyTuple_GetByte(poArgs, 0, &Cell.window_type))
			return Py_BuildException();
		if (!PyTuple_GetInteger(poArgs, 1, &Cell.cell))
			return Py_BuildException();
		break;
	default:
		return Py_BuildException();
	}
	const TItemData * pPlayerItem = CPythonPlayer::Instance().GetItemData(Cell);
	CItemData * pItemData = NULL;
	char buf[1024];

	if (pPlayerItem && CItemManager::Instance().GetItemDataPointer(pPlayerItem->vnum, &pItemData))
	{
		char itemlink[256];
		int len;
		bool isAttr = false;

		len = snprintf(itemlink, sizeof(itemlink), "item:%x:%x:%x:%x:%x:%x:%x:%x",
				pPlayerItem->vnum, pPlayerItem->flags,
				pPlayerItem->alSockets[0], pPlayerItem->alSockets[1], pPlayerItem->alSockets[2], pPlayerItem->alSockets[3], pPlayerItem->alSockets[4], pPlayerItem->alSockets[5]);

		for (int i = 0; i < ITEM_ATTRIBUTE_SLOT_MAX_NUM; ++i)
		{
			// if (pPlayerItem->aAttr[i].bType != 0) // @fixme009 (this line must be commented)
			{
				len += snprintf(itemlink + len, sizeof(itemlink) - len, ":%x:%d",
						pPlayerItem->aAttr[i].bType, pPlayerItem->aAttr[i].sValue);
				isAttr = true;
			}
		}

		if( GetDefaultCodePage() == CP_ARABIC ) {
			if (isAttr)
				//"item:ąřČŁ:ÇĂ·ˇ±×:ĽŇÄĎ0:ĽŇÄĎ1:ĽŇÄĎ2"
				snprintf(buf, sizeof(buf), " |h|r[%s]|cffffc700|H%s|h", pItemData->GetName(), itemlink);
			else
				snprintf(buf, sizeof(buf), " |h|r[%s]|cfff1e6c0|H%s|h", pItemData->GetName(), itemlink);
		} else {
			if (isAttr)
				//"item:ąřČŁ:ÇĂ·ˇ±×:ĽŇÄĎ0:ĽŇÄĎ1:ĽŇÄĎ2"
				snprintf(buf, sizeof(buf), "|cffffc700|H%s|h[%s]|h|r", itemlink, pItemData->GetName());
			else
				snprintf(buf, sizeof(buf), "|cfff1e6c0|H%s|h[%s]|h|r", itemlink, pItemData->GetName());
		}
	}
	else
		buf[0] = '\0';

	return Py_BuildValue("s", buf);
}