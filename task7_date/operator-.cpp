int dayOfYear(int year) {

    if (year % 4 == 0 && year%100 != 0 || year%400 == 0) {
        return 366;
    }
    else {
        return 365;
    }
}

int maxDays(int mon, int year)
{
    int mas[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if (mon != 2 && mon <= 12) {
        return mas[mon];
    }
    else {
        return 28 + dayOfYear(year) % 365;
    }

}

int dif(int d1, int m1, int y1, int d2, int m2, int y2) {

    int y3 = y2 + 1, res = m1 + maxDays(m2, y2) - m2, mbuf = m2 + 1;
    while (mbuf <= 12) {
        res += maxDays(mbuf, y2);
        mbuf++;
    }
    mbuf = m1 - 1;
    while (mbuf > 0) {
        res += maxDays(mbuf, y1);
        mbuf--;
    }
    while (y3 < y1) {
        res += dayOfYear(y3);
        y3++;
    }
    if (y1 == y2) {return res - dayOfYear(y1);}
    return res;
}
