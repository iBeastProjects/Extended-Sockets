[...]

const int aiWeaponSocketQty[WEAPON_NUM_TYPES] =
{
#ifdef ENABLE_EXTENDED_SOCKETS
	6, // WEAPON_SWORD,
	6, // WEAPON_DAGGER,
	6, // WEAPON_BOW,
	6, // WEAPON_TWO_HANDED,
	6, // WEAPON_BELL,
	6, // WEAPON_FAN,
#else
	3, // WEAPON_SWORD,
	3, // WEAPON_DAGGER,
	3, // WEAPON_BOW,
	3, // WEAPON_TWO_HANDED,
	3, // WEAPON_BELL,
	3, // WEAPON_FAN,
#endif
};

[...]

const int aiArmorSocketQty[ARMOR_NUM_TYPES] =
{
#ifdef ENABLE_EXTENDED_SOCKETS
	6, // ARMOR_BODY,
#else
	3, // ARMOR_BODY,
#endif
	1, // ARMOR_HEAD,
	1, // ARMOR_SHIELD,
	0, // ARMOR_WRIST,
	0, // ARMOR_FOOTS,
	0  // ARMOR_ACCESSORY
};

[...]