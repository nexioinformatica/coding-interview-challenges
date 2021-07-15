#include <iostream>
#include <cmath>

int to_degree(int scale, int n)
{
    return ((360 / scale) * n) % 360;
}

int hour_to_degree(int hour)
{
    return to_degree(12, hour);
}

int minute_to_degree(int minute)
{
    return to_degree(60, minute);
}

int angle_between_clock_hands(int hour, int minute)
{
    int deg_hour = hour_to_degree(hour);
    int deg_minute = minute_to_degree(minute);

    return deg_hour > deg_minute ? deg_hour - deg_minute : deg_minute - deg_hour; // deg_minute - deg_hour;
}

int main()
{
    std::cout << "angle between 00h and 00m = " << angle_between_clock_hands(0, 0) << std::endl;
    std::cout << "angle between 12h and 60m = " << angle_between_clock_hands(12, 60) << std::endl;
    std::cout << "angle between 00h and 15m = " << angle_between_clock_hands(0, 15) << std::endl;
    std::cout << "angle between 12h and 15m = " << angle_between_clock_hands(12, 15) << std::endl;
    std::cout << "angle between 00h and 30m = " << angle_between_clock_hands(0, 30) << std::endl;
    std::cout << "angle between 03h and 30m = " << angle_between_clock_hands(3, 30) << std::endl;
    std::cout << "angle between 02h and 05m = " << angle_between_clock_hands(2, 5) << std::endl;
    std::cout << "angle between 06h and 45m = " << angle_between_clock_hands(6, 45) << std::endl;
    std::cout << "angle between 17h and 00m = " << angle_between_clock_hands(17, 00) << std::endl;

    return 0;
}