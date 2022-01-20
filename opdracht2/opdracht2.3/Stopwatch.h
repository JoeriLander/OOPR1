#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <sys/time.h>

class Stopwatch
{
    private:
      struct timeval begintijd;
      struct timeval eindtijd;
    
    public:
        Stopwatch();
        void reset();
        void begin();
        void stop();
        unsigned int deTijd();        
};

#endif