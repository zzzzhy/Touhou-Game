﻿#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

#ifndef SAVE_DESCRIPTION_H
#define SAVE_DESCRIPTION_H

#include <string>

struct Save
{
    int tag;                 //存档标签
    std::string name;        //存档命名
    std::string time;        //存档时间
    std::string locationTag; //当前所处地点或位置的标签
};

#endif
