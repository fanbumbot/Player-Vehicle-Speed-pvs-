//------------------------------------------------------------------------------
//  �������� !!! ���� ������������ � ���� - �� ������ #include <playvehspeed>
//  ����� ��������� ����� ��������� main() � public OnGameModeInit()
//
//	SetPlayerVehicleSpeed(playerid, dataset); - ��������� �������� ������,
//		dataset = 0 - ��������� ���������
//		dataset = 1-40 - ��������� ���������
//	����������:
//		1 - ��������� ������� ���������
//		-1 - ����� �� ��������� � �������, ��� dataset �� ��������� ����������
//
//	GetPlayerVehicleSpeed(playerid); - ���������� ��������� �������� ������
//		0 - ��������� ���������
//		1-40 - �� ���������
//		-1 - ����� �� ��������� � �������
//------------------------------------------------------------------------------

new pvs_timer;
new pvs_playset[MAX_PLAYERS];
new pvs_playstatg[MAX_PLAYERS];
new pvs_playstatt[MAX_PLAYERS];
new Float:pvs_playspeed[MAX_PLAYERS];
new Float:pvs_playdlt;
new pvs_carid;
new Float:pvs_carspeed[3];
new Float:pvs_cardlt;
new Float:pvs_hms[212] = {176.0, 164.0, 208.0, 123.0, 149.0, 183.0, 123.0, 166.0, 112.0, 177.0,//400-409//������ ������������ �������������� ��������
145.0, 247.0, 188.0, 123.0, 118.0, 215.0, 172.0, 150.0, 129.0, 167.0,//410-419
162.0, 172.0, 157.0, 111.0, 151.0, 200.0, 194.0, 185.0, 175.0, 225.0,//420-429
208.0, 146.0, 106.0, 124.0, 187.0, 64.0, 167.0, 176.0, 160.0, 188.0,//430-439
152.0, 85.0, 156.0, 141.0, 124.0, 183.0, 297.0, 160.0, 125.0, 202.0,//440-449
59.0, 216.0, 205.0, 65.0, 149.0, 176.0, 119.0, 107.0, 176.0, 152.0,//450-459
233.0, 180.0, 125.0, 161.0, 68.0, 63.0, 164.0, 157.0, 161.0, 151.0,//460-469
175.0, 123.0, 141.0, 121.0, 167.0, 193.0, 300.0, 208.0, 132.0, 156.0,//470-479
206.0, 82.0, 175.0, 137.0, 72.0, 112.0, 73.0, 201.0, 200.0, 156.0,//480-489
175.0, 167.0, 157.0, 202.0, 240.0, 197.0, 182.0, 212.0, 121.0, 138.0,//490-499
157.0, 41.0, 240.0, 240.0, 193.0, 156.0, 200.0, 185.0, 121.0, 89.0,//500-509
114.0, 200.0, 200.0, 250.0, 135.0, 159.0, 176.0, 176.0, 184.0, 300.0,//510-519
300.0, 180.0, 197.0, 170.0, 146.0, 179.0, 176.0, 167.0, 197.0, 167.0,//520-529
68.0, 79.0, 123.0, 187.0, 188.0, 177.0, 193.0, 202.0, 202.0, 115.0,//530-539
167.0, 227.0, 184.0, 169.0, 166.0, 164.0, 167.0, 160.0, 150.0, 172.0,//540-549
162.0, 176.0, 136.0, 300.0, 161.0, 177.0, 124.0, 124.0, 174.0, 199.0,//550-559
189.0, 172.0, 199.0, 150.0, 99.0, 184.0, 179.0, 193.0, 164.0, 1.0,//560-569
1.0, 105.0, 68.0, 124.0, 68.0, 176.0, 176.0, 300.0, 146.0, 176.0,//570-579
171.0, 170.0, 152.0, 96.0, 41.0, 171.0, 161.0, 184.0, 121.0, 182.0,//580-589
800.0, 64.0, 300.0, 200.0, 69.0, 132.0, 196.0, 196.0, 196.0, 177.0,//590-599
169.0, 124.0, 189.0, 191.0, 164.0, 169.0, 111.0, 111.0, 4.0, 121.0,//600-609
21.0, 111.0};//610-611

