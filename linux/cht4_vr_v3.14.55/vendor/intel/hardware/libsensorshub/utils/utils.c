#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#include "../include/utils.h"

#define MAX_LOG_SIZE 256

static char log_file[MAX_LOG_SIZE];

static message_level current_level = INFO;

void set_log_level(message_level log_level)
{
        if (log_level >= MAX_LEVEL)
                return;

        current_level = log_level;
}

void set_log_file(const char *fname)
{
        if (strnlen(fname, MAX_LOG_SIZE) < MAX_LOG_SIZE) {
                strncpy(log_file, fname, MAX_LOG_SIZE - 1);
                log_file[MAX_LOG_SIZE - 1] = '\0';
        } else
                strcpy(log_file, "/data/sensorhubd.log");
}

#define DATA_LOG 0
void log_message(const message_level level, const char *char_ptr, ...)
{
        char buffer[MAX_LOG_SIZE];
        va_list list_ptr;

        if (level > current_level)
                return;

        va_start(list_ptr, char_ptr);
        vsnprintf(buffer, MAX_LOG_SIZE, char_ptr, list_ptr);
        va_end(list_ptr);

        if (level == DEBUG)
                ALOGD("sensorhub: %s", buffer);
        else if (level == WARNING)
                ALOGW("sensorhub: %s", buffer);
        else if (level == INFO)
                ALOGI("sensorhub: %s", buffer);
        else
                ALOGE("sensorhub: %s", buffer);

#if DATA_LOG
        FILE *logf = fopen(log_file, "a");
        if (logf) {
                fprintf(logf, "%ld: %d %s", time(NULL), level, buffer);
                fclose(logf);
        } else {
                printf("Open log file failed, errno is %d \n", errno);
        }
#endif
}

int max_common_factor(int data1, int data2)
{
        int m = data1, n = data2, r;

        while (n != 0) {
                r = (m % n);
                m = n;
                n = r;
        }

        return m;
}

int least_common_multiple(int data1, int data2)
{
        int m = data1, n = data2, r;

        while (n != 0) {
                r = (m % n);
                m = n;
                n = r;
        }

        return ((data1 * data2) / m);
}

