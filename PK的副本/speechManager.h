//
// Created by 郑旭 on 2022/5/23.
//
#pragma once
#ifndef PK_SPEECHMANAGER_H
#define PK_SPEECHMANAGER_H
#include<iostream>
#include <vector>
#include <map>
#include "speaker.h"
#include <deque>
#include <functional>
#include<numeric>
#include<fstream>

using namespace std;

//演讲比赛管理类
class speechManager {
public:
    //构造函数
    speechManager();
    //菜单函数
    void show_Menu();
    //退出函数
    void exist_Menu();
    //初始化选手
    void iniSpeech();
    //创建选手
    void creatSpeaker();
    //开始比赛
    void startSpeech();
    //抽签函数
    void speechDraw();
    //比赛函数
    void speechContest();
    //显示得分
    void showScore();
    //保存记录
    void saveRecord();
    //查看记录
    void loadRecord();
    //显示往届记录
    void showRecord();
    //判断文件是否为空
    bool fileIsEmpty;
    //存放往届记录的容器
    map<int,vector<string>>m_Record;
    //每次比赛完后，重置比赛，获取记录
    void reInit();
    //清空记录
    void clearRecord();
    //析构函数
    ~speechManager();

    //成员属性
    //保存第一轮比赛选手编号容器
    vector<int>v1;
    //第一轮晋级选手编号容器
    vector<int>v2;
    //胜出前三名选手编号容器
    vector<int>vVictory;
    //比赛轮数
    int m_index;

    //存放编号以及对应具体选手容器
    map<int,speaker>m_Speaker;


};


#endif //PK_SPEECHMANAGER_H