#if defined main
	public OnGameModeInit()
	{
	    for(new i = 0; i < MAX_PLAYERS; i++)
		{
			pvs_playset[i] = 0;
			pvs_playspeed[i] = 1.0;
		}
		pvs_timer = SetTimer("pvs_timtim", 151, true);
		#if defined pvs_OnGameModeInit
			return pvs_OnGameModeInit();
		#else
			return 1;
		#endif
	}

	#if defined pvs_OnGameModeInit
		forward pvs_OnGameModeInit();
	#endif
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit pvs_OnGameModeInit

	public OnGameModeExit()
	{
		KillTimer(pvs_timer);
		#if defined pvs_OnGameModeExit
			return pvs_OnGameModeExit();
		#else
			return 1;
		#endif
	}

	#if defined pvs_OnGameModeExit
		forward pvs_OnGameModeExit();
	#endif
	#if defined _ALS_OnGameModeExit
		#undef OnGameModeExit
	#else
		#define _ALS_OnGameModeExit
	#endif
	#define OnGameModeExit pvs_OnGameModeExit
#else
	public OnFilterScriptInit()
	{
	    for(new i = 0; i < MAX_PLAYERS; i++)
		{
			pvs_playset[i] = 0;
			pvs_playspeed[i] = 1.0;
		}
		pvs_timer = SetTimer("pvs_timtim", 151, true);
		#if defined pvs_OnFilterScriptInit
			return pvs_OnFilterScriptInit();
		#else
			return 1;
		#endif
	}

	#if defined pvs_OnFilterScriptInit
		forward pvs_OnFilterScriptInit();
	#endif
	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit pvs_OnFilterScriptInit

	public OnFilterScriptExit()
	{
		KillTimer(pvs_timer);
		#if defined pvs_OnFilterScriptExit
			return pvs_OnFilterScriptExit();
		#else
			return 1;
		#endif
	}

	#if defined pvs_OnFilterScriptExit
		forward pvs_OnFilterScriptExit();
	#endif
	#if defined _ALS_OnFilterScriptExit
		#undef OnFilterScriptExit
	#else
		#define _ALS_OnFilterScriptExit
	#endif
	#define OnFilterScriptExit pvs_OnFilterScriptExit
#endif

