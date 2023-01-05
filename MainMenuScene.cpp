

#include "MainMenuScene.h"
#include "GameScene.h"


USING_NS_CC;

Scene* MainMenu::createScene()
{
    auto scene = Scene::create();
    auto layer = MainMenu::create();
    scene->addChild(layer);
    return scene;
}


// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto menuTitle = MenuItemImage::create("Title.png", "Title.png");

    auto playItem  = MenuItemImage::create("playbtn.png","playbtn(Click).png",
                  CC_CALLBACK_1(MainMenu::GoToGameScene, this));
    auto menu = Menu::create(menuTitle, playItem, NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);

    auto backgroundSprite = Sprite::create("backgroung.jpg");
    backgroundSprite->setPosition(Point((visibleSize.width / 2) +
             origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(backgroundSprite, -1);

    return true;
}

void MainMenu::GoToGameScene(cocos2d::Ref *pSender)
{
    auto scene = GameScene::createScene();

    Director::getInstance()->replaceScene(scene);
}


