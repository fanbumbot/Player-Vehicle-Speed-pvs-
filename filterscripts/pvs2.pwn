#include <a_samp>
#include <playvehspeed>

public OnFilterScriptInit()
{
	print(" ");
	print("----------------------------------");
	print("       playvehspeed script         ");
	print("----------------------------------\n");
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}

public OnPlayerConnect(playerid)
{
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	return 1;
}

strtok(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}

	new offset = index;
	new result[30];
	while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	new idx;
	idx = 0;
	new string[256];
	new cmd[256];
	new tmp[256];
	cmd = strtok(cmdtext, idx);
	if(strcmp(cmd, "/pvs", true) == 0)
	{
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp))
		{
			SendClientMessage(playerid, 0xFFFF00FF, " Используйте: /pvs [скорость 0-40]");
			return 1;
		}
		new para1;
		para1 = strval(tmp);
		if(para1 < 0 || para1 > 40)
		{
			SendClientMessage(playerid, 0xFF0000FF, " Используйте: /pvs [скорость 0-40] !");
			return 1;
		}
		SetPlayerVehicleSpeed(playerid, para1);
		format(string, sizeof(string), "скорость %d", para1);
		SendClientMessage(playerid, 0x00FF00FF, string);
		return 1;
	}
	return 0;
}

