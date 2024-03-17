#pragma once
struct Sense {
    ConfigLoader* cl;
    XDisplay* display;
    Level* level;
    LocalPlayer* localPlayer;
    std::vector<Player*>* players;

    Sense(ConfigLoader* cl, XDisplay* display, Level* level, LocalPlayer* localPlayer, std::vector<Player*>* players) {
        this->cl = cl;
        this->display = display;
        this->level = level;
        this->localPlayer = localPlayer;
        this->players = players;
    }

    void update(int counter)
    {
        int senseMaxRange = 250;
        int senseMaxRangeOverWall = 250;
        int gameMode = 0;
        if (!level->playable)
            return;
        
        for (int i = 0; i < players->size(); i++) {
            Player *player = players->at(i);
            if (!player->isValid())
                continue;
            
            if (player->friendly) {
                player->setGlowEnable(1);
                player->setGlowThroughWall(1);
                int healthShield = player->currentHealth + player->currentShields;
                player->setCustomGlow(cl, healthShield, true, true);
                continue;
            }
            double distance = math::calculateDistanceInMeters(
                localPlayer->localOrigin.x,
                localPlayer->localOrigin.y, 
                localPlayer->localOrigin.z,
                player->localOrigin.x,
                player->localOrigin.y,
                player->localOrigin.z);
            if (player->visible && !player->knocked && distance < senseMaxRange) {
                player->setGlowEnable(1);
                player->setGlowThroughWall(1);
                int healthShield = player->currentHealth + player->currentShields;
                player->setCustomGlow(cl, healthShield, true, false);
            } 
            if (!player->visible && !player->knocked && distance < senseMaxRange){
                player->setGlowEnable(1);
                player->setGlowThroughWall(1);  
                int healthShield = player->currentHealth + player->currentShields; 
                player->setCustomGlow(cl, healthShield, true, false);
            } 
            else if (distance < senseMaxRangeOverWall) {
                player->setGlowEnable(1);
                player->setGlowThroughWall(1);
                player->setCustomGlow(cl, 0, false, false);
            } else if (player->getGlowEnable() == 1 && player->getGlowThroughWall() == 1) {
                player->setGlowEnable(0);
                player->setGlowThroughWall(0);
            }
        }
    }
};
