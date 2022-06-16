#include<iostream>

using namespace std;

#include "speechManager.h"
#include <ctime>


int main() {
    srand((unsigned int) time(NULL));

    //创建管理类对象
    speechManager sn;

/*    //测试12名选手的创建
    for(map<int,speaker>::iterator it=sn.m_Speaker.begin();
    it!=sn.m_Speaker.end();it++)
    {
        cout<<"选手编号："<<it->first<<"姓名："<<it->second.show_name()<<"分数："<<it->second.show_score0()<<endl;
    }*/

    int choice = 0;//用于存储用户输入

    while (true) {
        sn.show_Menu();
        cout << "请输入您的选择" << endl;
        cin >> choice;
        switch (choice) {
            case 1://开始比赛
                sn.startSpeech();
                break;
            case 2://查看往届比赛记录
                sn.showRecord();
                break;
            case 3://清空比赛记录
                sn.clearRecord();
                break;
            case 0://退出系统
                sn.exist_Menu();
                break;
            default:
                cout << "输入有误" << endl;
                system("clear");
                break;
        }

    }

    return 0;
}