﻿#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

#include "InventoryScene.h"
#include "NonGameplayScenesCache.h"
#include "PlaceHolder.h"
#include "ui/CocosGUI.h"
// #include "resources.h.dir/inventory.h"
#include <string>
using namespace ui;

// 静态数据成员必须在类定义 *外* 进行初始化
// 为保证编译时静态数据成员最后只存在于一个目标文件中
// 这个定义也不能写入 .h 文件中，放在对应的 .cpp 文件的开头是最好选择
const std::string InventoryScene::TAG{ "InventoryScene" };

InventoryScene::InventoryScene()
{
    _visibleSize = _director->getVisibleSize();
}

bool
InventoryScene::init()
{
    /*  1. super init first */

    if (!Scene::init()) {
        return false;
    }

/*  2. debug info */

#ifndef NDEBUG
    auto sceneTag = Label::createWithTTF("InventoryScene", "fonts/arial.ttf", 16);
    sceneTag->setAnchorPoint(Vec2(0, 1));
    sceneTag->setPosition(Vec2(0, _visibleSize.height));
    sceneTag->setColor(Color3B::WHITE);
    this->addChild(sceneTag);
#endif

    /*  3. PlaceHolder */

    /*auto p = PlaceHolder::createCircle(100, "InventoryScene");
    p->setPosition(_visibleSize / 2);
    this->addChild(p);*/

    /*  4. schedule */

    this->scheduleUpdate();

    /*backButton*/
    auto backButton = Button::create("InventoryScene/p1.png", "", "");
    backButton->setPosition(Vec2(_visibleSize.width * 0.2, _visibleSize.height * 0.2));
    backButton->setTitleText("返回");
    backButton->setContentSize(Size(_visibleSize.width * 0.2, _visibleSize.height * 0.2));
    backButton->addTouchEventListener(
        [](Ref* pSender, Widget::TouchEventType type) { Director::getInstance()->popScene(); });
    this->addChild(backButton);

    /*background*/
    auto bg = Sprite::create("InventoryScene/bg.png");
    bg->setContentSize(Size(_visibleSize.width, _visibleSize.height));
    bg->setPosition(Vec2(_visibleSize.width * 0.5, _visibleSize.height * 0.5));
    this->addChild(bg, -1);

    /*normalProps*/
    auto normalProps = Button::create("InventoryScene/p1.png", "", "");
    normalProps->setPosition(Vec2(_visibleSize.width * 0.2, _visibleSize.height * 0.4));
    normalProps->setTitleText("普通道具");
    normalProps->setContentSize(Size(_visibleSize.width * 0.2, _visibleSize.height * 0.2));
    this->addChild(normalProps);

    /*strongProps*/
    auto strongProps = Button::create("InventoryScene/p1.png", "", "");
    strongProps->setPosition(Vec2(_visibleSize.width * 0.2, _visibleSize.height * 0.6));
    strongProps->setTitleText("强化道具");
    strongProps->setContentSize(Size(_visibleSize.width * 0.2, _visibleSize.height * 0.2));
    this->addChild(strongProps);

    /*specialProps*/
    auto specialProps = Button::create("InventoryScene/p1.png", "", "");
    specialProps->setPosition(Vec2(_visibleSize.width * 0.2, _visibleSize.height * 0.8));
    specialProps->setTitleText("特殊道具");
    specialProps->setContentSize(Size(_visibleSize.width * 0.2, _visibleSize.height * 0.2));
    this->addChild(specialProps);

    return true;
}

void
InventoryScene::update(float dt)
{
}
