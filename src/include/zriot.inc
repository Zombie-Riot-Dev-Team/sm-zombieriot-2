/**
 * ====================
 *    Zombie Riot
 *   File: zriot.inc
 *   Author: Greyscale, Oylsister, Oz_Lin
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

/**
 * Get Total Zombie that need to be eliminated in that day.
 * @param day   Day index.
 * @return   Return total zombie count, -1 if invalid day.
 */
native int ZRiot_GetZombieCount(int day);

/**
 * Get Number of zombie that has been already killed.
 * @return   Return amount of zombie that get killed.
 */
native int ZRiot_GetZombieKilledCount();

/**
 * Set Total Zombie that need to be eliminated in that day.
 * @param day   Day index.
 * @param zombiecount   number zombie count that you desire to change.
 * @return   0 if success, -1 failed otherwise.
 */
native int ZRiot_SetZombieCount(int day, int zombiecount);

/**
 * Get Overall Zombie health that needs to be boosted in that day.
 * @param day   Day index.
 * @return   Return overall zombie healthboost, -1 if invalid.
 */
native int ZRiot_GetZombieHealthBoost(int day);

/**
 * Set Overall Zombie health that needs to be boosted in that day.
 * @param day   Day index.
 * @param healthboost   number of zombie health boost that you desire to change.
 * @return   0 if success, -1 failed otherwise.
 */
native int ZRiot_SetZombieHealthBoost(int day, int healthboost);

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

    MarkNativeAsOptional("ZRiot_GetDay");
    MarkNativeAsOptional("ZRiot_SetDay");
    MarkNativeAsOptional("ZRiot_GetTotalDay");

    MarkNativeAsOptional("ZRiot_GetZombieCount");
    MarkNativeAsOptional("ZRiot_GetZombieKilledCount");
    MarkNativeAsOptional("ZRiot_SetZombieCount");
    MarkNativeAsOptional("ZRiot_GetZombieHealthBoost");
    MarkNativeAsOptional("ZRiot_SetZombieHealthBoost");
}
#endif
