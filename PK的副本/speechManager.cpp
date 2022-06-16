//
// Created by 郑旭 on 2022/5/23.
//

#include "speechManager.h"
#include "speaker.h"

//构造函数
speechManager::speechManager() {
    //初始化容器和属性
    this->iniSpeech();

    //创建12名选手
    this->creatSpeaker();

    //加载往届记录
    this->loadRecord();
}

//菜单功能
void speechManager::show_Menu() {
    cout << "*****************************" << endl;
    cout << "********欢迎参加演讲比赛********" << endl;
    cout << "******** 1.开始演讲比赛 *******" << endl;
    cout << "******** 2.查看往届记录 *******" << endl;
    cout << "******** 3.清空比赛记录 *******" << endl;
    cout << "******** 0.退出比赛程序 *******" << endl;
    cout << "*****************************" << endl;
    cout << endl;
/*    cin.ignore();
    getchar();
    system("clear");*/
}

void speechManager::exist_Menu() {
    cout << "程序退出，欢迎下次使用" << endl;
    cin.ignore();
    getchar();
    exit(0);
}

void speechManager::iniSpeech() {
    //先将容器置空 clear
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();
    //初始化比赛轮数
    this->m_index = 1;
    this->m_Record.clear();
}

//创建12名选手
void speechManager::creatSpeaker() {
    string nameSeed = "ABCDEFGHIJKh";
    for (int i = 0; i < nameSeed.size(); i++)//字符串长度.size()
    {
        string name = "选手";
        name += nameSeed[i];
        //创建具体选手
        vector<double> a(2, 0);
        speaker sp(name, a);

        //创建选手编号 并且放到v1容器中
        this->v1.push_back(i + 10001);

        //选手编号以及对应选手 放入map容器中
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}

//重置
void speechManager::reInit() {
    //初始化容器和属性
    this->iniSpeech();

    //创建12名选手
    this->creatSpeaker();

    //加载往届记录
    this->loadRecord();
}


//开始比赛
void speechManager::startSpeech() {
    //第一轮开始比赛

/*    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechContest();
    //3、显示晋级结果
    this->showScore();
    //第二轮比赛
    this->m_index++;
    //1、抽签
    speechDraw();
    //2、比赛
    speechContest();
    //3、显示最终结果
    showScore();*/
    for (; this->m_index <= 2; this->m_index++) {
        this->speechDraw();
        this->speechContest();
        this->showScore();
    }
    //4、保存分数到文件中
    this->saveRecord();
    //5、没届比赛完成后，重置属性
    this->reInit();

    cout << "本届比赛完毕！" << endl;
    cin.ignore();
    getchar();
    system("clear");
}

//抽签
void speechManager::speechDraw() {
    cout << "第" << this->m_index << "轮比赛选手正在抽签" << endl;
    cout << "-----------------------------" << endl;
    cout << "抽签后演讲顺序" << endl;
    switch (m_index) {
        case 1:
            random_shuffle(v1.begin(), v1.end());
            for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
            break;
        case 2:
            random_shuffle(v2.begin(), v2.end());
            for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
            break;
    }
    cout << "-----------------------------" << endl;
    cin.ignore();
    getchar();
}

//比赛
void speechManager::speechContest() {
    cout << "--------第" << this->m_index << "轮比赛正式开始--------" << endl;

    //准备临时容器 存放小组 按照分数从大到小
    multimap<double, int, greater<double>> groupScore;

    int num = 0;//记录人员个数 6人一组

    vector<int> v_Src;//比赛选手容器
    if (this->m_index == 1) {
        v_Src = v1;
    } else {
        v_Src = v2;
    }
    //遍历所有选手进行比赛
    for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
        num++;//记录人数
        deque<double> d;
        for (int i = 0; i < 10; i++) {
            double score = (rand() % 401 + 600) / 10.f;//600~1000
            //cout<<score<<" ";//测试
            d.push_back(score);
        }
        //cout<<endl;
        sort(d.begin(), d.end(), greater<double>());//排序 降序
        d.pop_front();//去除最高分
        d.pop_back();//去除最低分
        //总分
        double sum = accumulate(d.begin(), d.end(), 0.0f);
        //平均分
        double avg = sum / (double) d.size();

        //将平均分放入到map容器里
        this->m_Speaker[*it].getPoint(this->m_index - 1, avg);
//        //打印
//        cout<<"编号："<<*it<<"姓名："<<this->m_Speaker[*it].show_name()
//            <<"获取平均分："<<this->m_Speaker[*it].show_score(i)<<endl;
        //将打分数据 放到临时小组容器中
        groupScore.insert(make_pair(avg, *it));//key是得分 value是具体选手编号
        //每六人去除前三名
        if (num % 6 == 0) {
            if (this->m_index == 1) {
                cout << "第" << num / 6 << "小组比赛名次" << endl;
            } else {
                cout << "最终决赛名次：" << endl;
            }
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
                 it != groupScore.end(); it++) {
                cout << "编号：" << it->second << " " << "姓名：" << this->m_Speaker[it->second].show_name() << " "
                     << "分数：" << this->m_Speaker[it->second].show_score(this->m_index - 1) << endl;
            }
            //取走前三名
            int count = 0;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
                 it != groupScore.end() && count < 3; it++, count++) {
                if (this->m_index == 1)//判断轮数
                {
                    v2.push_back(it->second);
                } else {
                    vVictory.push_back(it->second);
                }
            }

            groupScore.clear();//循环一次就将容器清空
            cout << endl;
        }
    }
