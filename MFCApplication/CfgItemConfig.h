#include <vector>
#include <map>

#pragma once
class CCfgItemConfig
{
public:
    CCfgItemConfig();
    ~CCfgItemConfig();

    BOOL Load();
    void UnLoad();
    BOOL CreatPolicyIDMap();

    typedef struct _QQPCMGRSUPPORT
    {
        UINT build_min;
        UINT build_max;
    }QQPCMGRSUPPORT, *PQQPCMGRSUPPORT;

    typedef struct _DOWNLOAD
    {
        UINT appid;
        ATL::CAtlString path;
    }DOWNLOAD, *PDOWNLOAD;

    typedef struct _CLOUD
    {
        UINT policy_id;
        UINT switch_id;
        UINT url_id;
        UINT md5_id;
    }CLOUD, *PCLOUD;

    typedef struct _CFGITEM
    {
        UINT id;
        ATL::CAtlString name;
        ATL::CAtlString guid;
        QQPCMGRSUPPORT QQPcMgrSupport;
        DOWNLOAD Download;
        CLOUD Cloud;
    }CFGITEM, *PCFGITEM;

    //��ȡ���ð汾��Ϣ
    int GetVersion();
    //��ȡid��Ӧ��CfgItem
    BOOL GetCfgItem(UINT uIndex, CFGITEM& vecCfgItem);
    //��ȡpolicy_id��Ӧ��id
    BOOL GetIDGroup(UINT uIndex, std::vector<UINT>& idGroup);

protected:
    DWORD m_dwVersion;
    std::vector<CFGITEM> m_vecCfgItem;
    std::map<UINT, std::vector<UINT>> m_mapPolicyID;
};

