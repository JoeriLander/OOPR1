#ifndef AANSL_PLATFORM_H
#define AANSL_PLATFORM_H

class AansluitingsPlatform {
  public:
    virtual void zetSpanningOp(bool) = 0;
    virtual int pinNumber() = 0;
};

#endif