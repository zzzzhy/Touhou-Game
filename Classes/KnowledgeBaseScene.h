#ifndef KNOWLEDGE_BASE_SCENE_H
#define KNOWLEDGE_BASE_SCENE_H

#include "AppMacros.h"
#include "cocos2d.h"
#include <string>

USING_NS_CC;

class KnowledgeBaseScene : public Scene
{
public:
    APP_SCENE_CREATE_FUNC(KnowledgeBaseScene, TAG);

    virtual bool init();
    virtual void update(float dt);

private:
    KnowledgeBaseScene();

private:
    static const std::string TAG;

    // intorspection
    Size _visibleSize;
};

#endif // KNOWLEDGE_BASE_SCENE_H