/*    cout<<"_______"<<endl;
    for(vector<int>::iterator it=v2.begin();it!=v2.end();it++)
    {
        cout<<"选手："<<*it;
    }
    cout<<endl;*/

    cout << "--------第" << this->m_index << "轮比赛完毕--------" << endl;
    cin.ignore();
    getchar();
}

//显示分数
void speechManager::showScore() {
    if (this->m_index == 1) { cout << "--------第" << this->m_index << "轮晋级选手信息如下：--------" << endl; }
    else { cout << "最终比赛前三名为：" << endl; }
    vector<int> v;//临时容器，根据轮数存储
    if (this->m_index == 1) {
        v = v2;
    } else {
        v = vVictory;
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "选手编号：" << *it << "姓名：" << this->m_Speaker[*it].show_name() << "得分："
             << this->m_Speaker[*it].show_score(this->m_index - 1) << endl;
    }
    cout << endl;

    cin.ignore();
    getchar();
    system("clear");
    this->show_Menu();
}

//保存记录
void speechManager::saveRecord() {
    ofstream ofs;
    //用追加的方式写文件
    ofs.open("speech.csv", ios::out | ios::app);

    //将每个选手数据 写入到文件中
    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++) {
        ofs << *it << "," << this->m_Speaker[*it].show_score(1) << ",";
    }
    ofs << endl;
    ofs.close();//关文件
    cout << "比赛记录已经保存" << endl;
    //有记录了，文件不为空
    this->fileIsEmpty = false;
}

//读取记录
void speechManager::loadRecord() {
    ifstream ifs("speech.csv", ios::in);//读文件
    if (!ifs.is_open())//判断能否打开文件
    {
        this->fileIsEmpty = true;
        //cout<<"文件不存在"<<endl;
        ifs.close();
        return;
    }
    //文件清空情况
    char ch;
    ifs >> ch;
    if (ifs.eof())//eof:end of file是否读到文件尾
    {
        //cout << "文件为空" << endl;
        this->fileIsEmpty=true;
        ifs.close();
        return;
    }
    //文件不为空
    this->fileIsEmpty = false;
    ifs.putback(ch);//将上面读取的单个字符 放回来

    string data;
    int index = 0;//第几届的下标


    while (ifs >> data)//ifs一行行读
    {
        //cout<<data<<endl;
        vector<string> v;//存放6个string字符串
        //解析数据 查"，"位置的变量
        int pos = -1;
        int start = 0;
        while (true) {
            pos = data.find(",", start);
            if (pos == -1) {//没有找到
                break;
            }
            string temp = data.substr(start, pos - start);
            //cout<<temp<<endl;
            v.push_back(temp);
            start = pos + 1;
        }

        //注意 map容器中key值不能相同
        this->m_Record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();
    for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++) {
        cout << "第" << it->first + 1 << "届冠军编号：" << it->second[0] <<
             "具体分数：" << it->second[1] << endl;
    }
}

//显示往届记录
void speechManager::showRecord() {
    if (this->fileIsEmpty) {
        cout << "文件为空或者文件不存在" << endl;
    }
    for (int i = 0; i < this->m_Record.size(); i++) {
        cout << "第" << i + 1 << "届"
             << "冠军编号：" << this->m_Record[i][0] << "得分：" << this->m_Record[i][1] << " "
             << "亚军编号：" << this->m_Record[i][2] << "得分：" << this->m_Record[i][3] << " "
             << "季军编号：" << this->m_Record[i][4] << "得分：" << this->m_Record[i][5] << endl;
    }
    cin.ignore();
    getchar();
    system("clear");

}

//清楚记录
void speechManager::clearRecord()
{
    cout<<"确认清空？"<<endl;
    cout<<"1、确认"<<endl;
    cout<<"2、返回"<<endl;

    int select=0;
    cin>>select;

    if(select==1)
    {
     //打开模式，trunc。如果该文件存在，则将文件删除重新创建，相当于清空
     ofstream ofs;
     ofs.open("speech.csv",ios::trunc);
     ofs.close();
        //初始化容器和属性
        this->iniSpeech();

        //创建12名选手
        this->creatSpeaker();

        //加载往届记录
        this->loadRecord();
        //this->fileIsEmpty= true;

        cout<<"清空成功"<<endl;
    }
    cin.ignore();
    getchar();
    system("clear");
}


//析构函数
speechManager::~speechManager() {

}