#ifdef ENABLE_EXTENDED_SOCKETS
	PyModule_AddIntConstant(poModule, "ENABLE_EXTENDED_SOCKETS", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_EXTENDED_SOCKETS", 0);
#endif