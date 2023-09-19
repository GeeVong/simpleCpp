#if defined(__unix) || defined(__APPLE__)
#include <unistd.h>
#include <sys/time.h>
#elif defined(_WIN32)
#include <windows.h>
#endif

void PISleep(unsigned long timems)
{
#if defined(__unix) || defined(__APPLE__)
    usleep((timems << 10) - (timems << 4) - (timems << 3));
#elif defined(_WIN32)
    Sleep(timems);
#endif
}

unsigned long PITime()
{
#if defined(__unix)
    timezone tz={0, 0};
        timeval time;
        gettimeofday(&time,&tz);
        return (time.tv_sec*1000+time.tv_usec/1000);
#elif defined(_WIN32)
    return GetTickCount();
#elif defined(__APPLE__)  // todo  test
    timeval time;
    gettimeofday(&time,nullptr);
    return (time.tv_sec*1000+time.tv_usec/1000);
#endif
}

unsigned int GetDayID()
{
    struct
    {
        unsigned short year;
        unsigned char  mon;
        unsigned char  day;
    } now;

    time_t now_time = time(0);
    struct tm *p_tm = localtime(&now_time);
    now.year = (unsigned short)p_tm->tm_year;
    now.mon = (unsigned char)p_tm->tm_mon;
    now.day = (unsigned char)p_tm->tm_mday;
    return *(unsigned int*)&now;
}
