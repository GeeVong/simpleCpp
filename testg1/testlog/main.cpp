//
// Created by hq on 2023/9/18.
//

#ifndef ENGINE_TEST_H
#define ENGINE_TEST_H

#include <iostream>
#include "gameserver/game.h"
#include "log/logmain.h"

#include "ilogmodule.h"
#include "imodule.h"
#include "logagent.h"
using namespace std;

int main(){
    cout<<"hello log module !!"<<endl;

    Game game;
    LogDLL::Register(&game);

    LogAgent		m_log;

    ILogModule *log = dynamic_cast<ILogModule *>(game.QueryModule(LOG_MODULE));

    m_log.SetLogModule(log);


    m_log.printf(LL_INFO, "Login Server On INIT, RoleInitAttr::Init Success.");

    return -100;
}


#endif //ENGINE_TEST_H
