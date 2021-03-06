﻿#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

#include "LogoAndDisclaimerScene.h"
#include "BackgroundIntroScene.h"
#include "GameData.h"
#include "JumpTableScene.h"
#include "NonGameplayScenesCache.h"
#include "PlaceHolder.h"
#include "resources.h.dir/logo.h"
#include <iostream>
#include <string>
using namespace std;

LogoAndDisclaimerScene::LogoAndDisclaimerScene()
{
    _visibleSize = _director->getVisibleSize();
}

bool
LogoAndDisclaimerScene::init()
{
    /*  1. super init first */

    if (!Scene::init()) {
        return false;
    }

    /*  2. 构建 logoLayer 的 UI 树 */

    auto whiteBg = Sprite::create("place_holder.png");
    whiteBg->setContentSize(_visibleSize);
    whiteBg->setPosition(_visibleSize / 2);

    auto logoLayer = Layer::create();
    logoLayer->addChild(whiteBg);

    auto logoImg = PlaceHolder::createCircle(100, "Logo", 48);
    logoImg->setPosition(_visibleSize / 2 + Size(0, 100));
    logoLayer->addChild(logoImg);

    auto studioLabel = Label::createWithTTF("Torch Studio", "fonts/arial.ttf", 64);
    studioLabel->setColor(Color3B::BLACK);
    studioLabel->setPosition(_visibleSize / 2 - Size(0, 100));
    logoLayer->addChild(studioLabel);

    /*  3. 构建 disclaimerLayer 的 UI 树 */

    whiteBg = Sprite::create("place_holder.png");
    whiteBg->setContentSize(_visibleSize);
    whiteBg->setPosition(_visibleSize / 2);

    auto disclaimerLayer = Layer::create();
    disclaimerLayer->addChild(whiteBg);

    string bodyText = "本作品是以上海爱丽丝幻乐团（ZUN）的东方project系列为原作的二"
                      "次同人创作非官方作品或商业作品。";

    auto body = Label::createWithTTF(bodyText, "fonts/dengxian.ttf", 32);
    body->setColor(Color3B::BLACK);
    body->setMaxLineWidth(1000);
    body->setLineSpacing(30);
    auto bodyPos = _visibleSize / 2;
    body->setPosition(bodyPos);
    disclaimerLayer->addChild(body);

    auto title = Label::createWithTTF("免责声明", "fonts/dengxian.ttf", 48);
    title->setColor(Color3B::BLACK);

    // titlePos = bodyPos + (0, vOffset)
    float vOffset = body->getContentSize().height / 2 + (title->getContentSize() / 2).height + 80;
    Vec2 titlePos = Vec2(bodyPos) + Vec2(0, vOffset);
    title->setPosition(titlePos);
    disclaimerLayer->addChild(title);

    /*  4. 依次显示 logoLayer 与 disclaimerLayer */

    // 刚开始的时候 logoLayer 可见，disclaimerLayer 不可见

    this->addChild(disclaimerLayer);
    this->addChild(logoLayer);
    logoLayer->setVisible(true);
    disclaimerLayer->setVisible(false);

    // 先展示 logoLayer，后展示 disclaimerLayer

    this->scheduleOnce(
        [logoLayer, disclaimerLayer](float) {
            disclaimerLayer->setVisible(true);
            logoLayer->setVisible(false);
        },
        _logoLast, "disclaimerTurn");

    // 都展示完了，切换到下一场景

    this->scheduleOnce([this](float) { this->switchToJumpTableScene(); },
                       _logoLast + _disclaimerLast, "nextScene");

    return true;
}

void
LogoAndDisclaimerScene::switchToJumpTableScene()
{
    auto s = JumpTableScene::create();
    _director->replaceScene(s);
}

void
LogoAndDisclaimerScene::switchToBackgroundIntroScene()
{
    auto s = BackgroundIntroScene::create();
    _director->replaceScene(s);
}
