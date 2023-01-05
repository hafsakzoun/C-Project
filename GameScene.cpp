

#include "GameScene.h"
#include "PauseScene.h"
#include "GameOverScene.h"


USING_NS_CC;

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}


// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto pauseItem = MenuItemImage::create("pausebtn.png","pausebtn(Click).png", CC_CALLBACK_1(GameScene::GoToPauseScene, this));
    
    pauseItem->setPosition(Point(pauseItem->getContentSize().width - (pauseItem->getContentSize().width / 4) + origin.x,visibleSize.height - pauseItem->getContentSize().height +(pauseItem->getContentSize().width / 4) + origin.y));
   
    auto menu = Menu::create(pauseItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    backgrounsprite = Sprite::create("backgroundSprite1.jpg");

    backgrounsprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));

    this->addChild(backgrounsprite);


    mySprite = Sprite::create("player1.png");

    mySprite->setPosition(Point((visibleSize.width /12) + origin.x, (visibleSize.height / 6) + origin.y));

    this->addChild(mySprite);

    // mouvement
 
    void leftKey() {
        auto action = MoveBy::create(SPEED, Point(-20, 0));
        this->mySprite->runaction(action);
    }
   /* void rightkey()
    {
        auto  action = MoveBy::create(SPEED, Point(20, 0));
        this->mySprite->runaction(action);
    }
    void upleftKey() {
        auto action = JumpBy::create(SPEED, Point(-50, 60), 100, 1);
        this->mySprite->runaction(action);
    }
    void uprightkey()
    {
        auto  action = JumpBy::create(SPEED, Point(50, 60), 100, 1);
        this->mySprite->runaction(action);
    } */

    return true;
}

void GameScene::GoToPauseScene(cocos2d::Ref* pSender)
{
    auto scene = PauseMenu::createScene();

    Director::getInstance()->pushScene(scene);
}
void GameScene::GoToGameOverScene(cocos2d::Ref* pSender)
{
    auto scene = GameOver::createScene();

    Director::getInstance()->replaceScene(scene);
}
void GameScene::keyPressed(cocos2d::EventKeyboard::KeyCode, cocos2d::Event* event)
{
    if (KeyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) { this->mySprite->leftKey(); this->upPressed = true; }
    if (KeyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) { this->mySprite->rightKey(); this->rightPressed = true; }
}


