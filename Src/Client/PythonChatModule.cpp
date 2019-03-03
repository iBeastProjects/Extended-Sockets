//Find:
PyObject * chatGetLinkFromHyperlink(PyObject * poSelf, PyObject * poArgs)

//Replace for:
PyObject * chatGetLinkFromHyperlink(PyObject * poSelf, PyObject * poArgs)
{
	char * szHyperlink;

	if (!PyTuple_GetString(poArgs, 0, &szHyperlink))
		return Py_BuildException();

	std::string stHyperlink(szHyperlink);
	std::vector<std::string> results;

	split_string(stHyperlink, ":", results, false);

	// item:vnum:flag:socket0:socket1:socket2
	if (0 == results[0].compare("item"))
	{
		if (results.size() < 9)
			return Py_BuildValue("s", "");

		CItemData * pItemData = NULL;

		if (CItemManager::Instance().GetItemDataPointer(htoi(results[1].c_str()), &pItemData))
		{
			char buf[1024] = { 0 };
			char itemlink[256];
			int len;
			bool isAttr = false;

			len = snprintf(itemlink, sizeof(itemlink), "item:%x:%x:%x:%x:%x:%x:%x:%x",
					htoi(results[1].c_str()),
					htoi(results[2].c_str()),
					htoi(results[3].c_str()),
					htoi(results[4].c_str()),
					htoi(results[5].c_str()),
					htoi(results[6].c_str()),
					htoi(results[7].c_str()),
					htoi(results[8].c_str()));

			if (results.size() >= 8)
			{
				for (int i = 6; i < results.size(); i += 2)
				{
					len += snprintf(itemlink + len, sizeof(itemlink) - len, ":%x:%d",
							htoi(results[i].c_str()),
							atoi(results[i+1].c_str()));
					isAttr = true;
				}
			}

			if (isAttr)
				//"item:ąřČŁ:ÇĂ·ˇ±×:ĽŇÄĎ0:ĽŇÄĎ1:ĽŇÄĎ2"
				snprintf(buf, sizeof(buf), "|cffffc700|H%s|h[%s]|h|r", itemlink, pItemData->GetName());
			else
				snprintf(buf, sizeof(buf), "|cfff1e6c0|H%s|h[%s]|h|r", itemlink, pItemData->GetName());

			return Py_BuildValue("s", buf);
		}
	}

	return Py_BuildValue("s", "");
}