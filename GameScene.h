

#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();


    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

    void GoToPauseScene(Ref* pSender);
    void GoToGameOverScene(Ref* pSender);
      
    cocos2d::Sprite* backgrounsprite;

    cocos2d::Sprite * mySprite;
 
    void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

};

#endif // __GAME_SCENE_H__
