#pragma once

//constexpr int WEAPON_HANDS = 0;
//Sniper ammo weapons
constexpr int WEAPON_SENTINEL = 1;
constexpr int WEAPON_CHARGE_RIFLE = 83;
constexpr int WEAPON_LONGBOW = 85;
    //Shotgun ammo weapons
constexpr int WEAPON_MOZAMBIQUE = 96;
constexpr int WEAPON_EVA8 = 87;
constexpr int WEAPON_PEACEKEEPER = 103;
constexpr int WEAPON_MASTIFF = 95;
    //Light ammo weapons
constexpr int WEAPON_P2020 = 105;
constexpr int WEAPON_RE45 = 81;
constexpr int WEAPON_ALTERNATOR = 80;
constexpr int WEAPON_R99 = 104;
constexpr int WEAPON_R301 = 0;
constexpr int WEAPON_SPITFIRE = 106;
constexpr int WEAPON_G7 = 89;
    //Heavy ammo weapons
constexpr int WEAPON_CAR = 112;
constexpr int WEAPON_RAMPAGE = 21;
constexpr int WEAPON_3030 = 111;
constexpr int WEAPON_HEMLOCK = 90;
constexpr int WEAPON_FLATLINE = 88;
    //Energy ammo weapons
constexpr int WEAPON_NEMESIS = 113;
constexpr int WEAPON_VOLT = 110;
constexpr int WEAPON_TRIPLE_TAKE = 107;
constexpr int WEAPON_LSTAR = 93;
constexpr int WEAPON_DEVOTION = 84;
constexpr int WEAPON_HAVOC = 86;
    //Legendary ammo weapons
constexpr int WEAPON_WINGMAN = 109;
constexpr int WEAPON_PROWLER = 102;
constexpr int WEAPON_BOCEK = 2;
constexpr int WEAPON_KRABER = 92;
constexpr int WEAPON_THROWING_KNIFE = 163;
constexpr int BUSTER_SWORD_R2R5 = 3;
constexpr int WEAPON_THERMITE_GRENADE = 213;


// Define a reverse mapping from integer values to string names
std::unordered_map<int, std::string> intToStringMap = {
//    {WEAPON_HANDS,"WEAPON_HANDS"},
    {WEAPON_SENTINEL,"WEAPON_SENTINEL"},
    {WEAPON_CHARGE_RIFLE,"WEAPON_CHARGE_RIFLE"},
    {WEAPON_LONGBOW ,"WEAPON_LONGBOW"},
    {WEAPON_MOZAMBIQUE,"WEAPON_MOZAMBIQUE"},
    {WEAPON_EVA8,"WEAPON_EVA8"},
    {WEAPON_PEACEKEEPER,"WEAPON_PEACEKEEPER"},
    {WEAPON_MASTIFF,"WEAPON_MASTIFF"},
    {WEAPON_P2020,"WEAPON_P2020"},
    {WEAPON_RE45,"WEAPON_RE45"},
    {WEAPON_ALTERNATOR,"WEAPON_ALTERNATOR"},
    {WEAPON_R99 ,"WEAPON_R99"},
    {WEAPON_R301,"WEAPON_R301"},
    {WEAPON_SPITFIRE,"WEAPON_SPITFIRE"},
    {WEAPON_G7,"WEAPON_G7"},
    {WEAPON_CAR,"WEAPON_CAR"},
    {WEAPON_RAMPAGE,"WEAPON_RAMPAGE"},
    {WEAPON_3030,"WEAPON_3030"},
    {WEAPON_HEMLOCK,"WEAPON_HEMLOCK"},
    {WEAPON_FLATLINE,"WEAPON_FLATLINE"},
    {WEAPON_NEMESIS,"WEAPON_NEMESIS"},
    {WEAPON_VOLT,"WEAPON_VOLT"},
    {WEAPON_TRIPLE_TAKE,"WEAPON_TRIPLE_TAKE"},
    {WEAPON_LSTAR,"WEAPON_LSTAR"},
    {WEAPON_DEVOTION ,"WEAPON_DEVOTION"},
    {WEAPON_HAVOC ,"WEAPON_HAVOC"},
    {WEAPON_WINGMAN ,"WEAPON_WINGMAN"},
    {WEAPON_PROWLER ,"WEAPON_PROWLER"},
    {WEAPON_BOCEK ,"WEAPON_BOCEK"},
    {WEAPON_KRABER ,"WEAPON_KRABER"},
    {WEAPON_THROWING_KNIFE,"WEAPON_THROWING_KNIFE"},
    {BUSTER_SWORD_R2R5,"BUSTER_SWORD_R2R5"},
    {WEAPON_THERMITE_GRENADE,"WEAPON_THERMITE_GRENADE"}
};

std::string WeaponName(int weaponId) {
    auto it = intToStringMap.find(weaponId);
    if (it != intToStringMap.end())
        return it->second;
    return "UNKNOWN! NEED WEAPONID UPDATE!?";
}