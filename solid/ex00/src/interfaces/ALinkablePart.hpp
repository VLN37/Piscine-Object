#pragma once

class ALinkablePart {
 public:
    virtual ~ALinkablePart() {};
    virtual void execute(float p_pression) = 0;
};
