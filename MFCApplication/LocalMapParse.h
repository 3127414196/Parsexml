#include <map>
#include <vector>

using namespace std;

//#define __Debug_My_App

#ifdef __Debug_My_App
#define MY_ABORT abort();
#else
#define MY_ABORT
#endif

#pragma once

/**
* ��ų���id�����������Ϣ
*/
class CMapInfo
{
public:
    CMapInfo()
        : name(_T(""))
        , guid(_T(""))
        , path(_T(""))
        , build_min(0)
        , build_max(0)
        , appid(0)
        , policy_id(0)
        , switch_id(0)
        , url_id(0)
        , md5_id(0)
    {

    }

    CMapInfo(CString name, CString guid, CString path, int build_min, int build_max, int appid, int policy_id, int switch_id, int url_id, int md5_id)
        : name(name)
        , guid(guid)
        , path(path)
        , build_min(build_min)
        , build_max(build_max)
        , appid(appid)
        , policy_id(policy_id)
        , switch_id(switch_id)
        , url_id(url_id)
        , md5_id(md5_id)
    {

    }

    CString _Getname()
    {
        return name;
    }
    CString _Getguid()
    {
        return guid;
    }
    CString _Getpath()
    {
        return path;
    }
    int _Getbuild_min()
    {
        return build_min;
    }
    int _Getbuild_max()
    {
        return build_max;
    }
    int _Getappid()
    {
        return appid;
    }
    int _Getpolicy_id()
    {
        return policy_id;
    }
    int _Getswitch_id()
    {
        return switch_id;
    }
    int _Geturl_id()
    {
        return url_id;
    }
    int _Getmd5_id()
    {
        return md5_id;
    }

    // �˺���Ϊ�˵���
    CString to_CString()
    {
        CString str;
        str.Format(_T("%u %u %u %u %u %u %u"), _Getbuild_min(), _Getbuild_max(), _Getappid(), _Getpolicy_id(), _Getswitch_id(), _Geturl_id(), _Getmd5_id());
        str = _Getname() + _T("  ") + _Getguid() + _T("  ") + _Getpath() + _T(" ") + str + _T("\n");

        return str;
    }

private:
    CString name;
    CString guid;
    CString path;
    unsigned int build_min;
    unsigned int build_max;
    unsigned int appid;
    unsigned int policy_id;
    unsigned int switch_id;
    unsigned int url_id;
    unsigned int md5_id;
};


/**
* ʹ��map�������д洢��Ӧ��id��MapInfo
*/
class CLocalMapParse
{
public:
    CLocalMapParse();
    ~CLocalMapParse();

    enum XML_Err
    {
        XML_PARSE_ERR = -4,
        XML_FILE_NOT_EXIST = -3,
        XML_ID_NOT_EXIST = -2,
        XML_MEMORY_ALLOC_FAIL = -1,
        XML_NONE = 0,
        XML_SUCCESS = 1,
    };
    

    //brief ��file�ж�ȡ���� �����LocalMap,FileName=·��+�ļ���
    CLocalMapParse(CString FileName);

    //brief ��ȡ�������õİ汾��
    BOOL GetConfigVersion(int& congfigversion);

    // �����Ǹ���id����ȡ��Ӧ�Ĺؼ��ֶ�Ӧ��ֵ
    // ���id��Ӧ�������,����TRUE;��֮FALSE
    BOOL Getname(int id, CString& name);
    BOOL Getguid(int id, CString& guid);
    BOOL Getpath(int id, CString& path);
    BOOL Getbuild_min(int id, int& build_min);
    BOOL Getbuild_max(int id, int& build_max);
    BOOL Getappid(int id, int& appid);
    BOOL Getpolicy_id(int id, int& policy_id);
    BOOL Getswitch_id(int id, int& switch_id);
    BOOL Geturl_id(int id, int& url_id);
    BOOL Getmd5_id(int id, int& md5_id);

    //����id��ȡ������
    const CMapInfo* GetMapInfo(int id);

    //��ȡpolicy_id��Ӧ��id����
    BOOL GetPolicyIDMapInfo(int policy_id, vector<int> &id);

    //��ȡ����״̬
    int GetXMLErr();

    //Ϊ�˵������õĺ���
    CString to_CString()
    {
        CString str = _T("");

        map<int, CMapInfo*>::iterator Mapiter;

        for (Mapiter = LocalMap.begin(); Mapiter != LocalMap.end(); Mapiter++)
        {
            str = str + Mapiter->second->to_CString();
        }

        return str;
    }

private:
    // keyΪid, value������CMpInfo�Ľṹ
    map<int, CMapInfo*> LocalMap;

    //keyΪpolicy_id, value��id�ļ���
    map<int, vector<int>> PolicyIDMap;

    /**
    * @brief ����PolicyIDMap
    */
    void CreatPolicyIDMap();
    
    // �汾��
    int ConfigVersion;

    //����״̬
    int m_bInited;
};

