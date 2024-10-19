#ifndef ISAVER_H
#define ISAVER_H

class ISaver {
public:
    virtual nlohmann::json GetSaveData() const = 0;
};
#endif //ISAVER_H
