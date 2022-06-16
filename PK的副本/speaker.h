//
// Created by 郑旭 on 2022/5/23.
//

#ifndef PK_SPEAKER_H
#define PK_SPEAKER_H

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

class speaker {
public:
    speaker()
    {

    }
    speaker(string name,vector<double> score)
    {
        m_Name=name;
        m_Score=score;
    }
    string show_name()
    {
        return m_Name;
    }
    double show_score(int index)
    {
        switch(index)
        {
            case 0://显示第一轮
                return *m_Score.begin();
                break;
            case 1://显示第二轮
                return *(m_Score.begin()+1);
                break;
        }
        //replace(m_Score.begin(),m_Score.begin(),0,9);
        //return *m_Score.begin();
        //return m_Score[0];
    }

    void getPoint(int i,double avg)
    {
        m_Score[i]=avg;
    }

private:
    string m_Name;//姓名
    vector<double> m_Score;//分数 最多有两轮得分，所以创建一个数组
};

#endif //PK_SPEAKER_H
