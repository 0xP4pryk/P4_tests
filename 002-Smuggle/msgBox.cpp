#include <Windows.h>
#include <iostream>
#include <ctime>
#include <Lmcons.h>
#include <tchar.h>

int main() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    TCHAR username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    GetUserName(username, &username_len);

    char buffer[100];
    sprintf(buffer, "Date'n'time: %04d-%02d-%02d %02d:%02d:%02d\nExecuted by: %s",
            ltm->tm_year + 1900, ltm->tm_mon + 1, ltm->tm_mday,
            ltm->tm_hour, ltm->tm_min, ltm->tm_sec, username);

    MessageBox(NULL, buffer, "Testing Box", MB_OK);

    return 0;
}