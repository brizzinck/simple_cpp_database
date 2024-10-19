#ifndef ILOADER_H
#define ILOADER_H

class ILoader {
public:
    virtual void SelfLoader(const nlohmann::basic_json<> &data) = 0;
    virtual void DisplayInfo() const = 0;
};


#endif //ILOADER_H