public OnPlayerConnect(playerid)
{
	pvs_playset[playerid] = 0;
	pvs_playspeed[playerid] = 1.0;
	#if defined pvs_OnPlayerConnect
		return pvs_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

#if defined pvs_OnPlayerConnect
	forward pvs_OnPlayerConnect(playerid);
#endif
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect pvs_OnPlayerConnect

public OnPlayerDisconnect(playerid, reason)
{
	pvs_playset[playerid] = 0;
	pvs_playspeed[playerid] = 1.0;
	#if defined pvs_OnPlayerDisconnect
		return pvs_OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}

#if defined pvs_OnPlayerDisconnect
	forward pvs_OnPlayerDisconnect(playerid, reason);
#endif
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect pvs_OnPlayerDisconnect

stock SetPlayerVehicleSpeed(pvs_playerid, pvs_dataset)
{
	if(IsPlayerConnected(pvs_playerid))
	{
		if(pvs_dataset < 0 || pvs_dataset > 40)
		{
			return -1;
		}
		pvs_playset[pvs_playerid] = pvs_dataset;
		switch(pvs_dataset)
		{
		    case 0: { pvs_playspeed[pvs_playerid] = 1.0; }
		    case 1: { pvs_playspeed[pvs_playerid] = 1.05; }
		    case 2: { pvs_playspeed[pvs_playerid] = 1.1; }
		    case 3: { pvs_playspeed[pvs_playerid] = 1.15; }
		    case 4: { pvs_playspeed[pvs_playerid] = 1.2; }
		    case 5: { pvs_playspeed[pvs_playerid] = 1.25; }
		    case 6: { pvs_playspeed[pvs_playerid] = 1.3; }
		    case 7: { pvs_playspeed[pvs_playerid] = 1.35; }
		    case 8: { pvs_playspeed[pvs_playerid] = 1.4; }
		    case 9: { pvs_playspeed[pvs_playerid] = 1.45; }
		    case 10: { pvs_playspeed[pvs_playerid] = 1.5; }
		    case 11: { pvs_playspeed[pvs_playerid] = 1.55; }
		    case 12: { pvs_playspeed[pvs_playerid] = 1.6; }
		    case 13: { pvs_playspeed[pvs_playerid] = 1.65; }
		    case 14: { pvs_playspeed[pvs_playerid] = 1.7; }
		    case 15: { pvs_playspeed[pvs_playerid] = 1.75; }
		    case 16: { pvs_playspeed[pvs_playerid] = 1.8; }
		    case 17: { pvs_playspeed[pvs_playerid] = 1.85; }
		    case 18: { pvs_playspeed[pvs_playerid] = 1.9; }
		    case 19: { pvs_playspeed[pvs_playerid] = 1.95; }
		    case 20: { pvs_playspeed[pvs_playerid] = 2.0; }
		    case 21: { pvs_playspeed[pvs_playerid] = 2.05; }
		    case 22: { pvs_playspeed[pvs_playerid] = 2.1; }
		    case 23: { pvs_playspeed[pvs_playerid] = 2.15; }
		    case 24: { pvs_playspeed[pvs_playerid] = 2.2; }
		    case 25: { pvs_playspeed[pvs_playerid] = 2.25; }
		    case 26: { pvs_playspeed[pvs_playerid] = 2.3; }
		    case 27: { pvs_playspeed[pvs_playerid] = 2.35; }
		    case 28: { pvs_playspeed[pvs_playerid] = 2.4; }
		    case 29: { pvs_playspeed[pvs_playerid] = 2.45; }
		    case 30: { pvs_playspeed[pvs_playerid] = 2.5; }
		    case 31: { pvs_playspeed[pvs_playerid] = 2.55; }
		    case 32: { pvs_playspeed[pvs_playerid] = 2.6; }
		    case 33: { pvs_playspeed[pvs_playerid] = 2.65; }
		    case 34: { pvs_playspeed[pvs_playerid] = 2.7; }
		    case 35: { pvs_playspeed[pvs_playerid] = 2.75; }
		    case 36: { pvs_playspeed[pvs_playerid] = 2.8; }
		    case 37: { pvs_playspeed[pvs_playerid] = 2.85; }
		    case 38: { pvs_playspeed[pvs_playerid] = 2.9; }
		    case 39: { pvs_playspeed[pvs_playerid] = 2.95; }
		    case 40: { pvs_playspeed[pvs_playerid] = 3.0; }
		}
		return 1;
	}
	else
	{
		return -1;
	}
}

stock GetPlayerVehicleSpeed(pvs_playerid)
{
	if(IsPlayerConnected(pvs_playerid))
	{
		return pvs_playset[pvs_playerid];
	}
	else
	{
		return -1;
	}
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(GetPlayerState(playerid) == 2)
	{
		if(oldkeys & 8)//���������� ����
		{
			pvs_playstatg[playerid] = 0;
		}
		if(newkeys & 8)//��������� ����
		{
			pvs_playstatg[playerid] = 1;
		}
		if(oldkeys & 32 || oldkeys & 128)//���������� �������
		{
			pvs_playstatt[playerid] = 0;
		}
		if(newkeys & 32 || newkeys & 128)//��������� �������
		{
			pvs_playstatt[playerid] = 1;
		}
	}
	#if defined pvs_OnPlayerKeyStateChange
		return pvs_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}

#if defined pvs_OnPlayerKeyStateChange
	forward pvs_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif
#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange pvs_OnPlayerKeyStateChange

forward pvs_timtim();
public pvs_timtim()
{
    for(new i = 0; i < MAX_PLAYERS; i++)
	{
 		if(IsPlayerConnected(i))
 		{
			if(pvs_playset[i] > 0)//���� ������������ ���������, ��:
			{
    			if(GetPlayerState(i) == 2)
    			{
					pvs_carid = GetPlayerVehicleID(i);
					GetVehicleVelocity(pvs_carid, pvs_carspeed[0], pvs_carspeed[1], pvs_carspeed[2]);
					pvs_cardlt = floatsqroot(pvs_carspeed[0] * pvs_carspeed[0] + pvs_carspeed[1] * pvs_carspeed[1] +
					pvs_carspeed[2] * pvs_carspeed[2]) * 200.0;//�������� ��������
					pvs_playdlt = pvs_hms[GetVehicleModel(pvs_carid) - 400] * pvs_playspeed[i];//������������ ����������� �������� ��� ������
					if(pvs_cardlt > pvs_playdlt)//���� ��������� ��������, ��:
					{
						SetVehicleVelocity(pvs_carid, pvs_carspeed[0] * 0.95, pvs_carspeed[1] * 0.95, pvs_carspeed[2] * 0.95);//��������� �� ����������� �������
					}
					else//���� �������� �� ���������, ��:
					{
						if(pvs_playstatg[i] == 1)//���� ����� ���, ��:
						{
							SetVehicleVelocity(pvs_carid, pvs_carspeed[0] * 1.05, pvs_carspeed[1] * 1.05, pvs_carspeed[2] * 1.05);//��������� �� ����������� ��������
						}
						if(pvs_playstatt[i] == 1)//���� ����� ������, ��:
						{
							SetVehicleVelocity(pvs_carid, pvs_carspeed[0] * 0.90, pvs_carspeed[1] * 0.90, pvs_carspeed[2] * 0.90);//��������� �� ����������� �������
						}
					}
				}
			}
		}
	}
	return 1;
}

