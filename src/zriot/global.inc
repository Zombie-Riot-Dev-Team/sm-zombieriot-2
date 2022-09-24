/**
 * ====================
 *     Zombie Riot
 *   File: global.inc
 *   Author: Greyscale
 * ====================
 */

Handle hOnClientZombie = INVALID_HANDLE;
Handle hOnClientHuman = INVALID_HANDLE;
Handle hOnClientHUDUpdate = INVALID_HANDLE;

void CreateGlobals()
{
    CreateNative("ZRiot_IsClientZombie", Native_IsClientZombie);
    CreateNative("ZRiot_Zombie", Native_Zombie);
    CreateNative("ZRiot_Human", Native_Human);
    CreateNative("ZRiot_GetZombieTeam", Native_GetZombieTeam);
    CreateNative("ZRiot_GetHumanTeam", Native_GetHumanTeam);
    CreateNative("ZRiot_GetClientHumanClass", Native_GetClientHumanClass);
    CreateNative("ZRiot_GetClientZombieClasss", Native_GetClientZombieClass);
    CreateNative("ZRiot_GetDay", Native_GetDay);
    CreateNative("ZRiot_SetDay", Native_SetDay);
    CreateNative("ZRiot_GetTotalDay", Native_GetTotalDay);
    
    hOnClientZombie = CreateGlobalForward("ZRiot_OnClientZombie", ET_Ignore, Param_Cell);
    hOnClientHuman = CreateGlobalForward("ZRiot_OnClientHuman", ET_Ignore, Param_Cell);
    hOnClientHUDUpdate = CreateGlobalForward("ZRiot_OnClientHUDUpdate", ET_Ignore, Param_Cell, Param_String);
}

public int Native_IsClientZombie(Handle plugin, int argc)
{
    int client = GetNativeCell(1);
    if (!client)
        ThrowNativeError(SP_ERROR_INDEX, "Client index %d is not in the game", client);
    
    return bZombie[GetNativeCell(1)];
}

public int Native_GetZombieTeam(Handle plugin, int argc)
{
    return gZombieTeam;
}

public int Native_GetHumanTeam(Handle plugin, int argc)
{
    return gHumanTeam;
}

public int Native_Zombie(Handle plugin, int argc)
{
    int client = GetNativeCell(1);
    if (!client)
        ThrowNativeError(SP_ERROR_INDEX, "Client index %d is not in the game", client);
    
    ZRiot_Zombie(client);
    return 0;
}

public int Native_Human(Handle plugin, int argc)
{
    int client = GetNativeCell(1);
    if (!client)
        ThrowNativeError(SP_ERROR_INDEX, "Client index %d is not in the game", client);
    
    if (IsFakeClient(client))
        ThrowNativeError(SP_ERROR_INDEX, "Bots cannot be moved to the human team");
    
    ZRiot_Human(client);
    return 0;
}

public int Native_GetClientHumanClass(Handle plugin, int argc)
{
    int client = GetNativeCell(1);

    if (!client)
        ThrowNativeError(SP_ERROR_INDEX, "Client index %d is not in the game", client);
    
    if (IsFakeClient(client))
        ThrowNativeError(SP_ERROR_INDEX, "Bots cannot be moved to the human team");

    return g_iSelectedClass[client];
}

public int Native_GetClientZombieClass(Handle plugin, int argc)
{
    int client = GetNativeCell(1);

    if (!client)
        ThrowNativeError(SP_ERROR_INDEX, "Client index %d is not in the game", client);

    return gZombieID[client];
}

public int Native_SetDay(Handle plugin, int argc)
{
    int day = GetNativeCell(1);

    if(day < 1 || day > gDay)
    {
        ThrowNativeError(SP_ERROR_INDEX, "Invalid Number has been used", day);
        return -1;
    }

    gDay = day - 1;

    ZRiot_PrintToChat(0, "Skip to day", gDay + 1);
    
    if (tHUD == INVALID_HANDLE)
    {
        return -1;
    }
    
    CS_TerminateRound(3.0, CSRoundEnd_Draw, true);
    return 0;
}

public int Native_GetDay(Handle plugin, int argc)
{
    // day as index (start with 0 not 1)
    return gDay;
}

public int Native_GetTotalDay(Handle plugin, int argc)
{
    return dCount;
}