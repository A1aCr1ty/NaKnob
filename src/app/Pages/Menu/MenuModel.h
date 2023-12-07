#ifndef __MENU_MODEL_H
#define __MENU_MODEL_H
#include "App/Accounts/Account_master.h"

namespace Page
{

    class MenuModel
    {
    public:
        void Init();
        void Deinit();

        void GetIMUInfo(char *info, uint32_t len);
        void GetBatteryInfo(char *usage, float voltage,
                            char state, uint32_t len);
        void GetStorageInfo(bool *detect, char *size, uint32_t len);

        void GetJointsInfo(
            char *data, uint32_t len);

        void GetPose6DInfo(
            char *data, uint32_t len);

    private:
        Account *account;
    };

}

#endif