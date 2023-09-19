//
// Created by hq on 2023/6/29.
//

#ifndef SERVER_TBOOST_H
#define SERVER_TBOOST_H

#include <iostream>
//#include "boost/regex.hpp"
#include "boost/lambda/lambda.hpp"
//#include "boost/regex.hpp"

//int tRegex() {
//    std::string   str = "2013-08-15";
//    boost::regex  rex("(?<year>[0-9]{4}).*(?<month>[0-9]{2}).*(?<day>[0-9]{2})");
//    boost::smatch res;
//
//    std::string::const_iterator begin = str.begin();
//    std::string::const_iterator end   = str.end();
//
//    if (boost::regex_search(begin, end, res, rex))
//    {
//        std::cout << "Day:   " << res ["day"] << std::endl
//                  << "Month: " << res ["month"] << std::endl
//                  << "Year:  " << res ["year"] << std::endl;
//    }
//    return 0;
//}

int tLambda() {
    printf("Please input any number:");
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
            in(std::cin), in(), std::cout << (_1 * 3) << " " );

    return 0;
}

void tBoost(){
    tLambda();
    //tRegex();
}

#endif //SERVER_TBOOST_H
