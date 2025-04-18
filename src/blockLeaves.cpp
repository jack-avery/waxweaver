#include "blockLeaves.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void BLOCKLEAVES::_bind_methods() {
}

BLOCKLEAVES::BLOCKLEAVES() {

    setTexture("res://items/blocks/foliage/trees/forestTree/leaves.png");

    breakTime = 0.5;

    breakParticleID = 12;

    hasCollision = false;

    lightMultiplier = 0.8;

    rotateTextureToGravity = true;

    connectTexturesToMe = true;
    connectedTexture = true;

    itemToDrop = 7;
    isTransparent = true;

    soundMaterial = 5;

}


BLOCKLEAVES::~BLOCKLEAVES() {
}

Dictionary BLOCKLEAVES::onTick(int x, int y, PLANETDATA *planet, int dir){
    Dictionary changes = {};

    if(std::rand()%10>0){
        return changes;
    }

    for(int scanX = -2; scanX < 3; scanX++){
        for(int scanY = -2; scanY < 3; scanY++){
            Vector2i newPos =  Vector2i(x,y) - Vector2i( Vector2(scanX,scanY).rotated(acos(0.0)*dir) );
            int tile = planet->getTileData(newPos.x,newPos.y);
            if( tile == 8 || tile == 12 ){

                if(std::rand()%100==0){
                    changes[Vector2i(x,y)] = "leaf";
                }

                if(std::rand()%1000==0){
                    changes[Vector2i(x,y)] = "leafrustle";
                }

                 return changes;
            }

        }
    }

    changes[Vector2i(x,y)] = -1;
    return changes;

}