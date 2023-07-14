/**
 * @file Sleep.cpp
 * 
 * @brief Sleepクラスのソースファイル
 * 
 * @author Nave-wata
 * 
 * @date 2023-07-14
 */

#include "utils/Sleep.hpp"

/**
 * @brief ミリ単位でスリープする
 * 
 * @param milliseconds 
 */
void Sleep::milliSleep(const int milliseconds){
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = milliseconds * 1000 * 1000;
    nanosleep(&ts, NULL);
}