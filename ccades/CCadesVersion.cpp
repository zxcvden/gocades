#include "stdafx.h"
#include <stdlib.h>
#include "CCadesVersion.h"
#include "CPPVersion.h"

using namespace CryptoPro::PKI::CAdES;

CCadesVersion *CCadesVersion_create()
{
    CCadesVersion *m;
    CPPVersionObject *obj;
    char *err;

    m = (typeof(m))malloc(sizeof(*m));
    obj = new CPPVersionObject();
    err = (typeof(err))calloc(ERR_MAX_SIZE, sizeof(char));
    m->obj = obj;
    m->err = err;

    return m;
}

void CCadesVersion_destroy(CCadesVersion *m)
{
    if (m == NULL)
        return;
    delete static_cast<CPPVersionObject *>(m->obj);
    free(m->err);
    free(m);
}

char* CCadesVersion_to_string(CCadesVersion *m)
{
    CPPVersionObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPVersionObject *>(m->obj);
    CAtlString sValue;
    HRESULT hr = obj->toString(sValue);
    char *buf = (char*)calloc(sValue.GetLength(), sizeof(char));
    memcpy(buf, sValue.GetBuffer(), sValue.GetLength());
    ErrMsgFromHResult(hr, m->err);
    return buf;
}

int CCadesVersion_get_major_version(CCadesVersion *m)
{
    CPPVersionObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPVersionObject *>(m->obj);
    DWORD r;
    HRESULT hr = obj->get_MajorVersion(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}

int CCadesVersion_get_minor_version(CCadesVersion *m)
{
    CPPVersionObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPVersionObject *>(m->obj);
    DWORD r;
    HRESULT hr = obj->get_MinorVersion(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}

int CCadesVersion_get_build_version(CCadesVersion *m)
{
    CPPVersionObject *obj;

    if (m == NULL){
        ErrMsgFromHResult(E_UNEXPECTED, m->err);
        return 0;
    }

    obj = static_cast<CPPVersionObject *>(m->obj);
    DWORD r;
    HRESULT hr = obj->get_BuildVersion(&r);
    ErrMsgFromHResult(hr, m->err);
    return r;
}
