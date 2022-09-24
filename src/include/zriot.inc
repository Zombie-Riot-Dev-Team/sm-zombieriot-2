/**
 * ====================
 *    Zombie Riot
 *   File: zriot.inc
 *   Author: Greyscale
 * ==================== 
 */
 
 #if defined _zombieriot_included_
  #endinput
#endif
#define _zombieriot_included_

/**
 * Used to check if a player is a zombie.
 * @param client   Client index.
 * @return   True if the player is a zombie, and false if human.
 */   
native bool ZRiot_IsClientZombie(int client);

/**
 * Retrieves the team index of the zombies
 * @note   Remember these are based off cvars, 0 will be returned if called before the cvar is set
 */
native void ZRiot_GetZombieTeam();

/**
 * Retrieves the team index of the humans
 * @note   Remember these are based off cvars, 0 will be returned if called before the cvar is set
 */
native void ZRiot_GetHumanTeam();

/**
 * Turns a human into a zombie
 * @param client   Client index.
 */
native void ZRiot_Zombie(int client);

/**
 * Called when a player turns into a zombie.  This is not called at round end.
 * @param client   Client index.
 */
forward void ZRiot_OnClientZombie(int client);

/**
 * Turns a zombie into a human (will not work for bots)
 * @param client   Client index.
 */
native void ZRiot_Human(int client);

/**
 * Called when a player turns into a human.  This is not called at round end.
 * @param client   Client index.
 */
forward void ZRiot_OnClientHuman(int client);

/**
 * Called when the HUD is being updated on a client (not called for bots)
 * @param client   Client index.
 * @param hinttext   The text string being sent to the usermsg "HintText"
 * @note   If hinttext is modified the new value will be sent to the client
 */
forward void ZRiot_OnClientHUDUpdate(int client, char[] hinttext);

/**
 * Used to get player human class. (Cannot use for BOT)
 * @param client   Client index.
 * @return   Client Human Class index.
 */
native int ZRiot_GetClientHumanClass(int client);

/**
 * Used to get player zombie class. (Including with BOT)
 * @param client   Client index.
 * @return   Client Zombie Class index.
 */
native int ZRiot_GetClientZombieClasss(int client);

/**
 * Get Current Zombie Riot "Day Wave"
 * @return   Return Day Index.
 */
native int ZRiot_GetDay();

/**
 * Set the Day in ZRiot
 * @param day   Day index.
 * @return   0 if success, -1 failed otherwise.
 */
native void ZRiot_SetDay(int day);

/**
 * Get All Zombie Riot "Day Wave" count
 * @return   Return amount of day index.
 */
native int ZRiot_GetTotalDay();

public SharedPlugin __pl_zombieriot = 
{
    name = "zombieriot",
    file = "zombieriot.smx",
#if defined REQUIRE_PLUGIN
    required = 1,
#else
    required = 0,
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_zombieriot_SetNTVOptional()
{
    MarkNativeAsOptional("ZRiot_IsClientZombie");
    MarkNativeAsOptional("ZRiot_GetClientHumanClass");
    MarkNativeAsOptional("ZRiot_GetClientZombieClasss");
    MarkNativeAsOptional("ZRiot_Zombie");
    MarkNativeAsOptional("ZRiot_Human");
}
#endif
